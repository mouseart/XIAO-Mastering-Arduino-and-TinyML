/*
 * Use the serial monitor to view the knob potentiometer
 */
#define ROTARY_ANGLE_SENSOR A0//Define the rotary potentiometer interface A0
#define ADC_REF 3 //ADC reference voltage 3V
#define GROVE_VCC 3 //Reference voltage 3V
#define FULL_ANGLE 300 //The maximum rotation angle of the rotary potentiometer is 300°
 
void setup()
{
    Serial.begin(9600);//Initialize the serial port
    pinMode(ROTARY_ANGLE_SENSOR, INPUT);//Set the rotary potentiometer pin as an input
}
 
void loop()
{   
    float voltage;//Variable voltage is of floating-point type
    int sensorValue = analogRead(ROTARY_ANGLE_SENSOR);//Read the analog value at the rotary potentiometer pin
    voltage = (float)sensorValue*ADC_REF/1023;//Calculate real-time voltage
    float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;//Calculate the rotation angle of the knob
    Serial.println("The angle between the mark and the starting position:");//Print characters at the serial port
    Serial.println(degrees);//Print the rotation angle value of the rotary potentiometer at the serial port
    delay(100);
}
