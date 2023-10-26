#include <Servo.h>// Declare the use of the servo library
#define ROTARY_ANGLE_SENSOR A0 // Define the rotary potentiometer pin as A0
#define ADC_REF 3 // ADC reference voltage is 3V
#define GROVE_VCC 3 // GROVE module reference voltage is 3V
#define FULL_ANGLE 300 // The maximum rotation angle of the rotary potentiometer is 300°
Servo myservo;  // Create a myservo object to control the servo
int pos = 0; // Variable to store the rotation angle of the servo

void setup() {
    Serial.begin(9600);// Initialize the serial port
    pinMode(ROTARY_ANGLE_SENSOR, INPUT);// Set the rotary potentiometer pin as input
    myservo.attach(5);  // The myservo signal is transmitted through pin 5, if you are using XIAO RP2040/XIAO ESP32, please modify 5 to D5
}

void loop() {
    float voltage;// Set voltage as a floating point
    int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);// Read the analog value at the rotary potentiometer pin
    voltage = (float)sensor_value * ADC_REF / 1023;// Real-time voltage is the read analog value multiplied by the reference voltage divided by 1023
    float degrees = (voltage * FULL_ANGLE) / GROVE_VCC;// The rotation angle of the knob is the real-time voltage multiplied by the maximum rotation angle of the rotary potentiometer divided by the voltage value of the GROVE module interface
    Serial.println("The angle between the mark and the starting position:");// Print characters on the serial port
    Serial.println(degrees);// Print the rotation angle value of the rotary potentiometer on the serial port
    delay(50);
    myservo.write(degrees); // Write the rotation angle value of the rotary potentiometer into the servo
}