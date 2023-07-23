/*
 * GccApplication2.c
 *
 * Created: 30-09-2021 11.04.04 PM
 * Author : Sahil
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC = 0x00; //Input
	DDRB = 0xFF; //Output
	while (1) 
    {
		PORTB = PINC;
    }
	return 0;
}


