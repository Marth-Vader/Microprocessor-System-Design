#include "mbed.h"

//buttons 1 and 2 for player 1
InterruptIn p1b1(p25);
InterruptIn p1b2(p30);

//buttons 1 and 2 for player 2
InterruptIn p2b1(p11);
InterruptIn p2b2(p16);

//Timer
Timer timer;

//declare serial object
Serial pc(USBTX, USBRX);

//declare and initialize each player's steps to 0
int p1steps = 0;
int p2steps = 0;



//counts the steps for player 1
void player1steps() {
    p1steps++;
    }

//catches the rising edge of the second button pressed
//calls the function to count player 1's steps  
void player1() {
    wait(0.025);
    p1b2.rise(&player1steps);
    }

//counts the steps for player 2 
void player2steps() {
    p2steps++;
    }   

//catches the rising edge of the second button pressed
//calls the function to count player 2's steps   
void player2() {
    wait(0.025);
    p2b2.fall(&player2steps);
    }




int main() {
    
    pc.printf("\rWelcome. The race is aboout to begin.\r\n");
    //wait 4 seconds before starting the game countdown
    wait(4.0);
    pc.printf("\rOn your marks... \r\n");
    wait(3.0);
    pc.printf("Get set... \r\n");
    wait(2.0);
    pc.printf("GO!!! \r\n");
    
    //set the baudrate
    pc.baud(9600);
    
    //set player 2's buttons to pullUp
    p2b1.mode(PullUp);
    p2b2.mode(PullUp);

    while(1) {
        
    //start the timer
    timer.start();
        
    
    //call the player 1 and 2 functions to count steps for game
    //by catching the rising and falling edges
    p1b1.rise(&player1);
    p2b1.fall(&player2);
    

    //while either player has less than 40 steps, print 
    while ((p1steps < 40) && (p2steps < 40)) { 

    //print the number of steps for each player
    pc.printf("Player 1 Steps: %2d \r\n", p1steps);
    pc.printf("Player 2 Steps: %2d \r\n\n", p2steps);

    //wait 0.5 seconds so it doesn't print too fast
    wait(0.5);

    }
    
    //stop reading interrupts
    p1b1.rise(NULL);
    p2b1.fall(NULL);
    
    //stop the timer
    timer.stop();
    
    //compare the steps and determine the winner
    if (p1steps > p2steps) {
    pc.printf("Player 1 wins!!! \r\n\n");
        }
        
    else if (p2steps > p1steps) {
    pc.printf("Player 2 wins!!! \r\n\n");
    }
    
    
    //print the time elapsed
    pc.printf("Time: %.2f \r\n\n", timer.read());
    //leave the while loop and end the game
    break;
    }
    
    
    //after the game is over
    pc.printf("Reset the mBed to play again. \r\n");
    

}

