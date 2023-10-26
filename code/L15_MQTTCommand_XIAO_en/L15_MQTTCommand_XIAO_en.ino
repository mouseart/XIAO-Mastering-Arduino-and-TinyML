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
//  https://github.com/Seeed-Studio/Seeed_Arduino_MultiGas


////////////////////////////////////////////////////////////////////////////////
// Includes


#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>


const char* ssid = "ssid";
const char* password = "pass";


const char* mqtt_server = "broker.hivemq.com";


WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;


int speakerPin = A3;


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


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  if((char)payload[0]=='0'){
    Serial.print("  RUN");
    digitalWrite(speakerPin, HIGH);
    delay(2000);
    digitalWrite(speakerPin, LOW);
    delay(100);  
  }
  Serial.println();
}



void setup() {
  Serial.begin(115200);
  pinMode(speakerPin, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.subscribe("XIAO_ESP32/Recieve");
  client.setCallback(callback);
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("XIAO_ESP32")) {
      Serial.println("connected");
      // Subscribe
      
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
    client.subscribe("XIAO_ESP32/Recieve");
  }
  client.loop();


}