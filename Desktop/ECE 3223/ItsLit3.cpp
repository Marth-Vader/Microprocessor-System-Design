#include "mbed.h"

BusOut display(p5, p6, p7, p8, p9, p10, p11, p12);
AnalogIn LM35(p17);
AnalogIn MCP(p16);
DigitalIn celMode(p14, PullDown);
DigitalIn fareMode(p15, PullDown);

void showChar(char dispVal);
int tempOut = 0x3F;
int tempIn = 0x3F;
//temperature in C or F, 0 for C, 1 for F
int tempMode = 0;

int main()
{

    while(1) {

        //numerator of the ouside temperature values
        float tempOutNum = 0;
        //numerator of the inside temeprature values
        float tempInNum = 0;

        for (int i = 0; i < 1000; i++) {

            //calculate the numberator of the outside temperature
            tempInNum += (LM35.read() * 3.3 * 100);
            //calculate the numerator of the outside temperature
            tempOutNum += (((MCP.read() * 3.3 ) - 0.5 )* 100);

        }



        //divide by 1000 to get the average inside temperature
        tempIn = (int)(tempInNum / 1000);
        //divide by 1000 to get the average outside temperature
        tempOut = (int)(tempOutNum / 1000);



        //while in Celcius mode
        while (tempMode == 0) {

            //if temperature outside is negative then display the negative sign
            if (tempOut < 0) {
                showChar('-');
            }

            //display first digit of inside temperature
            showChar(tempIn / 10);
            wait(0.5);
            //display second digit of inside temperature
            showChar(tempIn % 10);
            wait(0.5);
            //display nothing for 0.1 seconds
            display = 0;
            wait(0.1);
            //display C for Celsius
            showChar('C');
            wait(0.5);
            //display i for indoor
            showChar('i');
            wait(0.5);
            
            
            //display first digit of outisde temperature
            showChar(tempOut / 10);
            wait(0.5);
            //display second digit of outside temperature
            showChar(tempOut % 10);
            wait(0.5);
            //display nothing for 0.1 seconds
            display = 0;
            wait(0.1);
            //display C for Celsius
            showChar('C');
            wait(0.5);
            //display i for indoor
            showChar('o');
            wait(0.5);



            //check if Farenheit switch is pressed
            if (fareMode == 1) {
                wait(0.5);
                //change to Fahrenheit mode if switch pressed
                tempMode = 1;
            }
            
            

        }




        while (tempMode == 1) {

            //display first digit of inside temperature
            showChar((((tempIn * 9) / 5) + 32) / 10);
            wait(0.5);
            //display second digit of inside temperature
            showChar((((tempIn * 9) / 5) + 32) % 10);
            wait(0.5);
            //wait before displaying F
            display = 0;
            wait(0.1);
            //display F for Fahrenheit
            showChar('F');
            wait(0.5);
            //display i for inside temperature
            showChar('i');
            wait(0.5);
            
            
            //display first digit of outside temperature
            showChar((((tempOut * 9) / 5) + 32) / 10);
            wait(0.5);
            //display second digit of outside temperature
            showChar((((tempOut * 9) / 5) + 32) % 10);
            wait(0.5);
            //wait before displaying F
            display = 0;
            wait(0.1);
            //display F for Fahrenheit
            showChar('F');
            wait(0.5);
            //display o for outside temperature
            showChar('o');
            wait(0.5);

            
            //check if Celsius switch is pressed
            if (celMode == 1) {
                wait(0.5);
                //change to Celsius mode if switch pressed
                tempMode = 0;
            }


        }
        
        
        
    }

}



//this function displays a character when called
void showChar(char dispVal)
{

    switch(dispVal) {
            //numbers
        case 0:
            display = 0x3F;
            break;
        case 1:
            display = 0x06;
            break;
        case 2:
            display = 0x5B;
            break;
        case 3:
            display = 0x4F;
            break;
        case 4:
            display = 0x66;
            break;
        case 5:
            display = 0x6D;
            break;
        case 6:
            display = 0x7D;
            break;
        case 7:
            display = 0x07;
            break;
        case 8:
            display = 0x7F;
            break;
        case 9:
            display = 0x6F;
            break;

            //letters
        case 'C':
            display = 0x39;
            break;
        case 'F':
            display = 0x71;
            break;
        case 'i':
            display = 0x10;
            break;
        case 'o':
            display = 0x5C;
            break;
        case '-':
            display = 0x40;
    }


}







