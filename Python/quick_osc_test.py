from pythonosc.udp_client import SimpleUDPClient
import time

client = SimpleUDPClient("127.0.0.1", 8000)

for i in range(5):
    client.send_message("/face/blink", 1.0)
    print("Sent blink")
    time.sleep(1)
