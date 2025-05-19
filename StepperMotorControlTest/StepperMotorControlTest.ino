#include <AccelStepper.h>

#define motorInterfaceType 1

// X-axis motor
const int XdirPin = 2;
const int XstepPin = 3;
const int joystickXPin = A0;

// Y-axis motor
const int YdirPin = 4;
const int YstepPin = 5;
const int joystickYPin = A1;

// Joystick button and LED
const int joystickButtonPin = 6;  // SW pin on the joystick
const int ledPin = 7;             // LED pin

bool ledState = false;  // LED toggle state
bool lastButtonState = HIGH;  // Assume default unpressed state
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;  // Debounce delay

AccelStepper XmyStepper(motorInterfaceType, XstepPin, XdirPin);
AccelStepper YmyStepper(motorInterfaceType, YstepPin, YdirPin);

void setup() {
  XmyStepper.setMaxSpeed(500);
  XmyStepper.setAcceleration(250);
  YmyStepper.setMaxSpeed(500);
  YmyStepper.setAcceleration(250);

  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);
  pinMode(joystickButtonPin, INPUT_PULLUP);  // Joystick button uses pull-up
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Start LED off
}

void loop() {
  // Read joystick button state
  int buttonState = digitalRead(joystickButtonPin);

  // Toggle LED when button is **pressed down** (falling edge detection)
  if (buttonState == LOW && lastButtonState == HIGH) {
    if (millis() - lastDebounceTime > debounceDelay) {
      ledState = !ledState;  // Flip LED state
      digitalWrite(ledPin, ledState ? HIGH : LOW);
      lastDebounceTime = millis();
    }
  }

  lastButtonState = buttonState;  // Store current button state

  // X-axis logic
  int joystickX = analogRead(joystickXPin);
  int centerX = 512;
  int deadzoneX = 100;
  int offsetX = joystickX - centerX;

  if (abs(offsetX) < deadzoneX) {
    XmyStepper.setSpeed(0);
  } else {
    int directionX = (offsetX > 0) ? 1 : -1;
    float normalizedX = (abs(offsetX) - deadzoneX) / 412.0;
    float curvedSpeedX = pow(normalizedX, 3) * 1000;
    XmyStepper.setSpeed(curvedSpeedX * directionX);
  }

  // Y-axis logic
  int joystickY = analogRead(joystickYPin);
  int centerY = 512;
  int deadzoneY = 100;
  int offsetY = joystickY - centerY;

  if (abs(offsetY) < deadzoneY) {
    YmyStepper.setSpeed(0);
  } else {
    int directionY = (offsetY > 0) ? 1 : -1;
    float normalizedY = (abs(offsetY) - deadzoneY) / 412.0;
    float curvedSpeedY = pow(normalizedY, 3) * 1000;
    YmyStepper.setSpeed(curvedSpeedY * directionY);
  }

  XmyStepper.runSpeed();
  YmyStepper.runSpeed();
}