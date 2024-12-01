/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 28 May 2015
  by Michael C. Miller
  modified 8 Nov 2013
  by Scott Fitzgerald

  https://github.com/jkb-git/ESP32Servo/blob/master/examples/Sweep/Sweep.ino
*/

#include <Servo.h>

// #define LED_BUILTIN_RED D0
// #define LED_BUILTIN_BLUE D4
// #define SERVO_PIN D1
#define SERVO_PIN D2
// #define SERVO_PIN D8

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {

  Serial.begin(115200);  // Start serial communication at 115200 baud rate
  Serial.println("\nStarting up...");


    // Verify we're running on ESP8266
    #ifdef ESP8266
      Serial.println("Running on ESP8266");
    #else
      Serial.println("Not running on ESP8266!");
    #endif

  // Initialize the pins as outputs
  // pinMode(LED_BUILTIN_RED, OUTPUT);
  // pinMode(LED_BUILTIN_BLUE, OUTPUT);
  // Turn the LEDs off by making the voltage HIGH
  // (I know, this seems counter-intuitive, but this is how the on-board LEDs work)
  // digitalWrite(LED_BUILTIN_RED, HIGH);
  // digitalWrite(LED_BUILTIN_BLUE, HIGH);
 
  myservo.attach(SERVO_PIN);
  Serial.println("Servo attached to pin " + String(SERVO_PIN));
  Serial.println("Setup complete");
}

// Try 1: based on a few things - sweeps, LEDs, etc.
void loop() {
  int pos;
  int MAX = 180;

  // Turn the red LED on by making the voltage LOW
  // digitalWrite(LED_BUILTIN_RED, LOW);

  // myservo.write(MAX);
  // delay(5000);

  for (pos = 0; pos <= MAX; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  // Turn the red LED off by making the voltage HIGH
  // digitalWrite(LED_BUILTIN_RED, HIGH);

  // Turn the blue LED on by making the voltage LOW
  // digitalWrite(LED_BUILTIN_BLUE, LOW);

  for (pos = MAX; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  // myservo.write(0);
  // delay(5000);

  // Turn the blue LED off by making the voltage HIGH
  // digitalWrite(LED_BUILTIN_BLUE, HIGH);

}