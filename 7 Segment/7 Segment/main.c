/*
 * 7 Segment.c
 *
 * Created: 30-09-2021 11.53.47 PM
 * Author : Sahil
 */ 
#define F_CPU 800000UL
#include <avr/io.h>
#include <util/delay.h>
 
int main(void)
{
	int dv[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	int i;
	DDRA=0x00;
	DDRD=0XFF;
	while(1)
	{    
		
		if(PINA==0x01)
		{
			for(i=0;i<=9;i++)
			{   
				PORTD=dv[i];
				_delay_ms(500);
			}
		}
	}
}

