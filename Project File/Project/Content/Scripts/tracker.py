import time
import argparse
import numpy as np
import cv2
import mediapipe as mp
from pythonosc.udp_client import SimpleUDPClient

DEFAULT_IP = "127.0.0.1"
DEFAULT_PORT = 8000

# ------------------------------------------
# Vars
# Landmarks 

# Mediapipe detects 468 facial landmarks each with an index
# The values below are just the points we are using and are standardised
RIGHT_EYE = [33, 160, 158, 133, 153, 144]
LEFT_EYE  = [362, 385, 387, 263, 373, 380]
MOUTH = [13, 14, 78, 308, 191, 80]

# Thresholds
BLINK_THRESHOLD = 0.20
MOUTH_OPEN_THRESHOLD = 0.6
MOUTH_CLOSED_THRESHOLD = 0.5

# Debounce time
BLINK_DEBOUNCE = 0.25
MOUTH_DEBOUNCE = 0.3

# Settings
refresh_time = 0.01

# ------------------------------------------
# Helpers
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

# ------------------------------------------
# OSC - Send messages to UE

# Args
parser = argparse.ArgumentParser()
parser.add_argument("--ip", default=DEFAULT_IP)
parser.add_argument("--port", type=int, default=DEFAULT_PORT)
parser.add_argument("--camera", type=int, default=0)
args = parser.parse_args()

client = SimpleUDPClient(args.ip, args.port)
print(f"[OSC] Sending to {args.ip}:{args.port}")
client.send_message("/face/loading", 1)

# Mediapipe
mp_face = mp.solutions.face_mesh
face_mesh = mp_face.FaceMesh(
    static_image_mode=False,
    max_num_faces=1,
    refine_landmarks=True,
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5,
)

# Camera
capture = cv2.VideoCapture(args.camera)
if not capture.isOpened():
    raise RuntimeError("Cannot open camera")
client.send_message("/face/loaded", 1)

# Time since
last_blink = 0
last_mouth = 0

# tracking state
mouth_is_open = False

print("ESC to quit")

# ------------------------------------------
# Main
try:
    while True:
        captured, frame = capture.read()
        if not captured:
            continue

        height, width = frame.shape[:2]
        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        result = face_mesh.process(rgb)

        if result.multi_face_landmarks:
            landmarks = result.multi_face_landmarks[0].landmark
            points = extract_landmarks_to_xy(landmarks, width, height)

            # Ear Aspect Ratio for both eyes
            eye_aspect_ratio_r = aspect_ratio(points, RIGHT_EYE)
            eye_aspect_ratio_l = aspect_ratio(points, LEFT_EYE)
            eye_aspect_ratio = (eye_aspect_ratio_r + eye_aspect_ratio_l) / 2.0

            # Mouth Aspect Ratio for mouth
            mouth_aspect_ratio = aspect_ratio(points, MOUTH)
            
            current_time = time.time()

            # Blink - Sends messages while eyes are past blink threshold
            if eye_aspect_ratio < BLINK_THRESHOLD and (current_time - last_blink) > BLINK_DEBOUNCE:
                client.send_message("/face/blink", 1)
                last_blink = current_time
                print("BLINK")

            # Mouth open - Sends message on both mouth open and mouth close
            if not mouth_is_open and mouth_aspect_ratio > MOUTH_OPEN_THRESHOLD and (current_time - last_mouth) > MOUTH_DEBOUNCE:
                client.send_message("/face/mouth_open", mouth_aspect_ratio)
                last_mouth = current_time
                mouth_is_open = True
                print("MOUTH_OPEN")   
            elif mouth_is_open and mouth_aspect_ratio < MOUTH_CLOSED_THRESHOLD and (current_time - last_mouth) > MOUTH_DEBOUNCE:
                client.send_message("/face/mouth_closed", mouth_aspect_ratio)
                last_mouth = current_time
                mouth_is_open = False
                print("MOUTH_CLOSED")

        time.sleep(refresh_time)


except KeyboardInterrupt:
    pass
finally:
    capture.release()
    cv2.destroyAllWindows()
