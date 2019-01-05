
/**
 * Testing writing to LED on D* pins
 */

#define LED D0    // OK, but onboard red LED blinks opposite
//#define LED D1    // OK
//#define LED D2    // OK
//#define LED D3    // OK
//#define LED D4    // OK, but onboard blue LED blinks opposite
//#define LED D5    // OK
//#define LED D6    // OK
//#define LED D7    // OK
//#define LED D8    // OK
 
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
