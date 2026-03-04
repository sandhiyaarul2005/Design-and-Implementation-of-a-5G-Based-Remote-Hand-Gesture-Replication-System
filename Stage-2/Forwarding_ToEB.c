//Transmitting the data from MEC server to Raspberry pi OS at Evaluation Board 
import socket 
import re 
# ESP32 → MEC 
RX_IP = "0.0.0.0" 
RX_PORT = 5005 
# MEC → Evaluation Board (Raspberry Pi) 
PI_IP = "192.168.10.20"   # <-- CHANGE to Pi IP 
PI_PORT = 6000 
# SOCKET setup 
rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
rx_sock.bind((RX_IP, RX_PORT)) 
tx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
print("[INFO] MEC listening on port", RX_PORT) 
print("[INFO] Forwarding data to Raspberry Pi at", 
f"{PI_IP}:{PI_PORT}\n") 
#Main Loop 
while True: 
    try: 
        data, addr = rx_sock.recvfrom(1024) 
        decoded = data.decode().strip() 
        print(f"[RX] ESP32 → MEC: {decoded}") 
        match = re.search(r"([\d.]+)", decoded) 
        if not match: 
            print("[WARN] Invalid data format\n") 
            continue 
        distance = match.group(1) 
        forward_msg = f"Distance_cm={distance}" 
# Forward to Raspberry Pi 
        tx_sock.sendto(forward_msg.encode(), 
                       (PI_IP, PI_PORT)) 
        print(f"[TX] MEC → Pi: {forward_msg}\n") 
    except Exception as e: 
        print("[ERROR]", e) 
