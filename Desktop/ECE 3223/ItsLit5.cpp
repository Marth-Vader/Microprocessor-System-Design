#include "mbed.h"
#include "cmath"
#include "cstdlib"
SPI spi(p11, p12, p13); // mosi, miso, sclk

DigitalOut ss1(p14); //chip select for 74HC595
DigitalOut ss2(p15); //chip select for 74HC165


//input array variable
//all buttons start off
int input[] = {0, 0, 0, 0, 0};
//output array variable
int output[] = {0, 0, 0, 0, 0};


float gameTime;
int round;


//declare serial object
Serial pc(USBTX, USBRX);

//function to display letter
void displayLetter(int letter);
//function to determine the time between letter displays
void detTime();
//display the round
void displayRound(int round);



int main()
{
    //go for 10 rounds unless broken out of
    for(round = 1; round < 10; round++) {

        //call function to determine the time;
        detTime();

        //select the 595 chip
        spi.format(8,0);

        //for 5 spots in the output array (randomly generated)
        for (int i = 0; i < 5; i++) {

            //turn on the chip
            ss1 = 0;

            //store the random letter value in the output array
            output[i] = (rand() % 4 + 0);

            //display randoom letter
            displayLetter(output[i]);

            //wait between display
            wait(gameTime);

            //turn off the display
            spi.write(0x00);


            //pc.printf("Letter value is %d\r\n", output[i]);

            //turn off the 595 chip
            ss1 = 1;

        }

        //blank the display
        ss1 = 0;
        spi.write(0);
        ss1 = 1;



        //select the 165 chip
        spi.format(8,2);


        for (int j = 0; j < 5; j++) {

            //turn on the 165 chip
            ss2 = 1;

            //assign the input in the current position of the array
            //value corresponding to button pressed
            input[j] = spi.write(0);

            //turn off the 165 chip
            ss2 = 0;

            //if no buttons are being pressed then do nothing
            while (input[j] == 0) {
                ss2 = 1;
                input[j] = spi.write(0);
                wait(.1);
                ss2 = 0;
            }

            //pc.printf("Button value is %d\n", input[j]);
            //if a button is pressed

            int power;
            //if button A was pressed and the value in the position is
            //the value associated with A (0)
            if ((input[j] == 1)) {
                //display A
                displayLetter(0);
                power = 0;
            }

            //if button b was pressed and the value in the position is
            //the value associated with b (1)
            if ((input[j] == 2)) {
                //display b
                displayLetter(1);
                power = 1;
            }

            //if button c was pressed and the value in the position is
            //the value associated with c (2)
            if ((input[j] == 4)) {
                //display c
                displayLetter(2);
                power = 2;
            }

            //if button d was pressed and the value in the position is
            //the value associated with d (3)
            if ((input[j] == 8)) {
                //display d
                displayLetter(3);
                power = 3;
            }

            //pc.printf("Check value is %d\n", check);


            //check if the correct button was presed
            if (output[j] == power) {
                //if the button pressed matches
                //then do nothing
                //wait so the button doesnt read too fast if held down
                wait(.65);
            }


            //if incorrect
            if (output[j] != power) {
                //call the displayRound function to tell the user what round
                //they failed in
                displayRound(round);
                //exit the program
                exit;
            }

            //reset the power
            power = NULL;


        }
        
        //clear the display before the next round
        spi.format(8,0);
        ss1 = 0;
        spi.write(0);
        ss1 = 1;


    }


}



//function to display character
void displayLetter(int letter)
{

    switch(letter) {

        case 0:

            spi.format(8,0);
            ss1 = 0;
            spi.write(0xEE);
            ss1 = 1;
            break;


        case 1:

            spi.format(8,0);
            ss1 = 0;
            spi.write(0x3E);
            ss1 = 1;
            break;


        case 2:

            spi.format(8,0);
            ss1 = 0;
            spi.write(0x9C);
            ss1 = 1;
            break;


        case 3:

            spi.format(8,0);
            ss1 = 0;
            spi.write(0x7A);
            ss1 = 1;
            break;


    }
}




void displayRound(int round)
{

    switch(round) {

        case 1:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0x60);
            ss1 = 1;
            break;

        case 2:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0xDA);
            ss1 = 1;
            break;

        case 3:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0xF2);
            ss1 = 1;
            break;

        case 4:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0x66);
            ss1 = 1;
            break;

        case 5:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0xB6);
            ss1 = 1;
            break;

        case 6:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0xBE);
            ss1 = 1;
            break;

        case 7:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0xE0);
            ss1 = 1;
            break;

        case 8:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0xFE);
            ss1 = 1;
            break;

        case 9:
            spi.format(8,0);
            ss1 = 0;
            spi.write(0xE6);
            ss1 = 1;
            break;

    }

}
//function to determine the time based on the round
void detTime()
{
    //rates are  75% of the previous round
    if (round == 1) {
        gameTime = 1;
    }
    if (round == 2) {
        gameTime = 0.75;
    }
    if (round == 3) {
        gameTime = 0.5625;
    }
    if (round == 4) {
        gameTime = 0.421875;
    }
    if (round == 5) {
        gameTime = 0.31640625;
    }
    if (round == 6) {
        gameTime = 0.2373046875;
    }
    if (round == 7) {
        gameTime = 0.177978515625;
    }
    if (round == 8) {
        gameTime = 0.133483886719;
    }
    if (round == 9) {
        gameTime = 0.100112915039;
    }
}





//create function to blank the display
//turn on the slave (0)
//spi.write(0x0);
//wait
//turn off the slave(1)


//opposite for the other one

//turn 595 on
//display letter
//output value
//turn off
//leave chip off after displaying sequence

//need a time variable for each round

//spi.format(0,0);
//set the frequency 1000000
//formatting is for bit shifting


//spi.format(8,2);
//while none of the buttons are pressed
//turn on the 165 chip
//byte = spi.write(0);
//then turn off the chip

//associate each input with each output in the order they came in

//keep the value and button that was pressed

//reformat
//read from 165 then write to 595 what button was pressed



//if output and input match then do nothing
//else tell the user they missed
//tell them what round they fuck up in



