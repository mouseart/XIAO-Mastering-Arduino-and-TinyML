// This example shows the 3-axis acceleration.
#include "LIS3DHTR.h" // Declare library
#include <Wire.h>
LIS3DHTR<TwoWire> LIS; 
#define WIRE Wire // Initialize the module above using hardware I2C

void setup()
{
    Serial.begin(9600);
    while (!Serial) { }; // If you can't open the serial monitor, the code will stop here
    LIS.begin(WIRE, 0x19); // Initialize I2C with default value
    delay(100);
    LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ); // Set the accelerometer's output rate to 50Hz.
}
void loop()
{
    if (!LIS) {
        Serial.println("LIS3DHTR didn't connect.");
        while (1);
        return;
    }
    // Read the values of the X, Y, Z axes from the sensor, and display them on the serial monitor
    Serial.print("x:"); Serial.print(LIS.getAccelerationX()); Serial.print("  ");
    Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
    Serial.print("z:"); Serial.println(LIS.getAccelerationZ());
    delay(500);
}