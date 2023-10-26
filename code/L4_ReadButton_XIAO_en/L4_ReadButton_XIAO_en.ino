/*
 * Use the Serial Monitor to Check if the Button is Pressed
*/

const int buttonPin = 1; // Define the button switch as pin 1. If you are using XIAO RP2040/XIAO ESP32, please change 1 to D1
int buttonState = 0; // Define buttonState as a variable to store the button status

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as input
    Serial.begin(9600); // Initialize the serial port
}

void loop() {
    buttonState = digitalRead(buttonPin);  // Read the button status and store it in the buttonState variable
    Serial.println(buttonState); // Send the button status data to the serial port
    delay(500);
}
