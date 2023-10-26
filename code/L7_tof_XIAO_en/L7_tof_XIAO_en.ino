#include <Grove_LED_Bar.h>
#include "Seeed_vl53l0x.h"

const int Buzzer = 8;//Vibration motor connected to D8
Grove_LED_Bar bar(0, 1, 0, LED_CIRCULAR_24);  //Grove-LED ring connected to D0 
Seeed_vl53l0x VL53L0X;  //Grove-tof distance sensor connected to IIC (D4/D5)

#if defined(ARDUINO_SAMD_VARIANT_COMPLIANCE) && defined(SerialUSB)
#define SERIAL SerialUSB
#else
#define SERIAL Serial
#endif


void setup() {
    bar.begin();

    pinMode(Buzzer, OUTPUT);
    digitalWrite(Buzzer, LOW);   // turn the Buzzer on (HIGH is the voltage level)
    // Turn off all LEDs
    bar.setBits(0x0);            

    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    SERIAL.begin(115200);
    Status = VL53L0X.VL53L0X_common_init();
    if (VL53L0X_ERROR_NONE != Status) {
        SERIAL.println("Starting VL53L0X measurement failed!");
        VL53L0X.print_pal_error(Status);
        while (1);
    }

    VL53L0X.VL53L0X_long_distance_ranging_init();

    if (VL53L0X_ERROR_NONE != Status) {
        SERIAL.println("Starting VL53L0X measurement failed!");
        VL53L0X.print_pal_error(Status);
        while (1);
    }

}

void loop() {

    VL53L0X_RangingMeasurementData_t RangingMeasurementData;
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;

    memset(&RangingMeasurementData, 0, sizeof(VL53L0X_RangingMeasurementData_t));
    Status = VL53L0X.PerformSingleRangingMeasurement(&RangingMeasurementData);
    if (VL53L0X_ERROR_NONE == Status) {
        if (RangingMeasurementData.RangeMilliMeter >= 2000) {
            SERIAL.println("Out of range!!");
            digitalWrite(Buzzer, LOW);   // turn the Buzzer off (LOW is the voltage level)

            // Turn off all LEDs
            bar.setBits(0x0);

        } 
        else if (RangingMeasurementData.RangeMilliMeter <= 1000) {
            digitalWrite(Buzzer, HIGH);   // turn the Buzzer on (HIGH is the voltage level)
            // Turn on all LEDs
            bar.setBits(0b111111111111111111111111);

            SERIAL.print("Distance:");
            SERIAL.print(RangingMeasurementData.RangeMilliMeter);
            SERIAL.println(" mm");
        } 
        else {    
            digitalWrite(Buzzer, LOW);   // turn the Buzzer off (LOW is the voltage level)

            // Turn off all LEDs
            bar.setBits(0x0);

            SERIAL.print("Distance:");
            SERIAL.print(RangingMeasurementData.RangeMilliMeter);
            SERIAL.println(" mm");
        }

    }
    else {
        SERIAL.print("Measurement failed!! Status code =");
        SERIAL.println(Status);
        digitalWrite(Buzzer, LOW);   // turn the Buzzer off (LOW is the voltage level)

        // Turn off all LEDs
        bar.setBits(0x0);
    }

    delay(250);   

}
