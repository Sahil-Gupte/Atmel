/*
 * Timer 16.c
 *
 * Created: 06-10-2021 10.06.35 PM
 * Author : Sahil
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
char a;
int main(void)
{
	DDRD=0xFF;
	PORTD=0x00; 
	TIMSK=(1<<TOIE1); 
	TCCR1B=(1<<CS00); 
	sei();
	while(1)
	{
		
	}
}
ISR(TIMER1_OVF_vect)
{
	a++;
	if(a>10)
	{
		PORTD=~PORTD;
		a=0;
	}
}

