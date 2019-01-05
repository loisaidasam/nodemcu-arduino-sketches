/**
 * Modified from Examples/ESP8266WiFi/WiFiClientBasic
 *
 * This sketch sends a message to a TCP server and reads the response
 */

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#define ssid "WIFI SSID"
#define password "WIFI PASSWORD"

// ip or dns
#define http_host "samsandberg.com"
#define http_port 80;
#define http_url "/ping/"

ESP8266WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(115200);
  
  // Initialize the LED_BUILTIN pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
  delay(10);

  // Turn the LED on by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);

  // Open:
  //WiFiMulti.addAP(ssid);

  // Password-protected:
  WiFiMulti.addAP(ssid, password);
  
  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(500);
}


void do_led_loop(int num_flashes) {
  for (int i = 0; i < num_flashes; i++) {
    // Turn the LED on by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
    delay(20);
    // Turn the LED off by making the voltage HIGH
    digitalWrite(LED_BUILTIN, HIGH);
    delay(20);
  }
}


void loop() {
  do_led_loop(10);

  Serial.print("connecting to ");
  Serial.println(http_host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;

  if (!client.connect(http_host, http_port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;
  }

  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + http_host + "\r\n" +
               "Connection: close\r\n\r\n");

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");

  Serial.println("wait 5 sec...");
  delay(5000);
}
