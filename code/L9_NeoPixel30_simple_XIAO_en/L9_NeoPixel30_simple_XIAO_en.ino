#include <Adafruit_NeoPixel.h> // Header file, declaring the library
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN 0 // The light strip is connected to pin 0. If you are using XIAO RP2040, please change 0 to A0
#define NUMPIXELS 30 // The number of LED lights on the light strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // Create a new light strip object, define data mode
#define DELAYVAL 500 // The interval time for each light to light up

void setup() {
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
    #endif
    pixels.begin(); // The light strip is ready to output data
}

void loop() {
    pixels.clear(); // All beads on the light strip are turned off
    for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Light up the beads in sequence, the color is green
        pixels.show(); // Display the light strip
        delay(DELAYVAL); 
    }
}