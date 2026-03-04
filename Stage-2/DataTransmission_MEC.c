//ESP Data reading and transmitting to MEC server 
#include <WiFi.h> 
#include <WiFiUdp.h> 
// Wi-Fi credentials (CPE 5G) 
const char* ssid = "[ 5GCPE ] 2.4GHz"; 
const char* password = NULL;   // Open network 
// MEC / PC details 
const char* serverIP = "192.168.10.12"; 
const int serverPort = 5005; 
// Ultrasonic sensor pins 
#define TRIG_PIN 5 
#define ECHO_PIN 18 
WiFiUDP udp; 
long getDistanceCM()  
{ 
} 
digitalWrite(TRIG_PIN, LOW); 
delayMicroseconds(2); 
digitalWrite(TRIG_PIN, HIGH); 
delayMicroseconds(10); 
digitalWrite(TRIG_PIN, LOW); 
long duration = pulseIn(ECHO_PIN, HIGH, 30000); // timeout 30 ms 
// Speed of sound = 343 m/s 
long distance = duration * 0.034 / 2; 
return distance; 
void setup()  
{ 
Serial.begin(115200); 
pinMode(TRIG_PIN, OUTPUT); 
pinMode(ECHO_PIN, INPUT); 
WiFi.begin(ssid, password); 
Serial.print("Connecting to CPE WiFi"); 
while (WiFi.status() != WL_CONNECTED)  
{ 
delay(500); 
Serial.print("."); 
} 
Serial.println("\nConnected to CPE WiFi"); 
Serial.print("ESP32 IP: "); 
Serial.println(WiFi.localIP()); 
} 
void loop() 
{ 
long distance = getDistanceCM(); 
String msg = "Distance_cm=" + String(distance); 
udp.beginPacket(serverIP, serverPort); 
udp.print(msg); 
udp.endPacket(); 
Serial.println("Sent: " + msg); 
delay(1000); 
} 
