/*
 Happy Birthday Arduino
 */
const float c4 = 261.63;
const float d4 = 293.67;
const float e4 = 329.63; 
const float f4 = 349.23;
const float g4 = 392.00; 
const float a4 = 440.00; 
const float a4SH = 466.16; 
const float c5 = 523.25; 

int pinBuzzer = 3;
// Define the buzzer to pin 3, if you are using XIAO RP2040/XIAO ESP32, please change 3 to A3
void setup() {
  // Set the buzzer pin to output state:
  pinMode(pinBuzzer, OUTPUT);
}
 
void loop() {
  // The main code for playing the melody in a loop goes here
  // Play the first section
  firstSection();
  delay(600);

  // Play the second section
  secondSection();
  delay(400);

  // Play the third section
  thirdSection();
  delay(300);

  // Play the fourth section
  fourthSection();
  delay(1000);
}

// Function to play a note for a certain duration
void playNote(int note, int duration){
  // Play a note on the buzzer
  tone(pinBuzzer, note, duration);

  delay(duration);
  
  // Stop playing a note on the buzzer
  noTone(pinBuzzer);
}

// Play the first section
void firstSection(){
  playNote(c4,200);
  delay(100);
  playNote(c4,200);
  delay(100);
  playNote(d4, 450);
  delay(100);
  playNote(c4,330);
  delay(100);
  playNote(f4,380);
  delay(100);
  playNote(e4, 495);
}

// Play the second section
void secondSection(){
  playNote(c4, 200);
  delay(100);
  playNote(c4, 200);
  delay(100);
  playNote(d4, 450);
  delay(100);
  playNote(c4, 390);
  delay(100);
  playNote(g4, 400);
  delay(100);
  playNote(f4, 500);
}

// Play the third section
void thirdSection(){
  playNote(c4, 210);
  delay(130);
  playNote(c4, 210);
  delay(130);
  playNote(c5, 600);
  delay(120);
  playNote(a4, 550);
  delay(120);
  playNote(f4, 500);
  delay(120);
  playNote(e4, 500);
  delay(120);
  playNote(d4, 500);
}

// Play the fourth section
void fourthSection(){
  playNote(a4SH, 400);
  delay(100);
  playNote(a4SH, 400);
  delay(100);
  playNote(a4, 620);
  delay(200);
  playNote(f4, 400);
  delay(200);
  playNote(g4, 500);
  delay(100);
  playNote(f4, 800);
}
