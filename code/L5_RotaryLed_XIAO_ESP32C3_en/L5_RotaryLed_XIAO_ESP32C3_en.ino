#define ROTARY_ANGLE_SENSOR A0 // Define rotary potentiometer interface A0
#define LEDPIN D10 // Define LED light interface 10
#define ADC_REF 3 // Reference voltage 3V
#define GROVE_VCC 3 // GROVE reference voltage 3V
#define FULL_ANGLE 300 // The maximum rotation angle of the rotary potentiometer is 300°

void setup()
{
    Serial.begin(9600); // Initialize serial communication
    pinMode(ROTARY_ANGLE_SENSOR, INPUT); // Set the rotary potentiometer pin to input mode
    pinMode(LEDPIN, OUTPUT); // Set the LED light pin to output mode 
}

void loop()
{   
    float voltage; // Define voltage variable as float
    int sensor_value = analogRead(ROTARY_ANGLE_SENSOR); // Read the analog value on the rotary potentiometer pin
    voltage = (float)sensor_value*ADC_REF/1023; // Calculate real-time voltage
    float degrees = (voltage*FULL_ANGLE)/GROVE_VCC; // Calculate the angle of rotation of the knob
    Serial.println("The angle between the mark and the starting position:"); // Print string to serial port
    Serial.println(degrees); // Print the rotation angle value of the rotary potentiometer to the serial port
    delay(100);

    int brightness; // Define brightness variable
    brightness = map(degrees, 0, FULL_ANGLE, 0, 255); // Map the rotary potentiometer angle value to LED light brightness value and store it in the brightness variable
    analogWrite(LEDPIN, brightness); // Output brightness value to LED light
    delay(500);
}