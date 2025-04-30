// Pin setup
const int xAxis = A0;
const int yAxis = A1;
const int buttonPin = 3;    // Joystick push button
const int togglePin = 2;    // Button to simulate "mouse toggle" (logic only)

bool controlActive = false;
int lastToggleState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(togglePin, INPUT_PULLUP);
}

void loop() {
  // Handle control toggle (simulated "mouse on/off")
  int toggleState = digitalRead(togglePin);
  if (toggleState != lastToggleState && toggleState == LOW) {
    controlActive = !controlActive;
    Serial.print("Control Active: ");
    Serial.println(controlActive ? "YES" : "NO");
    delay(200); // debounce
  }
  lastToggleState = toggleState;

  // Read joystick
  int x = analogRead(xAxis);
  int y = analogRead(yAxis);
  bool pressed = digitalRead(buttonPin) == LOW;

  // Print values to Serial Monitor
  Serial.print("X: "); Serial.print(x);
  Serial.print("  Y: "); Serial.print(y);
  Serial.print("  Button: "); Serial.print(pressed ? "PRESSED" : "RELEASED");
  Serial.print("  | Control Active: ");
  Serial.println(controlActive ? "YES" : "NO");

  delay(100);  // Update every 100 ms
}
