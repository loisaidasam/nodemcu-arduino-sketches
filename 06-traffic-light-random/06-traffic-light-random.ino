
/**
 * Randomly control three lights
 *
 * (red/yellow/green, like a traffic light)
 *
 * https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
 */

#define led_red D1
#define led_yellow D5
#define led_green D8

#define show_progress true

#define bitmask_red 1
#define bitmask_yellow 2
#define bitmask_green 4

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
  if (show_progress) {
    pinMode(LED_BUILTIN, OUTPUT);
  }
}

void maybe_light(int pin) {
  if (random(2) == 1) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
}

void loop_iterative() {
  maybe_light(led_red);
  maybe_light(led_yellow);
  maybe_light(led_green);
}

void light_by_bitmask(int pin, int bitmask, int bitmask_pin) {
  if (bitmask & bitmask_pin) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
}

void loop_bitmask() {
  long bitmask = random(8);
  light_by_bitmask(led_red, bitmask, bitmask_red);
  light_by_bitmask(led_yellow, bitmask, bitmask_yellow);
  light_by_bitmask(led_green, bitmask, bitmask_green);
}

void loop_bitmask_shift() {
  long bitmask = random(8);
  light_by_bitmask(led_red, bitmask, 1);
  bitmask = bitmask >> 1;
  light_by_bitmask(led_yellow, bitmask, 1);
  bitmask = bitmask >> 1;
  light_by_bitmask(led_green, bitmask, 1);
}

void loop() {
  if (show_progress) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  // loop_iterative();
  // loop_bitmask();
  loop_bitmask_shift();
  delay(500);
  if (show_progress) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(500);
}
