# PulseInput
This is a simple library for an interrupt based, non-blocking alternative to Arduino's [pulseIn](https://reference.arduino.cc/reference/cs/language/functions/advanced-io/pulsein/) function. 

# Example uses
This library is well suited to read the channels of a RC receiver or the output of an ultrasonic distance sensor. Given that it uses interrupts to measure the signals, one can read multiple signals without long delays in the main loop of a sketch.  

# How it works
Pin change interrupts are used to detect when a signal is rising or falling, and the _on-time_ of the signal is measured in microseconds. Therefore, this library is only suited to decode PWM-like signals, where the time of the pulse-width (on-time) determines the value of the signal.

![image](diagram.png)

# Dependencies
This library depends on the [PinChangeInterrupt](https://github.com/NicoHood/PinChangeInterrupt) library. As such, it is compatible with many arduinos (Uno, Nano, Mega, etc), digiSpark ATTiny boards, any many other boards. Please see the documentation of PinChangeInterrupt to see if your board is supported.

