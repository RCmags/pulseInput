/* This sketch shows how to read PWM signals for servos */

// Create servo objects to generate signals
#include <Servo.h>
Servo servo;

// 1. Each signal must be read with an volatile unsigned int
#include <PulseInput.h>   
volatile unsigned int input;    /* each signal requires a variable - MUST be volatile unsigned int */

void setup() {
  // 2. assign variables to receive signal 
  attachPulseInput(8, input);  // pin 8 as INPUT_PULLUP

  /* Generate pwm signals [in us] */
  servo.attach(2);                 // Output at PIN 2
  servo.writeMicroseconds(1500);   // ON time = 1500 us
     
  Serial.begin(9600);

  /* To stop reading an already specified input, use this function: */
  //detachPulseInput(8);        // Stop reading input at pin 8
}

void loop() {  
  // read signal variable
  Serial.println(input);
}
