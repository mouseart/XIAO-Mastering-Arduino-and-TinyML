////////////////////////////////////////////////////////////////////////////////
// IDE:
//   Arduino 2.0.0
// Platform:
//   esp32 2.0.5 - https://github.com/espressif/arduino-esp32
// Board:
//   XIAO_ESP32C3
// Libraries:
//   MQTT 2.5.0 - https://github.com/knolleary/pubsubclient
//   ArduinoJson 6.19.4 - https://github.com/bblanchon/ArduinoJson

////////////////////////////////////////////////////////////////////////////////
// Includes

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "DHT.h"
#define DHTTYPE DHT20   
DHT dht(DHTTYPE); 

const char* ssid = "ssid";
const char* password = "pass";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

float temperature = 0;
float humidity = 0;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  Wire.begin();
  dht.begin();
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("XIAO_ESP32")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("XIAO_ESP32/LEDOUTPUT");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
    
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  float temp_hum_val[2] = {0};
  if (now - lastMsg > 5000) {
    lastMsg = now;

    dht.readTempAndHumidity(temp_hum_val);
    temperature = temp_hum_val[1];   
  
    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);
    client.publish("XIAO_ESP32C3_Telemetry/Temperaturedataread", tempString);

    humidity = temp_hum_val[0];
    
    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    Serial.print("Humidity: ");
    Serial.println(humString);
    client.publish("XIAO_ESP32_Telemetry/Humiditydataread", humString);
  }

}