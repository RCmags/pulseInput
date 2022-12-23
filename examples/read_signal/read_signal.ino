/* Sketch to that shows how to read the pwm signal of a servo */

// Create servo objects to generate signals
#include <Servo.h>
Servo servo1;
Servo servo2;

// 1. Each signal must be read with an unsigned int
#include "PulseInput.h"   
volatile unsigned int input1;
volatile unsigned int input2;

void setup() {
  // 2. assign variables to receive signals 
  attachPulseInput(8, input1);  // pin 8 as INPUT_PULLUP
  attachPulseInput(9, input2);  // pin 9 as INPUT_PULLUP

  /* Generate pwm signals [in us] */
  servo1.attach(2);                 // Output at PIN 2
  servo1.writeMicroseconds(1500);   // ON time = 1500 us
  
  servo2.attach(3);                 // Output at PIN 3
  servo2.writeMicroseconds(2000);   // ON time = 2000 us
     
  Serial.begin(9600);

  /* To stop reading an already specified input, use this function: */
  //detachPulseInput(8);        // Stop reading input at pin 8
}

void loop() {  
  // 3. Read each signal
  Serial.print(input1);
  Serial.print(" ");
  Serial.print(input2);
  Serial.println();
}
