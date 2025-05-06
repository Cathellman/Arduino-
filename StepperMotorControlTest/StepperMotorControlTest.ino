// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int XdirPin = 7;
const int XstepPin = 11;

const int YdirPin = 10;
const int YstepPin = 6;

// Define motor interface type
#define motorInterfaceType 1
#define YmotorinterfaceType 2


// Creates an instance
AccelStepper XmyStepper(motorInterfaceType, XstepPin, XdirPin);
AccelStepper YmyStepper(YmotorinterfaceType, YstepPin, YdirPin);

void setup() {
	// set the maximum speed, acceleration factor,
	// initial speed and the target position
	YmyStepper.setMaxSpeed(2000);
	YmyStepper.setAcceleration(500);
	YmyStepper.setSpeed(2000);
	YmyStepper.moveTo(100);

	XmyStepper.setMaxSpeed(2000);
	XmyStepper.setAcceleration(500);
	XmyStepper.setSpeed(2000);
	XmyStepper.moveTo(100);

}

void loop() {
	// Change direction once the motor reaches target position
  
	if (YmyStepper.distanceToGo() == 0) 
		YmyStepper.moveTo(-YmyStepper.currentPosition());

	// Move the motor one step

	if (XmyStepper.distanceToGo() == 0) 
		XmyStepper.moveTo(-XmyStepper.currentPosition());

	// Move the motor one step
	XmyStepper.run();
	YmyStepper.run();

}