#include <Arduino.h>
#include <U8x8lib.h>//Use U8x8 library file
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
//Set the constructor, define the display type, controller, RAM buffer size, and communication protocol, generally determine according to the used display model

void setup(void) {
    u8x8.begin();//Initialize u8x8 library
    u8x8.setFlipMode(1);//Flip the display 180 degrees, generally numbers 0 and 1
}

void loop(void) {
    u8x8.setFont(u8x8_font_chroma48medium8_r);//Define u8x8 font
    u8x8.setCursor(0, 0);//Set the position of the drawing cursor
    u8x8.print("Hello World!");//Draw content on OLED: Hello World！
}