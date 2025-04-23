/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int Red = 9;         // the PWM pin the LED is attached to
int Blue = 10;
int Yellow = 11;
int White = 6;
int Green = 5;

int brightness = 0;  // how bright the LED i/s
int OpBrigh = 255;

int fadeAmount = 5;  // how many points to fade the LED by
int fadeOpAm = -5;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(White, OUTPUT);
  pinMode(Green, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(Red, OpBrigh);
  analogWrite(Blue, brightness);
  analogWrite(Yellow, OpBrigh);
  analogWrite(White, brightness);
  analogWrite(Green, OpBrigh);
 

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  OpBrigh = OpBrigh + fadeOpAm;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    fadeOpAm = -fadeOpAm;
    delay(250);
  }





  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
