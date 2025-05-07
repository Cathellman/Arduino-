#include <AccelStepper.h>

#define motorInterfaceType 1

const int XdirPin = 2;
const int XstepPin = 3;
const int joystickXPin = A0;

AccelStepper XmyStepper(motorInterfaceType, XstepPin, XdirPin);

void setup() {
  XmyStepper.setMaxSpeed(500);
  XmyStepper.setAcceleration(250);  // Adjust acceleration for smooth ramp-up
  pinMode(joystickXPin, INPUT);
}

void loop() {
  int joystickX = analogRead(joystickXPin);
  int center = 512;
  int deadzone = 100; // Increased deadzone for better control

  int offset = joystickX - center;

  // Apply deadzone
  if (abs(offset) < deadzone) {
    XmyStepper.setSpeed(0);
  } else {
    // Map the joystick offset to speed with curve
    int direction = (offset > 0) ? 1 : -1;
    int distanceFromCenter = abs(offset) - deadzone;

    // Max joystick deflection is (512 - 100) = 412
    float normalized = distanceFromCenter / 412.0;

    // Apply exponential acceleration curve for smoother start
    float curvedSpeed = pow(normalized, 3) * 1000; // Exponential curve for acceleration

    // Apply this speed with respect to the joystick direction
    XmyStepper.setSpeed(curvedSpeed * direction);
  }

  XmyStepper.runSpeed();
}
