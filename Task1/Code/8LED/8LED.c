/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 8LED
Version : 
Date    : 12/10/2020
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
// Declare your global variables here

void main(void)
{
    DDRA = 0x00;
    DDRB = 0xFF;

while (1)
      {
      // Place your code here
      
      if(PINA.0 == 1){  
      
        for(int i = 1; i <= 2^7; i*2){
            PORTB = i;
            delay_ms(50);
        }
        
        for(int j = 128; i >= 1; i/2){
            PORTB = i;
            delay_ms(50);
        }
       }
      }
}
