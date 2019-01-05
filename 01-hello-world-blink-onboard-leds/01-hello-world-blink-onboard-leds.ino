/**
 * Hello world
 *
 * The NodeMCU has two onboard LEDs, one blue and one red
 * Let's make 'em blink!
 */

#define LED_BUILTIN_RED D0
#define LED_BUILTIN_BLUE D4
 
void setup() {
  // Initialize the pins as outputs
  pinMode(LED_BUILTIN_RED, OUTPUT);
  pinMode(LED_BUILTIN_BLUE, OUTPUT);
  // Turn the LEDs off by making the voltage HIGH
  // (I know, this seems counter-intuitive, but this is how the on-board LEDs work)
  digitalWrite(LED_BUILTIN_RED, HIGH);
  digitalWrite(LED_BUILTIN_BLUE, HIGH);
}

void loop() {
  // Turn the red LED on by making the voltage LOW
  digitalWrite(LED_BUILTIN_RED, LOW);
  // Wait for a second
  delay(1000);
  // Turn the blue LED on by making the voltage LOW
  digitalWrite(LED_BUILTIN_BLUE, LOW);
  // Wait for a second
  delay(1000);
  // Turn the red LED off by making the voltage HIGH
  digitalWrite(LED_BUILTIN_RED, HIGH);
  // Wait for a second
  delay(1000);
  // Turn the blue LED off by making the voltage HIGH
  digitalWrite(LED_BUILTIN_BLUE, HIGH);
  // Wait for two seconds
  delay(2000);
}
