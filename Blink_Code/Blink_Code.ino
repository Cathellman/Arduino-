/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// the setup function runs once when you press reset or power the board


int BlueLED = 12;
int RedLED = 11;
int YellowLED = 10;
int WhiteLED = 9;
int GreenLED = 8;

int del = 250;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(BlueLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(WhiteLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(BlueLED, HIGH);  // turn the LED on (HIGH is the voltage level)                     
  digitalWrite(RedLED, LOW);
  digitalWrite(YellowLED, LOW);
  digitalWrite(WhiteLED, HIGH);   // turn the LED off by making the voltage LOW
  digitalWrite(GreenLED, LOW);
  delay(del); // wait 

  digitalWrite(BlueLED, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(RedLED, HIGH);
  digitalWrite(YellowLED, HIGH);
  digitalWrite(WhiteLED, LOW);
  digitalWrite(GreenLED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(del);                      // wait 

  del -= 10;

  if (del == 100){
    del = 300;
  }
}
