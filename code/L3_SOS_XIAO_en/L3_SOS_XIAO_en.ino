/*
 * SOS
 */
 
 int pinBuzzer = 3; // Define the buzzer on pin 3, if you're using XIAO RP2040/XIAO ESP32, change 3 to A3
 
 void setup() {
    pinMode(pinBuzzer, OUTPUT); // Set the buzzer pin to output state
}

void loop() {
    // Emit three short signals:
    for(int i = 0; i < 3; i++){
        tone(pinBuzzer, 200);
        delay(100);
        noTone(pinBuzzer);
        delay(100);
    }
    delay(200);

    // Emit three long signals:
    for(int i = 0; i < 3; i++){
        tone(pinBuzzer, 200);
        delay(300);
        noTone(pinBuzzer);
        delay(100);
    }
    delay(200);

    // Emit three short signals again:
    for(int i = 0; i < 3; i++){
        tone(pinBuzzer, 200);
        delay(100);
        noTone(pinBuzzer);
        delay(100);
    }
    delay(800); // Wait before repeating
}