#include <Arduino.h>
#include <IRremote.h>

const byte IR_RECEIVE_PIN=7; // The infrared receiver is connected to pin 7. If you are using XIAO RP2040/XIAO ESP32, please change 7 to A0

void setup() {
    Serial.begin(115200);
    Serial.println(F("Enabling IRin"));
    IrReceiver.begin(IR_RECEIVE_PIN,ENABLE_LED_FEEDBACK); // Start infrared decoding
    Serial.print(F("Ready to receive IR signals at pin "));
    Serial.println(IR_RECEIVE_PIN);
    delay(1000);
}

void loop() {
    if (IrReceiver.decode()) // Decode successfully, receive a set of infrared signals
   {
      Serial.println(IrReceiver.decodedIRData.command, HEX); // Output infrared decoding result (hexadecimal)
      Serial.println(IrReceiver.decodedIRData.command); // Output infrared decoding result (octal)
      IrReceiver.resume(); // Receive the next set of values
   }
}