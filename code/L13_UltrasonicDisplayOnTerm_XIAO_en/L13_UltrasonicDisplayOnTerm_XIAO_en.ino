#include "Ultrasonic.h"//declare the library file
Ultrasonic ultrasonic(0);//define variables, connect pins. If you're using XIAO RP2040/XIAO ESP32, please change 0 to D0
void setup() {
    Serial.begin(9600);
}
void loop() {
    long RangeInInches;//define a long integer variable named RangeInInches
    long RangeInCentimeters;//define a long integer variable named RangeInCentimeters

    Serial.println("The distance to obstacles in front is: ");
    RangeInInches = ultrasonic.MeasureInInches();//read the distance value (inches) measured by the ultrasonic distance sensor and store it in the variable RangeInInches
    Serial.print(RangeInInches);//serial print value
    Serial.println(" inch");
    delay(250);

    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); //read the distance value (centimeters) measured by the ultrasonic distance sensor and store it in the variable RangeInCentimeters
    Serial.print(RangeInCentimeters);//serial print value
    Serial.println(" cm");
    delay(250);
}