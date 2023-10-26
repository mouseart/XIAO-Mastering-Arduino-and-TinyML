////////////////////////////////////////////////////////////////////////////////
// IDE:
//   Arduino 2.0.3
// Platform:
//   esp32 2.0.4 - https://github.com/espressif/arduino-esp32
// Board:
//   XIAO_ESP32C3
// Libraries:
//   ESP32Ping 1.6 - https://github.com/marian-craciunescu/ESP32Ping

////////////////////////////////////////////////////////////////////////////////
// Includes

#include <WiFi.h>
#include <ESP32Ping.h>

static constexpr unsigned long INTERVAL = 3000;	// [msec.]

static const char WIFI_SSID[] = "your-ssid";
static const char WIFI_PASSPHRASE[] = "your-password";

static const char SERVER[] = "www.seeedstudio.com";

void setup()
{
	Serial.begin(115200);
	delay(1000);
	Serial.println();
	Serial.println();

	Serial.println("WIFI: Start.");
	WiFi.mode(WIFI_STA);
	if (WIFI_SSID[0] != '\0')
	{
		WiFi.begin(WIFI_SSID, WIFI_PASSPHRASE);
	}
	else
	{
		WiFi.begin();
	}
}

void loop()
{
	static int count = 0;

	const bool wifiStatus = WiFi.status() == WL_CONNECTED;
	const int wifiRssi = WiFi.RSSI();

	const bool pingResult = !wifiStatus ? false : Ping.ping(SERVER, 1);
	const float pingTime = !pingResult ? 0.f : Ping.averageTime();

	Serial.print(count);
	Serial.print('\t');
	Serial.print(wifiStatus ? 1 : 0);
	Serial.print('\t');
	Serial.print(wifiRssi);
	Serial.print('\t');
	Serial.print(pingResult ? 1 : 0);
	Serial.print('\t');
	Serial.println(pingTime);
	count++;

	delay(INTERVAL);
}