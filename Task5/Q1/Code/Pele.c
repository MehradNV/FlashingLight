/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : Pele
Version : 
Date    : 1/6/2021
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

bit i =0;
int states[4] = {9 , 10 , 6 , 5};
int currentState=0;
int counter =0;
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{

    counter++;
    if(counter == 20){

        if(currentState < 4 && i ==0){

       PORTA =  states[currentState];
       currentState++;  
       
       i =1; 
       
       if(currentState == 4)
        {
         currentState = 0;

        }

    } else if(i ==1){

           PORTA = 0x00;
        i = 0;
        if(currentState == 4)
        {
         currentState = 0;

        }

        }


          counter=0;

        }

    TCNT0 = 6;



}

void main(void)
{

DDRA=0xff;
PORTA=0x00;

DDRC=0x00;
PINC=0x00;



TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0 = 6;
OCR0=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);


while (1)
      {
        if(PINC.2 == 0)
        {
              #asm("sei")


         // Global enable interrupts
       }

      }
}