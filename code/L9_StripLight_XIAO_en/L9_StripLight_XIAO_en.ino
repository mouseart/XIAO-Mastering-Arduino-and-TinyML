#include <Adafruit_NeoPixel.h>// Header file, declare library
#ifdef __AVR__
#include <avr/power.h> 
#endif
#define LIGHT_PIN 7// Define the light sensor connected to A7. If you are using XIAO RP2040, please change 7 to A3. If you are using XIAO BLE, please change 7 to 5
#define PIXEL_PIN 0 // The light strip is connected to the A0 pin. If you are using XIAO RP2040, please change 0 to A0
#define PIXEL_COUNT 30 // The number of LEDs on the light strip
int readValue = 0;// Define variable readValue to store light values
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// Declare the light strip object and define the data mode
void setup() {
  strip.begin(); // Initialize the light strip and prepare the light strip to output data
  pinMode(LIGHT_PIN , INPUT); // Set the pin of the light sensor to input state
}
void loop() {
  strip.clear();// Turn off all the beads on the light strip
  rainbow(10);// The light strip shows a rainbow light effect. The number in the parentheses represents the speed of the rainbow light rotation. The smaller the number, the faster the rotation speed
  readValue = analogRead(A7);// Read the analog value of the light on the A7 pin and store it in the readValue variable. If you are using XIAO RP2040, please change A7 to A3. If you are using XIAO BLE, please change A7 to A5
    if(readValue > 500){ // Conditional judgment, if the light value is greater than 500, then the light strip presents a rainbow light effect, otherwise, the light strip is turned off
        rainbow(10);
    }else {
        strip.clear();  
        strip.show(); 
    }
}
// The following is the code for the rainbow light effect, presenting the breathing light effect, this code can be found in the sample program buttoncycler
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