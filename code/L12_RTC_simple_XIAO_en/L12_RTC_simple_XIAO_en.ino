#include <PCF8563.h> //Declare library file
PCF8563 pcf;//Define variable pcf

void setup() {
    Serial.begin(9600);
    pcf.init();//Initialize the clock
    pcf.stopClock();//Stop the clock

    //Set the current date and time. After setting, it will start timing from this moment

    pcf.setYear(23);//Year
    pcf.setMonth(05);//Month
    pcf.setDay(29);//Day
    pcf.setHour(16);//Hour
    pcf.setMinut(10);//Minute
    pcf.setSecond(0);//Second

    pcf.startClock();//Clock starts timing
}

void loop() {
    Time nowTime = pcf.getTime();//Get time

    //Print the current date and time on the serial monitor
    Serial.print(nowTime.day);
    Serial.print("/");
    Serial.print(nowTime.month);
    Serial.print("/");
    Serial.print("20"); // Manually input the set year
    Serial.print(nowTime.year);
    Serial.print("/");
    Serial.print(nowTime.hour);
    Serial.print(":");
    Serial.print(nowTime.minute);
    Serial.print(":");
    Serial.println(nowTime.second);
    delay(1000);
}
