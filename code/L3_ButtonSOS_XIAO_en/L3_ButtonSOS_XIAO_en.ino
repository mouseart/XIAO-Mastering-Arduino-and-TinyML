/*
 * Button-Controlled Buzzer
 */
const int buttonPin = 1;    // Button is connected to pin 1; adjust for your board (e.g., D1 for XIAO RP2040/XIAO ESP32)
int buzzerPin = 3;         // Buzzer is connected to pin 3; adjust for your board (e.g., A3 for XIAO RP2040/XIAO ESP32)

void setup() {
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  // Configure the button pin as input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed
  if (buttonState == LOW) {
    // While the button remains pressed, keep the buzzer sounding
    while (buttonState == LOW) {
      tone(buzzerPin, 200);   // Make the buzzer sound at 200Hz
      delay(10);              // Small delay to avoid CPU overload; can be adjusted or a more sophisticated debouncing method used
      buttonState = digitalRead(buttonPin); // Continuously check the button state within the loop
    }
    // When the button is released, ensure the buzzer stops
    noTone(buzzerPin);
  }
}
