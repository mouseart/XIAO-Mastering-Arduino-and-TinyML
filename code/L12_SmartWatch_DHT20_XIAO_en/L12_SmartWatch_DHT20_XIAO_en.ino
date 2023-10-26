#include <Arduino.h>
#include <U8x8lib.h> //use u8x8 library
#include <PCF8563.h> //RTC library
PCF8563 pcf; //define variable pcf
#include <Wire.h>
#include "DHT.h" //DHT library
#define DHTTYPE DHT20 //The type of the temperature and humidity sensor is DHT20
DHT dht(DHTTYPE);
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE); //OLED's constructor, set data type, connect OLED display

void setup() {
    Serial.begin(9600);
    u8x8.begin(); //u8x8 starts working
    u8x8.setFlipMode(1);
    Wire.begin();
    pcf.init(); //Initialize the clock
    pcf.stopClock(); //Stop the clock
    //Set the current time and date:
    pcf.setYear(23);
    pcf.setMonth(05);
    pcf.setDay(29);
    pcf.setHour(18);
    pcf.setMinut(53);
    pcf.setSecond(0);
    pcf.startClock(); //The clock starts timing
}
void loop() {
    float temp, humi; //Define temperature and humidity variables
    temp = dht.readTemperature(); //Read the temperature value
    humi = dht.readHumidity(); //Read the humidity value
    Time nowTime = pcf.getTime(); //Get the time
    u8x8.setFont(u8x8_font_chroma48medium8_r); //u8x8 font

    //Display the current date, time, temperature, and humidity at different coordinates on the OLED screen.
    u8x8.setCursor(0, 0);
    u8x8.print(nowTime.day);
    u8x8.print("/");
    u8x8.print(nowTime.month);
    u8x8.print("/");
    u8x8.print("20");
    u8x8.print(nowTime.year);
    u8x8.setCursor(0, 1);
    u8x8.print(nowTime.hour);
    u8x8.print(":");
    u8x8.print(nowTime.minute);
    u8x8.print(":");
    u8x8.println(nowTime.second);
    delay(1000);
    u8x8.setCursor(0, 2);
    u8x8.print("Temp:");
    u8x8.print(temp);
    u8x8.print("C");
    u8x8.setCursor(0,3);
    u8x8.print("Humidity:");
    u8x8.print(humi);
    u8x8.print("%");
    u8x8.refreshDisplay();
    delay(200);
}