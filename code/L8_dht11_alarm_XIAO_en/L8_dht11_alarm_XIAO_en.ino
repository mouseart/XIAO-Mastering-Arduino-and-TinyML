#include "DHT.h"//Use DHT library
#include <Arduino.h>
#include <U8x8lib.h>//Use u8x8 library
#define DHTPIN 0 
#define DHTTYPE DHT11//Specify using DHT11
DHT dht(DHTPIN, DHTTYPE); 
int buzzerPin = A3;
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);//Set constructor to connect OLED display

void setup() { 
  pinMode(buzzerPin , OUTPUT);//Set buzzer pin to output mode
  Wire.begin();//Initialize wire library and join to I2C network
  dht.begin();//DHT begins operation
  u8x8.begin();//u8x8 begins operation
  u8x8.setPowerSave(0);  //Disable power save mode, 1 is enable. After enabling power save mode, nothing will be seen on the screen
  u8x8.setFlipMode(1);
}

void loop() { 
  float temp, humi;//Set variables temp and humi to floating point type, representing temperature and humidity respectively
  temp = dht.readTemperature();//Read temperature value and store it in temp
  humi = dht.readHumidity();//Read humidity value and store it in humi
  if (temp > 30 || humi < 40) {  //When the temperature is above 30 or the humidity is below 40, if either condition is met, the buzzer will sound an alarm
  tone(buzzerPin, 200, 200);
  }

  u8x8.setFont(u8x8_font_chroma48medium8_r);//Set display font
  u8x8.setCursor(0, 33);//Set the position of the drawing cursor (0,33)
  u8x8.print("Temp:");//Display "Temp:" at the position (0,33)
  u8x8.print(temp);//Then display the real-time temperature value
  u8x8.print("C");//Then display the unit of temperature "C"
  u8x8.setCursor(0,50);
  u8x8.print("Humidity:");
  u8x8.print(humi);
  u8x8.print("%");
  u8x8.refreshDisplay();
  delay(200);
}