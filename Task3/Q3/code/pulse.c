/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : pulse
Version : 
Date    : 12/29/2020
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
#include <alcd.h>
#include <stdio.h>

// Declare your global variables here
int counter, turn;
unsigned int ending_edge, starting_edge, clocks, period_out;
char message[16];

interrupt [TIM1_OVF] void timer1_ovf_isr(void){
     counter++;
}

interrupt [TIM1_CAPT] void timer1_capt_isr(void){
    
    if(turn == 0)
        turn = 1;
    
    if(turn == 1){
        starting_edge = 256 * ICR1H + ICR1L; 
        turn = 2; 
    }
    
    if(turn == 2){
        ending_edge = 256 * ICR1H + ICR1L + counter * 65536;
        clocks = ending_edge - starting_edge;
    
    period_out = 8000000/clocks;
    
    sprintf(message,"%d Hz", period_out); 
    lcd_puts(message); 
    
    
    turn = 3;
    }   
    
    
    
}


void main(void)
{
// Declare your local variables here
turn = 0;
counter = 0;
TCCR1A = 0;
TCCR1B = 0xC2;
TIMSK = 0x24;
lcd_init(20);
lcd_gotoxy(0,0);
#asm("sei")



while (1)
      {
      // Place your code here

      }
}

