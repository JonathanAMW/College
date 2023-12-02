import cv2
import mediapipe as mp
import socket
from collections import deque

# Create a UDP socket
udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Define the IP address and port of the receiver (Unity application)
receiver_ip = '127.0.0.1'  # Change this to the IP address of your Unity application
receiver_port = 12345  # Change this to the port number of your Unity application

mp_hands = mp.solutions.hands
hands = mp_hands.Hands(static_image_mode=False, max_num_hands=2, min_detection_confidence=0.5)

# OpenCV setup
cap = cv2.VideoCapture(0)  # Use the webcam (change 0 to another number if multiple cameras)

# Create a buffer (deque) to store hand count values
buffer_size = 2  # Adjust the buffer size as needed for smoothing
hand_count_buffer = deque(maxlen=buffer_size)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # Convert the image to RGB and process it with MediaPipe
    image_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hands.process(image_rgb)

    # Initialize hand count
    hand_count = 0

    if results.multi_hand_landmarks:
        # Increment the hand count for each detected hand
        hand_count = len(results.multi_hand_landmarks)

    # Add the hand count to the buffer
    hand_count_buffer.append(hand_count)

    # Calculate the mean of the hand count values in the buffer
    smoothed_hand_count = round(sum(hand_count_buffer) / len(hand_count_buffer))

    # Simulate recognized gesture data
    gesture_data = f"{smoothed_hand_count}"  # Sending the smoothed hand count
    print("Sending gesture data:", gesture_data)

    # Send recognized gestures to the Unity application
    udp_socket.sendto(gesture_data.encode(), (receiver_ip, receiver_port))

    # Display the frame
    cv2.imshow('Hand Tracking', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit the loop
        break

hands.close()
cap.release()
cv2.destroyAllWindows()
udp_socket.close()  # Close the UDP socket after use
