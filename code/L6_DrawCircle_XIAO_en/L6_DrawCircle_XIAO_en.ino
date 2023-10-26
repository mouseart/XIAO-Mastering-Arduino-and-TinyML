#include<Arduino.h>
#include<U8g2lib.h>//Use U8g2 library

// Determine whether to use SPI or I2C protocol
#ifdef U8X8_HAVE_HW_SPI
#include<SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include<Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// Set up the constructor, define display type, controller, RAM buffer size, and communication protocol

void draw(void) { 
    u8g2.drawCircle(20, 25, 10, U8G2_DRAW_ALL);// Draw a full circle with a diameter of 21 at coordinates (20, 25)
}

void setup(void) {
    u8g2.begin();// Initialize the library
}

void loop(void) {
    // Cycle through image display
    u8g2.firstPage();
    do {
        draw();// Use draw function
    } while( u8g2.nextPage() );

    delay(1000);
}