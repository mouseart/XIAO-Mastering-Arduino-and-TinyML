const int buttonPin = 1;  // The on-board button switch on the XIAO expansion board is D1, which we define as pin 1
// If you are using XIAO RP2040, please change 1 to D1
int buttonState = 0;  // buttonState is a variable to store the button status

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);// Set the LED pin to output status
    pinMode(buttonPin, INPUT_PULLUP);// Set the button pin to input status
}

void loop() {
    // Read the button status and store it in the buttonState variable
    buttonState = digitalRead(buttonPin);  
    // Check whether the button is pressed, if the button is pressed
    if (buttonState == HIGH) {
        // Turn on the LED:
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
        // Turn off the LED:
        digitalWrite(LED_BUILTIN, LOW);
    }
}