#include <PinChangeInterrupt.h>
#include <PulseFilter.h>

#ifndef PulseInput_h
#define PulseInput_h

// Read signal at given pin 
template<uint8_t PIN, volatile uint16_t* time_change>
void attachPulseInput() {
  
  // lamda function to update time
  auto interruptFunc = [] (void) {
    static uint32_t time_last = micros();
    if( digitalRead(PIN) ) {      // rising
      time_last = micros();
    } else {                      // falling
      *time_change = uint16_t(micros() - time_last);
    }
  };
  
  // set pin interrupt
  *time_change = 0;
  pinMode(PIN, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(PIN), interruptFunc, CHANGE);
}

// Stop pin from reading signal
void detachPulseInput(uint8_t PIN) {
  detachPCINT( digitalPinToPCINT(PIN) );
}

// Macro for function-like notation
#define attachPulseInput(pin, input)    attachPulseInput<pin, &input>()

#endif
