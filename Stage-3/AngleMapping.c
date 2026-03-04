#include <ESP32Servo.h>

Servo myServo;

const int flexPin = 36;     // Flex sensor on VP
const int servoPin = 18;    // Servo signal pin

// Change these after calibration
int flexMin = 2850;   // Straight finger value
int flexMax = 3750;   // Fully bent value

float filteredAngle = 0;   // For smoothing

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
}

void loop() {

  int flexValue = analogRead(flexPin);

  // Map flex value to 0–180°
  float angle = ((float)(flexValue - flexMin) / (flexMax - flexMin)) * 180.0;

  // Limit range
  angle = constrain(angle, 0, 180);

  // Smooth filtering (reduces jitter)
  filteredAngle = 0.8 * filteredAngle + 0.2 * angle;

  myServo.write(filteredAngle);

  Serial.print("Flex: ");
  Serial.print(flexValue);
  Serial.print("  Angle: ");
  Serial.println(filteredAngle);

  delay(20);
}
