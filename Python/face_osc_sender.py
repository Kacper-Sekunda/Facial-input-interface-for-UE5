"""
face_osc_sender.py
- Tracks face via MediaPipe FaceMesh
- Detects blink (EAR) + mouth open (MAR)
- Sends OSC messages to Unreal Engine 5
"""

import time
import argparse
import numpy as np
import cv2
import mediapipe as mp
from pythonosc.udp_client import SimpleUDPClient

# ---------- CONFIG ----------
DEFAULT_IP = "127.0.0.1"  # Unreal Engine machine IP
DEFAULT_PORT = 8000       # OSC server port in UE5

# Landmark indices for EAR (blink detection)
RIGHT_EYE = [33, 160, 158, 133, 153, 144]
LEFT_EYE  = [362, 385, 387, 263, 373, 380]

# Mouth indices (for MAR detection)
MOUTH = [13, 14, 78, 308, 191, 80]

# Thresholds
BLINK_THRESHOLD = 0.20
MAR_THRESHOLD   = 0.5

# Debounce timers
BLINK_DEBOUNCE = 0.25
MOUTH_DEBOUNCE = 0.3

# ---------- Helpers ----------
def euclid(a, b):
    return np.linalg.norm(np.array(a) - np.array(b))

def extract_landmarks_to_xy(landmarks, w, h):
    return [(int(l.x * w), int(l.y * h)) for l in landmarks]

def aspect_ratio(pts, idxs):
    p = [pts[i] for i in idxs]
    A = euclid(p[1], p[5])
    B = euclid(p[2], p[4])
    C = euclid(p[0], p[3])
    if C == 0:
        return 0
    return (A + B) / (2.0 * C)

# ---------- Args ----------
parser = argparse.ArgumentParser()
parser.add_argument("--ip", default=DEFAULT_IP)
parser.add_argument("--port", type=int, default=DEFAULT_PORT)
parser.add_argument("--camera", type=int, default=0)
args = parser.parse_args()

client = SimpleUDPClient(args.ip, args.port)
print(f"[OSC] Sending to {args.ip}:{args.port}")

# ---------- MediaPipe Init ----------
mp_face = mp.solutions.face_mesh
face_mesh = mp_face.FaceMesh(
    static_image_mode=False,
    max_num_faces=1,
    refine_landmarks=True,
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5,
)

cap = cv2.VideoCapture(args.camera)
if not cap.isOpened():
    raise RuntimeError("Cannot open camera")

last_blink = 0
last_mouth = 0

print("[INFO] Press ESC to quit")

# ---------- Main Loop ----------
try:
    while True:
        ret, frame = cap.read()
        if not ret:
            continue

        h, w = frame.shape[:2]
        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        res = face_mesh.process(rgb)

        if res.multi_face_landmarks:
            lm = res.multi_face_landmarks[0].landmark
            pts = extract_landmarks_to_xy(lm, w, h)

            # EAR for both eyes
            ear_r = aspect_ratio(pts, RIGHT_EYE)
            ear_l = aspect_ratio(pts, LEFT_EYE)
            ear = (ear_r + ear_l) / 2.0

            # MAR for mouth
            mar = aspect_ratio(pts, MOUTH)

            now = time.time()

            # Blink
            if ear < BLINK_THRESHOLD and (now - last_blink) > BLINK_DEBOUNCE:
                client.send_message("/face/blink", 1)
                last_blink = now
                print("BLINK sent")

            # Mouth open
            if mar > MAR_THRESHOLD and (now - last_mouth) > MOUTH_DEBOUNCE:
                client.send_message("/face/mouth_open", mar)
                last_mouth = now
                print("MOUTH_OPEN sent")

            # Debug overlay
            cv2.putText(frame, f"EAR:{ear:.3f} MAR:{mar:.3f}",
                        (10, 30), cv2.FONT_HERSHEY_SIMPLEX,
                        0.7, (0,255,0), 2)

        cv2.imshow("Face Input (ESC to quit)", frame)
        if cv2.waitKey(1) & 0xFF == 27:
            break

except KeyboardInterrupt:
    pass
finally:
    cap.release()
    cv2.destroyAllWindows()
