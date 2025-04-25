// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;
const int stepPin = 3;

// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
	// set the maximum speed, acceleration factor,
	// initial speed and the target position
	myStepper.setMaxSpeed(2000);
	myStepper.setAcceleration(500);
	myStepper.setSpeed(2000);
	myStepper.moveTo(200);
  Serial.begin(9600);
}

void loop() {
	// Change direction once the motor reaches target position
  
	if (myStepper.distanceToGo() == 0) 
		myStepper.moveTo(-myStepper.currentPosition());

	// Move the motor one step
	myStepper.run();
  Serial.println(myStepper.currentPosition());
}