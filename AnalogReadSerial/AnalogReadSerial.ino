/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial/
*/

// the setup routine runs once when you press reset:

int OneLED = 11;
int TwoLED = 10;
int value = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(TwoLED, OUTPUT);
  pinMode(OneLED, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  value = sensorValue * 0.3;
  analogWrite(OneLED, value);
  analogWrite(TwoLED, value);
  Serial.println(sensorValue);
  delay(1);  // delay in between reads for stability
}
