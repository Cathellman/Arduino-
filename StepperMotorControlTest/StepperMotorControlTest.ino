#include <AccelStepper.h>

// Define motor interface type (1 = DRIVER: step + dir)
#define motorInterfaceType 1

// Define pin connections for X and Y axes
const int XdirPin = 2;
const int XstepPin = 3;

const int YdirPin = 5;
const int YstepPin = 4;

// Create instances for X and Y motors
AccelStepper XmyStepper(motorInterfaceType, XstepPin, XdirPin);
AccelStepper YmyStepper(motorInterfaceType, YstepPin, YdirPin);

void setup() {
  // Setup X motor
  XmyStepper.setMaxSpeed(1000);
  XmyStepper.setAcceleration(500);
  XmyStepper.moveTo(1000); // Target position

  // Setup Y motor
  YmyStepper.setMaxSpeed(1000);
  YmyStepper.setAcceleration(500);
  YmyStepper.moveTo(1000); // Target position
}

void loop() {
  // If X motor reached target, reverse direction
  if (XmyStepper.distanceToGo() == 0) {
    XmyStepper.moveTo(-XmyStepper.currentPosition());
  }

  // If Y motor reached target, reverse direction
  if (YmyStepper.distanceToGo() == 0) {
    YmyStepper.moveTo(-YmyStepper.currentPosition());
  }

  // Move motors one step at a time
  XmyStepper.run();
  YmyStepper.run();
}
