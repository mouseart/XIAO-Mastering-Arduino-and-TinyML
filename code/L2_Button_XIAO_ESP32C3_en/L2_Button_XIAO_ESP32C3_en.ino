/*
 * Button controlling external LED of XIA

Apologies for the confusion. It seems that there was an issue with quoting text from the document. Let's continue:

#### Task 2: Use the button on the XIAO expansion board to control the external LED on the XIAO ESP32C3
For the Seeed XIAO ESP32C3, it doesn't have an on-board LED for users to use. To execute the Blink program, you first need to connect an LED to the board's `D10` pin as shown. 

> ⚠️ Note: Make sure to add a resistor (about 150Ω) in series with the LED to limit the current flowing through the LED and prevent overcurrent from burning out the LED.

Then, copy the following program into the Arduino IDE:
```cpp
/*
 * Button controlling external LED of XIAO ESP32C3
 */

const int buttonPin = 1;     // The pin number of the button
int buttonState = 0;    // Variable for reading the button status
int led = D10;  // Pin number of the LED

void setup() {
  // Initialize the LED pin as an output:
  pinMode(led, OUTPUT);
  // Initialize the button pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the state of the button:
  buttonState = digitalRead(buttonPin);
  // Check if the button is pressed. If it is, the button state is HIGH
  if (buttonState == HIGH) {
    // Turn the LED on:
    digitalWrite(led, HIGH);
  }
  else {
    // Turn the LED off:
    digitalWrite(led, LOW);
  }
}