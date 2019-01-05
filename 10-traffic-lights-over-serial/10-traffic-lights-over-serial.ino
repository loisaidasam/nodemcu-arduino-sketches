
/**
 * Traffic light over Serial
 * 
 * ( stty raw speed 115200 >&2; echo 'red' ) > /dev/cu.SLAB_USBtoUART <&1
 */

#define baud_rate 115200

#define led_red D1
#define led_yellow D5
#define led_green D8

String data;
int current_led = -1;

void setup() {
//  Serial.print("Using serial baud rate ");
//  Serial.println(baud_rate);
  Serial.begin(baud_rate);

  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);

  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, LOW);
}

void transition(int led) {
  if (current_led == led) {
    // No op    
    return;
  }
  if (current_led != -1) {
    digitalWrite(current_led, LOW);
  }
  if (led != -1) {
    digitalWrite(led, HIGH);
  }
  current_led = led;
}

void handle_input(String input) {
  if (input.indexOf('\n') != -1) {
    input = input.substring(0, input.indexOf('\n'));
  }
//  Serial.print("handle_input(): *");
//  Serial.print(input);
//  Serial.println("*");
  if (input == "red") {
    transition(led_red);
    return;
  }
  if (input == "yellow") {
    transition(led_yellow);
    return;
  }
  if (input == "green") {
    transition(led_green);
    return;
  }
  transition(-1);
//  Serial.println("Unknown input");
}

void loop() {
  while(Serial.available()) {
    //data = Serial.readStringUntil('\n');
    data = Serial.readString();
    handle_input(data);
  }
}
