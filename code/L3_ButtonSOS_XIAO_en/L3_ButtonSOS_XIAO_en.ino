/*
 * Button-SOS
 */
const int buttonPin = 1; // The button is on pin 1, if you are using XIAO RP2040/XIAO ESP32, please change 1 to D1!
int pinBuzzer = 3; // The buzzer is on pin 3, if you are using XIAO RP2040/XIAO ESP32, please change 3 to A3!
void setup() {
  // Set the buzzer pin as output:
  pinMode(pinBuzzer, OUTPUT);
  // Set the button pin as input:
  pinMode(buttonPin, INPUT_PULLUP);
}
 
void loop() {
  // buttonState is the button variable, read the button state and store it in the variable:
  int buttonState = digitalRead(buttonPin);
 
  // Check if the button is pressed, if the button is pressed:
  if (buttonState == LOW) {
    // The buzzer sounds with a frequency of 200, for a duration of 200 milliseconds
    tone(pinBuzzer, 200, 200);
  }
}