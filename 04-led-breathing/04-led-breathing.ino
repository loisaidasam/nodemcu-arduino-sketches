/*
via https://arduining.com/2015/08/20/nodemcu-breathing-led-with-arduino-ide/

LED_Breathing.ino Arduining.com  20 AUG 2015
Using NodeMCU Development Kit V1.0
Going beyond Blink sketch to see the blue LED breathing.
A PWM modulation is made in software because GPIO16 can't
be used with analogWrite().

Inspired by the Apple’s "breathing" pattern used for the sleep indicator.
Here is the code to generate a “breathing LED”.

NOTE:
The Arduino code runs inside a multitasking application, the ESP8266 is running
at the same time TCP and WiFi stacks.

The sketch can breake the multitasking execution if your code runs in a blocking
section.

The delayMicroseconds() is one of those blocking functions, delay(0)  was used
to prevent watchdog reset inside the PWM loops.
*/

#define LED     D0        // Led in NodeMCU at pin GPIO16 (D0).
 
#define BRIGHT    350     //max led intensity (1-500)
#define INHALE    1250    //Inhalation time in milliseconds.
#define PULSE     INHALE*1000/BRIGHT
#define REST      1000    //Rest Between Inhalations.

//----- Setup function. ------------------------
void setup() {                
  pinMode(LED, OUTPUT);   // LED pin as output.    
}

//----- Loop routine. --------------------------
void loop() {
  //ramp increasing intensity, Inhalation: 
  for (int i=1;i<BRIGHT;i++){
    digitalWrite(LED, LOW);          // turn the LED on.
    delayMicroseconds(i*10);         // wait
    digitalWrite(LED, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);   // wait
    delay(0);                        //to prevent watchdog firing.
  }
  //ramp decreasing intensity, Exhalation (half time):
  for (int i=BRIGHT-1;i>0;i--){
    digitalWrite(LED, LOW);          // turn the LED on.
    delayMicroseconds(i*10);          // wait
    digitalWrite(LED, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);  // wait
    i--;
    delay(0);                        //to prevent watchdog firing.
  }
  delay(REST);                       //take a rest...
}
