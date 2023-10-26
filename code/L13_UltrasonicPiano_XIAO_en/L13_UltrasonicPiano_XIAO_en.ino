#include "Ultrasonic.h"//declare the library file
Ultrasonic ultrasonic(0);//define the ultrasonic object and connect the ultrasonic wave to the A0 interface. If you're using XIAO RP2040, please change 0 to D0
int buzzerPin = 3;//The buzzer is connected to the A3 interface, if you're using XIAO RP2040, please change 3 to A3

#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047

void setup()
{
    Serial.begin(9600);
    pinMode(buzzerPin,OUTPUT);
}

void loop()
{
    // Read the distance value detected by the ultrasonic distance sensor, in centimeters, and print it on the serial monitor
    long RangeInCentimeters;
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); 
    Serial.print(RangeInCentimeters);
    Serial.println(" cm");
    delay(250);
    // Using an if statement for conditional judgment, when the distance is 4, 6, 8, 10, 12, 14, 16, 18, it corresponds to C5, D5, E5, F5, G5, A5, B5, C6
    if (((long)RangeInCentimeters== 4)) {  //Do
        tone(3,NOTE_C5,100);   
    }
    if (((long) RangeInCentimeters== 6)) { //Re
        tone(3,NOTE_D5,100);    
    }
    if (((long) RangeInCentimeters== 8)) { //Mi
        tone(3,NOTE_E5,100);  
    }
    if (((long) RangeInCentimeters== 10)) {  //Fa
        tone(3,NOTE_F5,100);
    }
    if (((long) RangeInCentimeters== 12)) {  //Sol
        tone(3,NOTE_G5,100);
    }
    if (((long) RangeInCentimeters== 14)) {  //La
        tone(3,NOTE_A5,100);
    }
    if (((long) RangeInCentimeters== 16)) { //Xi
        tone(3,NOTE_B5,100);
    }
    if (((long) RangeInCentimeters== 18)) {  //Do
        tone(3,NOTE_C6,100);
    }
}