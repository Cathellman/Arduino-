#include <AccelStepper.h>

#define motorInterfaceType 1

const int XdirPin = 2;
const int XstepPin = 3;

// Create instance
AccelStepper XmyStepper(motorInterfaceType, XstepPin, XdirPin);

// Define a list of target positions
long positions[] = {0, 90, 90, 0};
int numPositions = sizeof(positions) / sizeof(positions[0]);
int currentIndex = 0;

void setup() {
  XmyStepper.setMaxSpeed(1000); // Set to safe speed for your motor
  XmyStepper.setAcceleration(500); // Optional, smoother movement
}

void loop() {
  static bool moving = false;

  if (!moving) {
    XmyStepper.moveTo(positions[currentIndex]);
    moving = true;
  }

  if (moving) {
    XmyStepper.run();
    if (XmyStepper.distanceToGo() == 0) {
      moving = false;
      currentIndex++;
      if (currentIndex >= numPositions) {
        currentIndex = 0; // Loop back to start
      }
    }
  }
}
