//Receiving the data from MEC server at Evaluation board OS 
import socket 
UDP_IP = "0.0.0.0" 
UDP_PORT = 6000 
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
sock.bind((UDP_IP, UDP_PORT)) 
print("[Pi] Waiting for data from MEC...") 
while True: 
    data, addr = sock.recvfrom(1024) 
    print("[RX]", data.decode()) 
