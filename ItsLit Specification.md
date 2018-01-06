ItsLit Specification

Objective: Create a logic puzzle game with switches and LEDs using mbed objects DigitalIn and DigitalOut. There are three groups of LEDs: green (3), red (3), and blue (4). Each of the three switches will change the state of the LEDs in certain ways. Upon pressing a switch, the next LEDs corresponding to the switch will light up or turn off, depending on the current state. The state of the switch is not read more than once per 300ms. All the LEDs are initially off. The goal is to press the switches in an order that will simultaneously light up all the LEDs.

Setup: A BR (blue/red) switch is connected between p5 and GND. A GR (green/red) switch is connected between p10 and GND. A GB (green/blue) switch is connected between p30 and VOUT.
A separate green LED and 220-ohm resistor is connected in series between each p18-p20 and GND. A separate red LED and 220-ohm resistor is connected in series between each p21-p23 and VOUT.
