/*
 * Led Blink PWM.c
 *
 * Created: 07-10-2021 11.11.39 AM
 * Author : Sahil
 */ 

#define F_CPU 16000000UL          
#include "avr/io.h"
#include <util/delay.h>

void PWM_set(){                                 
	DDRD |= (1<<PD7);                              
	TCCR2 |= (1<<WGM20)|(1<<WGM21);                
	TCCR2 |=(1<<COM21)|(1<<CS20)|(0<<CS21)|(0<<CS22);   
}

int main ()
{
	unsigned char duty;
	PWM_set();         
	while (1)
	{
		OCR2 = 255;
		/*
		for(duty=0; duty<200; duty++)   
		{
			OCR2=duty;    
			_delay_ms(10);
		}
		for(duty=0; duty>200; duty--)  
		{
			OCR2=duty;    
			_delay_ms(10);
		}
		*/
	}
}