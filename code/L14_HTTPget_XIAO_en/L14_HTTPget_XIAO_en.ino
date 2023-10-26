#include "WiFi.h"
#include <HTTPClient.h>

const char* ssid = "your-ssid";
const char* password = "your-password";
String serverName = "http://192.168.1.2/items/sensor";
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup()
{
    Serial.begin(115200); 

    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

    Serial.println("Setup done");
}

void loop()
{
    if ((millis() - lastTime) > timerDelay) {
        //Check WiFi connection status
        if(WiFi.status()== WL_CONNECTED){
            HTTPClient http;

            String serverPath = serverName ;

            http.begin(serverPath.c_str());

            int httpResponseCode = http.GET();

            if (httpResponseCode>0) {
                Serial.print("HTTP Response code: ");
                Serial.println(httpResponseCode);
                String payload = http.getString();
                Serial.println(payload);
            }
            else {
                Serial.print("Error code: ");
                Serial.println(httpResponseCode);
            }

            http.end();
        }
        else {
            Serial.println("WiFi Disconnected");
        }
        lastTime = millis();
    }
}