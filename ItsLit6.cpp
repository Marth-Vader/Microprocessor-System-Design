#include "mbed.h"

// Registers for port 0
#define FIO0DIR (*(volatile unsigned int *)0x2009c000)
#define FIO0PIN (*(volatile unsigned int *)0x2009c014)
#define FIO0SET (*(volatile unsigned int *)0x2009c018)
#define FIO0CLR (*(volatile unsigned int *)0x2009c01C)

// Registers for port 1
#define FIO1DIR (*(volatile unsigned int *)0x2009c020)
#define FIO1PIN (*(volatile unsigned int *)0x2009c034)
#define FIO1SET (*(volatile unsigned int *)0x2009c038)
#define FIO1CLR (*(volatile unsigned int *)0x2009c03C)

// pinmodes for port 0 and port 1
#define PINMODE0 (*(volatile unsigned int *)0x4002c040)
#define PINMODE1 (*(volatile unsigned int *)0x4002c044)

//how fast the "ball" moves
float delay = 0.3;


void player2to1()
{

    //if player 2's pushbutton is pressed
    if (((FIO0PIN>>8) & 1) == 1) {

        //turn on LED4
        FIO1PIN |= (1<<23);
        //wait
        wait(delay);
        //turn off LED4
        FIO1PIN &= ~(1<<23);
        //wait
        wait(delay);
        //turn on LED3
        FIO1PIN |= (1<<21);
        //wait
        wait(delay);
        //turn off LED3
        FIO1PIN &= ~(1<<21);
        //wait
        wait(delay);
        //turn off LED2
        FIO1PIN |= (1<<20);
        //wait
        wait(delay);
        //turn off LED2
        FIO1PIN &= ~(1<<20);
        //wait
        wait(delay);
        //turn on LED1
        FIO1PIN |= (1<<18);

        //if the ball is hit back by player 1 before LED1 turns off
        if (((FIO0PIN>>9) & 1) == 1) {

//          //if player 1's pushbutton is pressed
            if (((FIO0PIN>>9) & 1) == 1) {

                //turn on LED1
                FIO1PIN |= (1<<18);
                //wait
                wait(delay);
                //turn off LED1
                FIO1PIN &= ~(1<<18);
                //wait
                wait(delay);
                //turn on LED2
                FIO1PIN |= (1<<20);
                //wait
                wait(delay);
                //turn off LED2
                FIO1PIN &= ~(1<<20);
                //wait
                wait(delay);
                //turn off LED3
                FIO1PIN |= (1<<21);
                //wait
                wait(delay);
                //turn off LED3
                FIO1PIN &= ~(1<<21);
                //wait
                wait(delay);
                //turn on LED4
                FIO1PIN |= (1<<23);

                //if the ball is hit back by player 2 before LED4 turns off
                if (((FIO0PIN>>8) & 1) == 1) {

                    player2to1();

                }


                else {

                    //wait
                    wait(delay);
                    //turn off LED4
                    FIO1PIN &= ~(1<<18);
                    //if ball reaches here
                    //then player 1 scores
                    //turn on green LED
                    //if first green LED off
                    if ((((FIO0PIN>>10) & 1) == 0)) {
                        //turn on first green LED
                        FIO0PIN |= (1<<10);
                    }

                    else {
                        //turn on the second green LED
                        FIO0PIN |= (1<<11);
                    }

                }



            }

        }

        else {
            //wait
            wait(delay);
            //turn off LED4
            FIO1PIN &= ~(1<<18);
            //if ball reaches here
            //then player 2 scores
            //turn on red LED

            //if first red LED off
            if ((((FIO0PIN>>4) & 1) == 0)) {
                //turn on first red LED
                FIO0PIN |= (1<<4);
            }

            else {
                //turn on the second red LED
                FIO0PIN |= (1<<5);
            }
        }

    }
}



