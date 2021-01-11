/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : Pele2
Version : 
Date    : 1/12/2021
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

int states[4] = {9 , 10 , 6 , 5};
int currentState=0;
int i;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{


          TCNT0=6;

    PORTA = states[currentState];

    if(i>0) {
        if(currentState<3) {
            ++currentState;
        } else {
            currentState=0;
        }
    } else {
        if(currentState>0) {
            --currentState;
        } else {
            currentState=3;
        }
    }


}

void main(void)
{


    currentState = 0;
    i = 1;

DDRA=0xff;
PORTA=0x00;

DDRC=0x00;
PORTC=0x00;


TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;

TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);


#asm("sei")

while (1)
      {
          if(PINC.2==0) {
            i =1;

        }else{
            i =-1;
        }

      }
}