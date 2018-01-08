ItsLit2 Specification

Objective: Implement a simple musical instrument with pushbutton switches and a piezo transducer using mbed objects DigitalIn and PwmOut. A musical note is generated at maximum volume and lights up its corresponding LED at full brightness, and then both fade out over 0.1 seconds. The note will be at maximum volume when the PWM duty cycle is set to 50% and silent at 0% or 100%.

The corresponding pins, frequencies, and LEDs are:
p5 - 1046 Hz, LED1; 
p6 - 1175 Hz, LED2; 
p7 - 1319 Hz, LED3; 
p8 - 1397 Hz, LED4; 

Setup: Four active-high configuration connected to p5 through p8. Piezo transducer connected between p21 and GND.
