#define ROTARY_ANGLE_SENSOR A0 // Define rotary potentiometer interface as A0
#define LEDPIN 7 // Define LED interface as 7
#define ADC_REF 3 // Reference voltage is 3V
#define GROVE_VCC 3 // Grove reference voltage is 3V
#define FULL_ANGLE 300 // Maximum rotation angle of the rotary potentiometer is 300°

void setup()
{
    Serial.begin(9600); // Initialize serial communication
    pinMode(ROTARY_ANGLE_SENSOR, INPUT); // Set the rotary potentiometer pin as input
    pinMode(LEDPIN, OUTPUT); // Set the LED pin as output
}

void loop()
{
    float voltage; // Declare voltage as a float
    int sensor_value = analogRead(ROTARY_ANGLE_SENSOR); // Read the analog value at the rotary potentiometer pin
    voltage = (float)sensor_value * ADC_REF / 1023; // Calculate the real-time voltage
    float degrees = (voltage * FULL_ANGLE) / GROVE_VCC; // Calculate the angle of rotation of the knob
    Serial.println("The angle between the mark and the starting position:"); // Print string to the serial monitor
    Serial.println(degrees); // Print the angle of rotation of the rotary potentiometer to the serial monitor
    delay(100);

    int brightness; // Declare brightness as an integer
    brightness = map(degrees, 0, FULL_ANGLE, 0, 255); // Map the angle of the rotary potentiometer to the LED brightness and store it in the brightness variable
    analogWrite(LEDPIN, brightness); // Write the brightness value to the LED
    delay(500);
}
