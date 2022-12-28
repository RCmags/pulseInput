/* This sketch shows how to remove noise from a signal */

#include <PulseInput.h> 

#define BAND    12                  /* Deadband. Changes in signal within this band are ignored. 
                                       Large values result in a steadier signal, at cost of lower precision */

volatile unsigned int input;        /* variable is required to capture signal */
PulseFilter <&input, BAND> filter;

// Simpler form:
//PulseFilter <&input> filter;     /* The filter defaults to a deadband of 4 if none is specified */

// --------------- Generate PWM signal ----------------

#define OUTPUT_PIN    3       // PWM-capable pin
#define DUTY_CYCLE    125     // Initial PWM value

// ----------------------------------------------------

void setup() {
  Serial.begin(9600);
  
  // generate PWM signal
  analogWrite(OUTPUT_PIN, DUTY_CYCLE);       
  
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
  float target = analogRead(A0) * 255.0 / 1024.0;   // read potentiometer from A0
  analogWrite(OUTPUT_PIN, target);
  
  // display comparison:
  Serial.print( "Raw: " ); 
  Serial.print( input );            
  
  Serial.print("\t Filter: ");
  Serial.print( filter.update() );
  Serial.println();
}
