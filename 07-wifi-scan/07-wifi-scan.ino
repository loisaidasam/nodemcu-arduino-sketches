/**
 * Modified from Examples/ESP8266WiFi/WiFiScan
 *
 * This sketch demonstrates how to scan WiFi networks.
 * The API is almost the same as with the WiFi Shield library,
 * the most obvious difference being the different file you need to include:
*/

#include "ESP8266WiFi.h"

#define only_show_open false

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void do_wifi_scan() {
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
    return;
  }
  Serial.print(n);
  Serial.println(" total networks found");
  int network_num = 0;
  for (int i = 0; i < n; ++i) {
    delay(10);
    // Print SSID and RSSI for each network found
    boolean open = WiFi.encryptionType(i) == ENC_TYPE_NONE;
    if (only_show_open && ! open) {
      continue;
    }
    network_num++;
    Serial.print(network_num);
    Serial.print(": ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" (");
    Serial.print(WiFi.RSSI(i));
    Serial.print(")");
    Serial.println(open ? " " : "*");
  }
  if (only_show_open) {
    Serial.print(network_num);
    Serial.println(" open networks");
  }
  Serial.println("");
}

void loop() {
  do_wifi_scan();
  // Wait a bit before scanning again
  delay(5000);
}
