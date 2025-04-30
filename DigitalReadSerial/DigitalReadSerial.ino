// Pin setup
const int xAxis = A0;
const int yAxis = A1;
const int buttonPin = 2;    // Joystick push button
const int togglePin = 3;    // Button to simulate "mouse toggle" (logic only)

bool controlActive = false;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(togglePin, INPUT_PULLUP);
}

void loop() {
  // Read joystick
  bool x = analogRead(xAxis);
  bool y = analogRead(yAxis);
  bool pressed = digitalRead(buttonPin) == LOW;

  // Print values to Serial Monitor
  Serial.print("X: "); Serial.print(x);
  Serial.print("  Y: "); Serial.print(y);
  Serial.print("  Button: "); Serial.print(pressed ? "PRESSED" : "RELEASED");
  Serial.print("  | Control Active: ");
  Serial.println(controlActive ? "YES" : "NO");

  delay(100);  // Update every 100 ms
}
