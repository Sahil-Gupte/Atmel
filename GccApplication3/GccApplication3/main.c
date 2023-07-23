/*
 * GccApplication3.c
 *
 * Created: 01-10-2021 7.10.06 PM
 * Author : Sahil
 */ 

#define F_CPU 1600000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#define op 0xFF
#define ip 0x00


int main(void)
{
	unsigned int seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x06F};
	unsigned int alp[]={0x77,0x7C,0x39,0x5E,0x79,0x71};
	DDRA= ip;
	DDRC= op;
	uint8_t i;
	while(1)
	{
		i=PINA;
	}
	
	if (i<9)
	{
		for (int num=0;num<=i;num++)
		{
			PORTC=alp[num];
		}
	}
	else
	{
		for(int num=0;num<i;num++)
		{
			PORTC=seg[num];
		}
	}
	
}

