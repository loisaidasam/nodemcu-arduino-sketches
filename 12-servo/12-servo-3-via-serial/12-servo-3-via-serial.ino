
#include <Servo.h>

// #define LED_BUILTIN_RED D0
// #define LED_BUILTIN_BLUE D4
// #define SERVO_PIN D1
#define SERVO_PIN D2
// #define SERVO_PIN D8

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int servoPos = 0;  // 0 or 90


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

// Explicitly tell it what angle over serial
void loop () {
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n');  // Read until newline character
    Serial.print("Received: ");
    Serial.println(inputString);
    servoPos = inputString.toInt();
    myservo.write(servoPos);
  }
}