void player1serve()
{

    //if player 1's pushbutton is pressed
    if (((FIO0PIN>>9) & 1) == 1) {

        //turn on LED1
        FIO1PIN |= (1<<18);
        //wait
        wait(delay);
        //turn off LED1
        FIO1PIN &= ~(1<<18);
        //wait
        wait(delay);
        //turn on LED2
        FIO1PIN |= (1<<20);
        //wait
        wait(delay);
        //turn off LED2
        FIO1PIN &= ~(1<<20);
        //wait
        wait(delay);
        //turn off LED3
        FIO1PIN |= (1<<21);
        //wait
        wait(delay);
        //turn off LED3
        FIO1PIN &= ~(1<<21);
        //wait
        wait(delay);
        //turn on LED4
        FIO1PIN |= (1<<23);

        //if the ball is hit back by player 2 before LED4 turns off
        if (((FIO0PIN>>8) & 1) == 1) {
            //call the function that moves the ball from player 2 to player 1
            player2to1();

        }


        else {
            //wait
            wait(delay);
            //turn off LED4
            FIO1PIN &= ~(1<<23);
            //if ball reaches here
            //then player 1 scores
            //turn on green LED

            //if first green LED off
            if ((((FIO0PIN>>10) & 1) == 0)) {
                //turn on second green LED
                FIO0PIN |= (1<<10);
            }

            else {
                //turn on the second green LED
                FIO0PIN |= (1<<11);
            }
        }



    }


}




int main()
{

    //at the start of the game, both players have 0 points
    //all red and green LEDs are off
    while(1) {

        //configure pushbutton switches to be inputs, forces PullDown
        PINMODE0 |= (1<<19) | (1<<18) | (1<<17) | (1<<16);
        FIO0DIR &= ~(1<<19) & ~(1<<18) & ~(1<<17) & ~(1<<16);

        //configure LEDs on mbed as outputs
        FIO1DIR |= (1<<18) | (1<<20) | (1<<21) | (1<<23);
        //turn all LEDS off
        FIO1PIN &= ~(1<<18) & ~(1<<20) & ~(1<<21) & ~(1<<23);

        //configure score LEDs as outputs
        FIO0DIR |= (1<<4) | (1<<5) | (1<<10) | (1<<11);
        //turn all LEDS off
        FIO1PIN &= ~(1<<4) & ~(1<<5) & ~(1<<10) & ~(1<<11);

        //turn all score LEDS on to test
        //FIO0PIN |= (1<<4) | (1<<5) | (1<<10) | (1<<11);


        wait(.2);

        //if none of the score LEDs are on
        //let player 1 serve
        while ((((FIO0PIN>>4) & 1) == 0) & (((FIO0PIN>>5) & 1) == 0) & (((FIO0PIN>>10) & 1) == 0) & (((FIO0PIN>>11) & 1) == 0)) {

            player1serve();

        }



        //if player 1 scores then player 2 serves
        if ((((FIO0PIN>>4) & 1) == 0) & (((FIO0PIN>>5) & 1) == 0) & (((FIO0PIN>>10) & 1) == 1) & (((FIO0PIN>>11) & 1) == 0)) {

            player2to1();

            //if player 2 scores then player 1 serves
            while ((((FIO0PIN>>4) & 1) == 1) & (((FIO0PIN>>5) & 1) == 0) & (((FIO0PIN>>10) & 1) == 1) & (((FIO0PIN>>11) & 1) == 0)) {

                player1serve();


            }

            //if player 1 scores then player 2 serves
            while ((((FIO0PIN>>4) & 1) == 1) & (((FIO0PIN>>5) & 1) == 0) & (((FIO0PIN>>10) & 1) == 1 ) & (((FIO0PIN>>11) & 1) == 0)) {

                player1serve();

            }

        }




        //if player 2 scores then player 1 serves
        if ((((FIO0PIN>>4) & 1) == 1) & (((FIO0PIN>>5) & 1) == 0) & (((FIO0PIN>>10) & 1) == 0) & (((FIO0PIN>>11) & 1) == 0)) {

            player1serve();

            //if player 2 scores then player 1 serves
            while ((((FIO0PIN>>4) & 1) == 1) & (((FIO0PIN>>5) & 1) == 0) & (((FIO0PIN>>10) & 1) == 1) & (((FIO0PIN>>11) & 1) == 0)) {

                player2to1();

            }


            //if player 1 scores then player 2 serves
            while ((((FIO0PIN>>4) & 1) == 1) & (((FIO0PIN>>5) & 1) == 0) & (((FIO0PIN>>10) & 1) == 1) & (((FIO0PIN>>11) & 1) == 0)) {

                player1serve();

            }

        }



        //at this point someone has already scored two points
        //reset the mbed to play again



    }

}
