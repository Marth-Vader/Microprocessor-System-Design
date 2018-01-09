ItsLit6 Specification

Objective: Implement a simple one-dimensional pong game using direct register access to control LEDs and read switches. Each player has 2 LEDs representing their points. To start the game, player 1 presses their switch to serve the ball (the blue LEDs on the mbed serves as the ball). There is a slight delay between each step of the ball so it does not travel too quickly. Player 2 presses their switch to hit the ball back, and the ball goes back and forth until a player fails to hit the ball back. A point is awarded and the player who missed serves the next ball. Whoever scores 2 points first wins. 

Setup: Player 1's switch will be connected between mbed's p5 and VOUT. PLayer 2's switch will be connected between p6 and VOUT. Player 1's green LEDs are connected in series with a 220-ohm resistor between p27 and GND and p28 and GND. Player 2's red LEDs are connected in series with a 220-ohm resistor between p29 and GND and p30 and GND.
