#include "mbed.h"

//DigitalOut myled(LED1);
PwmOut speaker(p21);
DigitalIn switch1 (p5, PullDown);
DigitalIn switch2 (p6, PullDown);
DigitalIn switch3 (p7, PullDown);
DigitalIn switch4 (p8, PullDown);

PwmOut switch1LED (LED1);
PwmOut switch2LED (LED2);
PwmOut switch3LED (LED3);
PwmOut switch4LED (LED4);

float brightness = 1;
float fade = 0.1;
float freq1 = 1046;
float freq2 = 1175;
float freq3 = 1319;
float freq4 = 1397;
float duty = 0.1;
float dutyFade = 0.0100;


//DigitalOut switch1LED (

int main() {
    
    while(1) {
        
        //does nothing if no switches pressed
        while (switch1 == 0 && switch2 == 0 && switch3 == 0 && switch4 == 0) {
            //wait(0.1);
        }
        
        while (switch1 == 1 || switch2 == 1 || switch3 == 1 || switch4 == 1) {
            
        //if switch1 pressed
        if (switch1 == 1) {
            //LED and note hold as long as switch is held down
            while (switch1 == 1){
            switch1LED = brightness;
            speaker.write(1/freq1);
            speaker = 0.1;
            }
            
            //fades LED and note when switch is released
            for (int i = 20; i > 0; i--) {
            switch1LED.period(1/freq1);
            switch1LED = brightness;
            brightness = brightness - fade;
            wait(0.005);

            speaker.period(1/freq1);
            speaker = duty;
            duty = duty - dutyFade;
            wait(0.005);
            }
          
            //reset brightness
            brightness = 1;
            //reset duty cycle
            duty = 0.1;      
          }     
 
    
        //if switch2 pressed
        if (switch2 == 1) {
            //LED and note hold as long as switch is held down
            while (switch2 == 1){
            switch2LED = brightness;
            speaker.write(1/freq2);
            speaker = 0.1;
            }
            
            //fades LED and note when switch is released
            for (int i = 20; i > 0; i--) {
            switch2LED.period(1/freq2);
            switch2LED = brightness;
            brightness = brightness - fade;
            wait(0.005);

            speaker.period(1/freq2);
            speaker = duty;
            duty = duty - dutyFade;
            wait(0.005);
            }
          
            //reset brightness
            brightness = 1;
            //reset duty cycle
            duty = 0.1;      
          }
        

        //if switch3 pressed
        if (switch3 == 1) {
            //LED and note hold as long as switch is held down
            while (switch3 == 1){
            switch3LED = brightness;
            speaker.write(1/freq3);
            speaker = 0.1;
            }
            
            //fades LED and note when switch is released
            for (int i = 20; i > 0; i--) {
            switch3LED.period(1/freq3);
            switch3LED = brightness;
            brightness = brightness - fade;
            wait(0.005);

            speaker.period(1/freq3);
            speaker = duty;
            duty = duty - dutyFade;
            wait(0.005);
            }
          
            //reset brightness
            brightness = 1;
            //reset duty cycle
            duty = 0.1;      
          }
        


        //if switch4 pressed
        if (switch4 == 1) {
            //LED and note hold as long as switch is held down
            while (switch4 == 1){
            switch4LED = brightness;
            speaker.write(1/freq4);
            speaker = 0.1;
            }
            
            //fades LED and note when switch is released
            for (int i = 20; i > 0; i--) {
            switch4LED.period(1/freq4);
            switch4LED = brightness;
            brightness = brightness - fade;
            wait(0.005);

            speaker.period(1/freq4);
            speaker = duty;
            duty = duty - dutyFade;
            wait(0.005);
            }
          
            //reset brightness
            brightness = 1;
            //reset duty cycle
            duty = 0.1;      
          }
    
    
    
            wait(0.1);
            }
        //switch released
    }
}
