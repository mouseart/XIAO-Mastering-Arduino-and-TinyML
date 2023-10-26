#include "LIS3DHTR.h"// Declare the library file for the 3-axis accelerometer
#include <Adafruit_NeoPixel.h>// Declare the library file for the light strip
#ifdef __AVR__
#include <avr/power.h> 
#endif
// The following is to initialize the module using software I2C or hardware I2C
#ifdef SOFTWAREWIRE
#include <SoftwareWire.h>
SoftwareWire myWire(3, 2);
LIS3DHTR<SoftwareWire> LIS; 
#define WIRE myWire
#else
#include <Wire.h>
LIS3DHTR<TwoWire> LIS;    
#define WIRE Wire
#endif

#define PIXEL_PIN 0 // Define the pin of the light strip, if you are using XIAO RP2040/XIAO ESP32, please change 0 to A0
#define PIXEL_COUNT 30 // Define the number of LEDs on the light strip as 30
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800); // Declare the light strip object and set the data type

void setup() { 
    Serial.begin(9600); // Initialize the serial monitor
    while (!Serial) {};// If you do not open the serial monitor, the code will stop here, so please open the serial monitor
    LIS.begin(WIRE, 0x19); // IIC initialization
    delay(100);
    LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ); // Set the output rate of the accelerometer to 50Hz
    strip.begin(); // The light strip starts working
    strip.show(); // The light strip displays
}
void loop() {
    if (!LIS) {  // Check if the 3-axis accelerometer is connected correctly
        Serial.println("LIS3DHTR didn't connect.");
        while (1);
        return;
    }

    if ((abs(LIS.getAccelerationX()) > 0.2)) {
        theaterChase(strip.Color(127, 0, 0), 50); // The light strip turns red
    }
    if ((abs(LIS.getAccelerationY()) > 0.2)) {
        theaterChase(strip.Color(0, 127, 0), 50); // The light strip turns green
    }
    if ((abs(LIS.getAccelerationZ()) > 1.0)) {
        theaterChase(strip.Color(0, 0, 127), 50); // The light strip turns blue
    }
    else
    {
        strip.clear(); 
        strip.show();
    }

    // Read the values of the X, Y, and Z axes from the sensor and display them on the serial monitor
    Serial.print("x:"); Serial.print(LIS.getAccelerationX()); Serial.print("  ");
    Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
    Serial.print("z:"); Serial.println(LIS.getAccelerationZ());

    delay(500);
}
// Set theaterChase for flashing light effects
void theaterChase(uint32_t color, int wait) {
    for(int a=0; a<10; a++) {  
        for(int b=0; b<3; b++) { 
            strip.clear();   
            for(int c=b; c<strip.numPixels(); c += 3) {
                strip.setPixelColor(c, color);
            }
            strip.show(); 
            delay(wait);
        }
    }
}