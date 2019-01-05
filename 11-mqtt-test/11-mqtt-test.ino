/**
 * MQTT test
 *
 * Read from MQTT and use value N to blink onboard LED N times
 *
 * via https://www.home-assistant.io/blog/2015/10/11/measure-temperature-with-esp8266-and-report-to-mqtt/
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid "WIFI SSID"
#define wifi_password "WIFI PASSWORD"

#define mqtt_server "example.com"
#define mqtt_port 8883

#define topic_test_foo "test/foo"
#define topic_test_num_flashes "test/num_flashes"

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  delay(10);
  Serial.begin(115200);
  // Initialize the LED_BUILTIN pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
  // Turn the LED on by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  setup_wifi();
  setup_mqtt();
}

void setup_wifi() {
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup_mqtt() {
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  if (strcmp(topic, topic_test_num_flashes) == 0) {
    const char* num_flashes_str = (char*) payload;
    int num_flashes = atoi(num_flashes_str);
    Serial.print("Triggering ");
    Serial.print(num_flashes);
    Serial.println(" flashes!");
    do_led_loop(num_flashes);
  }
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
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void reconnect() {
  // Turn the LED on by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      client.subscribe(topic_test_foo);
      client.subscribe(topic_test_num_flashes);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
  // Turn the LED off by making the voltage HIGH
  digitalWrite(LED_BUILTIN, HIGH);
}
