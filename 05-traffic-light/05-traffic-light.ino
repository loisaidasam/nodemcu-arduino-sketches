
/**
 * Traffic light
 */

#define led_red D1
#define led_yellow D5
#define led_green D8

#define sleeptime 700

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, LOW);
}

void transition(int pin1, int pin2) {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

void loop() {
  transition(led_yellow, led_green);
  delay(sleeptime);
  transition(led_green, led_yellow);
  delay(sleeptime);
  transition(led_yellow, led_red);
  delay(sleeptime);
  transition(led_red, led_yellow);
  delay(sleeptime);
}
