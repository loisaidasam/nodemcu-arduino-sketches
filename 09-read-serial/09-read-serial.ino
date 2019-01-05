
/**
 * https://www.arduino.cc/reference/en/language/functions/communication/serial/
 * https://unix.stackexchange.com/a/117064/21868
 * 
 */

String data;

#define baud_rate 115200

void setup() {
  Serial.print("Using serial baud rate ");
  Serial.println(baud_rate);
  Serial.begin(baud_rate);
}

void loop() {
  Serial.println("loop()");
  while(Serial.available()) {
    data = Serial.readString();
    Serial.print(data);
  }
  Serial.println();
  delay(1000);
}
