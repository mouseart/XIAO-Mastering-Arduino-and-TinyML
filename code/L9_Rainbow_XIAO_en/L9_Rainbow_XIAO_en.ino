#include <Adafruit_NeoPixel.h> // Header file, declaring the library
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIXEL_PIN 0 // The light strip is connected to pin A0. If you are using XIAO RP2040, please change 0 to A0
#define PIXEL_COUNT 30 // The number of LED lights on the light strip
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// Declare a new light strip object and define the data mode

void setup() {
    strip.begin(); // Initialize the light strip, the light strip is ready to output data
}

void loop() {
    strip.clear();// Turn off all the lights on the light strip
    rainbow(10);// The light strip displays a rainbow light effect. The number in the parenthesis represents the speed of the rainbow light circulation. The smaller the number, the faster the circulation speed
}
// The following is the code for the rainbow light effect, presenting the breathing light effect. This code can be found in the example program buttoncycler
void rainbow(int wait) {
    for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
        for(int i=0; i<strip.numPixels(); i++) { 
            int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
        }
        strip.show(); // The light strip presents a light effect
        delay(wait);  // Delay
    }
}