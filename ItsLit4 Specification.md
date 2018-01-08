ItsLit4 Specification

Objective: Implement a virtual running game using mbed objects InterruptIn, Timer, and Serial. Two players each have a pair of switches to control their character running. Players will race to see who can get to the finish line (get to 40 steps) in the least amount of time. Players need to alternate between their switches to advance by a step. The program should initially display a message to let the players know the race is starting. At least once per second, display the position of the players (how many steps each player has taken). The first player to reach 40 steps is the winner. Once there is a winner, the program should display a message identifying the winner and the time elapsed with 2 decimal places. There should be at least 25ms between the alternate switch presses for a step to be counted.



Setup: Player 1's switches are connected between p30 and VOUT and between p25 and VOUT. Player 2's switches are connected between p11 and GND and between p16 and GND. The serial interface should be configured for 9600 bits/second, 8 bits, no parity, and 1 stop bit. 
