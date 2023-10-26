// Define the LED pin according to the pin diagram
int led = D10;

void setup() {
    // Initialize the digital pin 'led' as output
    pinMode(led, OUTPUT);
}

void loop() {
    digitalWrite(led, HIGH);   // Turn the LED on
    delay(1000);               // Wait for a second
    digitalWrite(led, LOW);    // Turn the LED off
    delay(1000);               // Wait for a second
}
