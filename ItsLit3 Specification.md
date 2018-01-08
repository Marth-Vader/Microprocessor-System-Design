ItsLit3 Specification

Objective: Implement a simple indoor/outdoor temperature monitor using mbed objects DigitalIn, AnalogIn, and BusOut. The LM35 is the indoor temperature sensor. The relationship between the LM35's Vout pin and its temperature is V = 0.500 + 0.010T. The MCP9700A is the outdoor sensor because it can measure colder temperatures. The relationship between the MCP9700A's Vout pin and its temperature is V = 0.500 + 0.010T. The mean average voltage from each temperature sensor is computed over 1000+ samples to prevent the value from fluctuating. The program should periodically read and display the temperatures from both sensors and display the nearest integer value on the 7-segment display in either Celsius or Fahrenheit, depending on the mode the user has selected. Display each digit for 0.5-1 seconds, then clear the display for 0.1 seconds, then show either 'C' or 'F' to indicate the scale and either 'i' or 'o' for either outdoor or indoor. Pressing the switch connected to p14 selects Celsius and pressing the switch connected to p15 selects Fahrenheit.


Setup: The LM35's +Vs pin is connected to the mbed's VOUT, Vout pin connected to the mbed's p17, and GND connected to the mbed's GND. The MCP9700A is connected to the mbed the same way as the LM35, except the Vout pin is connected to the mbed's p16. A pushbutton switch is connected between p14 and VOUT, and another one is connected between p15 and VOUT.

Each pin on the common cathode 7-segment LED display is connected to the mbed (with optional 220-ohm resistors) accordingly:
-pins 3,8 to GND
-pin 7 (seg a) to p5
-pin 6 (seg b) to p6
-pin 4 (seg c) to p7
-pin 2 (seg d) to p8
-pin 1 (seg e) to p9
-pin 9 (seg f) to p10
-pin 10 (seg g) to p11
-pin 5 (seg dp) to p12
