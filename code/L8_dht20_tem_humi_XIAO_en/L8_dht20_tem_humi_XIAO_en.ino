#include "DHT.h"	//Use DHT library
#include <Arduino.h>
#include <U8x8lib.h>	//Use u8x8 library
#define DHTTYPE DHT20
DHT dht(DHTTYPE);	//DHT20 does not need to define pins

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);	//Setup constructor to connect to OLED screen

void setup() { 
    Wire.begin();	//Initialize wire library, and join I2C network
    dht.begin();	//DHT starts working
    u8x8.begin();	//u8x8 starts working
    u8x8.setPowerSave(0);  //Turn off power saving mode, 1 is on, and nothing can be seen on the screen after power saving mode is on
    u8x8.setFlipMode(1);
}

void loop() { 
    float temp, humi;	//Set the variables temp and humi to floating point type, representing temperature and humidity respectively
    temp = dht.readTemperature();	//Read temperature value and store it in temp
    humi = dht.readHumidity();	//Read humidity value and store it in humi
    u8x8.setFont(u8x8_font_chroma48medium8_r);	//Set display font
    u8x8.setCursor(0, 33);	//Set the position of the drawing cursor (0,33)
    u8x8.print("Temp:");	//Display Temp at the position (0,33)
    u8x8.print(temp);	//Display real-time temperature value
    u8x8.print("C");	//Display the unit "C" of temperature
    u8x8.setCursor(0,50);
    u8x8.print("Humidity:");
    u8x8.print(humi);
    u8x8.print("%");
    u8x8.refreshDisplay();
    delay(200);
}