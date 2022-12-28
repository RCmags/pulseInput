/* This sketch shows how to read a PWM signal */

// Each signal must be read with an volatile unsigned int
#include <PulseInput.h>   
volatile unsigned int input;    /* each signal requires a variable */

void setup() {
  Serial.begin(9600);
  
  // 2. assign variables to receive signal 
  attachPulseInput(8, input);  // pin 8 as INPUT_PULLUP

  /* Generate pwm signal */
  constexpr int   PIN        = 3;            // PWM capable pin
  constexpr int   ON_TIME    = 1000;         // Pulse width in microseconds
  constexpr float DUTY_CYCLE = ON_TIME * 255.0 / 2024.0;
  
  analogWrite(PIN, DUTY_CYCLE); 

  /* To stop reading an already specified input, use this function: */
  //detachPulseInput(8);        // Stop reading input at pin 8
}

void loop() {  
  // read signal [microseconds]
  Serial.println(input);
}
