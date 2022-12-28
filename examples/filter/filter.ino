/* This sketch shows how to filter signals */

// ---- Create servo object to generate PWM signals ---
#include <Servo.h>
Servo servo;

// ----------- Signal deadband and calibration --------
#include <PulseInput.h> 
volatile unsigned int input;        /* variable is required to capture signal */

#define BAND    12                  /* Deadband. Changes in signal within this band are ignored. 
                                       Large values result in a steadier signal, at cost of lower precision */
                               
PulseFilter <&input, BAND> filter;

// Simpler form:
//PulseFilter <&input> filter;     /* The filter defaults to a deadband of 4 if none is specified */

// ----------------------------------------------------

void setup() {
  Serial.begin(9600);
  
  // PWM output at pin 2
  servo.attach(2);   
  servo.writeMicroseconds(1000); // initial signal value     
  
  // assign variables to receive signals 
  attachPulseInput(8, input);
   
  // subtract initial average from input
  /*
  delay(1000);              // pause before reading values [required for proper calibration]
  filter.calibrate();       // comment to only filter signal
  */
}

void loop() {
  // generate variable signal:
  int target = analogRead(A0) + 1000;   // read potentiometer from A0
  servo.writeMicroseconds(target);
  
  // display comparison:
  Serial.print( "Raw: " ); 
  Serial.print( input );            
  
  Serial.print("\t Filter: ");
  Serial.print( filter.update() );
  Serial.println();
}
