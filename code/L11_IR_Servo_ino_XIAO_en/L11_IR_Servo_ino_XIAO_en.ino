#include <IRremote.h>
#include <Servo.h>

Servo myservo; // Create a servo object myservo to control the servo
int RECV_PIN = 7; // The infrared receiver is connected to pin 7. If you are using XIAO RP2040/XIAO ESP32, please change 7 to A0
IRrecv irrecv(RECV_PIN); // Define an IRrecv object to receive infrared signals
decode_results results; // Decoding results are placed in results

int pos = 90; // Define pos as 90°

void setup()
{
    Serial.begin(9600);
    Serial.println("Enabling IRin");  
    irrecv.enableIRIn(); 
    myservo.attach(5); // Connect the servo on pin 5 to myservo. If you are using XIAO RP2040/XIAO ESP32, please change 5 to D5
}

// Note: Left 16712445 Right 16761405, please replace with the key values read from your own remote control
void loop() {
    if (irrecv.decode(&results)) {  // If decoding is successful, a set of infrared signals is received
        if (results.value == 16761405) {  // If the received signal is 16761405 (right key)
            for (pos; pos <= 89; pos += 1) { // Then the servo is incremented from 0° to 90° in sequence
                myservo.write(pos);              // Write the rotation angle value to the servo pin
                delay(40);
                // The following is to interrupt the above instruction and exit the loop
                if (irrecv.decode(&results)) {  
                    irrecv.resume();
                    if (results.value == 16712445)  
                        break;
                }
            }
        }

        if (results.value == 16712445) {    // If the received signal is 16712445 (left key)
            for (pos; pos >= 1; pos -= 1) { // Then the servo is decremented from 90° to 0° in sequence
                myservo.write(pos);              // Write the rotation angle value to the servo pin
                delay(40);                       
                // The following is to interrupt the above instruction and exit the loop
                if (irrecv.decode(&results)) {
                    irrecv.resume();
                    if (results.value == 16761405)
                        break;
                }
            }
        }
        // Display hexadecimal and octal codes in the serial port
        Serial.println(pos);
        Serial.println(results.value, HEX);
        Serial.println(results.value);
        irrecv.resume();                    

    }
    delay(100);
}