#include <Servo.h>

Servo servo1, servo2, servo3, servo4, servo5;
int angles[5] = {90, 90, 90, 90, 90};  // default start positions

void setup() {
  Serial.begin(9600);

  // Attach each servo to its pin
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);

  // Move all servos to default position
  for (int i = 0; i < 5; i++) {
    setServo(i, angles[i]);
  }

  Serial.println("Ready to receive servo angles...");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');  // Read until newline
    data.trim();

    int values[5];
    int index = 0;
    char *token = strtok((char *)data.c_str(), ",");

    while (token != NULL && index < 5) {
      values[index] = constrain(atoi(token), 0, 180);  // Keep values safe
      token = strtok(NULL, ",");
      index++;
    }

    // If we got 5 valid numbers, update servos
    if (index == 5) {
      for (int i = 0; i < 5; i++) {
        angles[i] = values[i];
        setServo(i, angles[i]);
      }
    }
  }
}

// Helper function to write servo angles
void setServo(int servoIndex, int angle) {
  switch (servoIndex) {
    case 0: servo1.write(angle); break;
    case 1: servo2.write(angle); break;
    case 2: servo3.write(angle); break;
    case 3: servo4.write(angle); break;
    case 4: servo5.write(angle); break;
  }
}
