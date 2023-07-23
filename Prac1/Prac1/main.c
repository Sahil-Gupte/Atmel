/*
 * Prac1.c
 *
 * Created: 29-09-2021 5.16.46 PM
 * Author : Sahil 
 */ 
#define F_CPU 800000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0b00001000;
	
    while (1) 
    {
		PORTB = 0b00001000;
		_delay_ms (1000);
		PORTB = 0b00000000;
		_delay_ms (1000);
    }
}

