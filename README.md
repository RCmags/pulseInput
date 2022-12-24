# PulseInput
This is a simple library for an interrupt based, non-blocking alternative to Arduino's [pulseIn](https://reference.arduino.cc/reference/cs/language/functions/advanced-io/pulsein/) function. It depends on the [PinChangeInterrupt](https://github.com/NicoHood/PinChangeInterrupt) library to measure the _on-time_ of digital signals. Consequently, this library is compatible with standard arduino boards (Uno, Nano, Mega, etc), ATTinys, and many other boards. Please see the documentation of PinChangeInterrupt to see if your board is supported.

# Example uses
This library is well suited to read the signals from a RC receiver, or the output of an ultrasonic distance sensor. Since it uses interrupts to measure the , one can read the signals while executing other code in the main loop. 


