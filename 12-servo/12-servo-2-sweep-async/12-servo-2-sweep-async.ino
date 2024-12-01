
#include <Servo.h>

// #define LED_BUILTIN_RED D0
// #define LED_BUILTIN_BLUE D4
// #define SERVO_PIN D1
#define SERVO_PIN D2
// #define SERVO_PIN D8

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

unsigned long previousMillis = 0;
const long interval = 5 * 1000;  // interval at which to switch servo position (milliseconds)
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

// Trying more async...
void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    Serial.print("Changing servo position. Current time: ");
    Serial.println(currentMillis);
   
    previousMillis = currentMillis;

    if (servoPos == 0) {
      servoPos = 90;
    } else {
      servoPos = 0;
    }
    myservo.write(servoPos);
    Serial.print("Servo position set to: ");
    Serial.println(servoPos);

    // Read back the servo position
    int actualPos = myservo.read();
    Serial.print("Actual servo position: ");
    Serial.println(actualPos);

    if (actualPos != servoPos) {
      Serial.println("Warning: Actual position doesn't match set position");
    }
  }
}
