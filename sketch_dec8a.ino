#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1);  // RX, TX

// Motor control pins
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

void setup() {
  // Define motor control pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Start the serial communication with the Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  // Check if data is available from Bluetooth module
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();

    // Perform actions based on received command
    switch (command) {
      case 'F':  // Forward
        moveForward();
        break;
      case 'B':  // Backward
        moveBackward();
        break;
      case 'L':  // Left
        turnLeft();
        break;
      case 'R':  // Right
        turnRight();
        break;
      case 'S':  // Stop
        stopMotor();
        break;
      default:
        break;
    }
  }
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotor() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}