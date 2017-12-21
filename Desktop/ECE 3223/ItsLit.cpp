#include "mbed.h"


//blue LEDs
DigitalOut blueled1 (LED1);
DigitalOut blueled2 (LED2);
DigitalOut blueled3 (LED3);
DigitalOut blueled4 (LED4);

//red LEDs
//initialize all red LEDs to be off
DigitalOut redled1 (p21, 1);
DigitalOut redled2 (p22, 1);
DigitalOut redled3 (p23, 1);

//green LEDs
DigitalOut greenled1 (p18);
DigitalOut greenled2 (p19);
DigitalOut greenled3 (p20);

//switch inputs
DigitalIn switchBR (p5, PullUp);
DigitalIn switchGR (p10, PullUp);
DigitalIn switchGB (p30, PullDown);


int main() {

    //keep track of state of each LED set, initialize to 0, the first state
    int bluestate = 0;
    int redstate = 0;
    int greenstate = 0;

    
    while(1) {
        
        //does nothing if no switches pressed
        while (switchBR == 1 && switchGR == 1 && switchGB == 0) {
            wait(0.3);
        }
        
        //check which switch is pressed
        
        
        //if BR switch is pressed
        if (switchBR == 0) {
            
            //check red state
            if (redstate == 0) {
                redled1 = 0;
                }
            if (redstate == 1) {
                redled2 = 0;
                }
            if (redstate == 2) {
                redled3 = 0;
                }
            if (redstate == 3) {
                redled1 = 1;
                redled2 = 1;
                redled3 = 1;
                //reset red state 
                redstate = -1;
                }
            
            //check blue state
            if (bluestate == 0) {
                blueled1 = 1;
                }
            if (bluestate == 1) {
                blueled2 = 1;
                }
            if (bluestate == 2) {
                blueled3 = 1;
                }
            if (bluestate == 3) {
                blueled4 = 1;
                }
            if (bluestate == 4) {
                blueled1 = 0;
                blueled2 = 0;
                blueled3 = 0;
                blueled4 = 0;
                //reset blue state 
                bluestate = -1;
                }
            
            //increase red and blue state counter
            redstate = redstate + 1; 
            bluestate = bluestate + 1; 
            }
            
            
        //if GR switch is pressed
        else if (switchGR == 0) {
            
            //check red states
            if (redstate == 0) {
                redled1 = 0;
                }
            if (redstate == 1) {
                redled2 = 0;
                }
            if (redstate == 2) {
                redled3 = 0;
                }
            if (redstate == 3) {
                redled1 = 1;
                redled2 = 1;
                redled3 = 1;
                //reset red state 
                redstate = -1;
                }
            
            //check green state
            if (greenstate == 0) {
                greenled1 = 1;
                }
            if (greenstate == 1) {
                greenled2 = 1;
                }
            if (greenstate == 2) {
                greenled3 = 1;
                }
            if (greenstate == 3) {
                greenled1 = 0;
                greenled2 = 0;
                greenled3 = 0;
                //reset green state
                greenstate = -1;
                }
         
            //increase red and green state counter
            redstate = redstate + 1; 
            greenstate = greenstate + 1;
            }
            
            
        //if GB switch is pressed
        else if (switchGB == 1) {
            switchGB == 1;
            
            //check green state
            if (greenstate == 0) {
                greenled1 = 1;
                }
            if (greenstate == 1) {
                greenled2 = 1;
                }
            if (greenstate == 2) {
                greenled3 = 1;
                }
            if (greenstate == 3) {
                greenled1 = 0;
                greenled2 = 0;
                greenled3 = 0;
                //reset green state
                greenstate = -1;
                }
            
            //check blue state
            if (bluestate == 0) {
                blueled1 = 1;
                }
            if (bluestate == 1) {
                blueled2 = 1;
                }
            if (bluestate == 2) {
                blueled3 = 1;
                }
            if (bluestate == 3) {
                blueled4 = 1;
                }
            if (bluestate == 4) {
                blueled1 = 0;
                blueled2 = 0;
                blueled3 = 0;
                blueled4 = 0;
                //reset blue state 
                bluestate = -1;
                }
              
            //increase green and blue state counter  
            greenstate = greenstate + 1; 
            bluestate = bluestate + 1;
            }
        
        
        //switch pressed
        while (switchBR == 0 || switchGR == 0 || switchGB == 1) {
            wait(0.3);
            }
        //switch released
        
        }
 
}
