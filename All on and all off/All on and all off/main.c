/*
 * All on and all off.c
 *
 * Created: 29-09-2021 10.51.19 PM
 * Author : Sahil
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   DDRB = 0b11111111;
   int B =0x00;
   while (1)
   {
	   //LED HIGH AND LOW
	   PORTB = B ;
	   _delay_ms(500);
	   PORTB=0xFF;
	   _delay_ms(1000);
	   
	   //RIGHT TO LEFT
	   PORTB = B;
	   _delay_ms(1000);
	   PORTB |= 0x80;
	   _delay_ms(1000);
	   PORTB |= 0x40;
	   _delay_ms(1000);
	   PORTB |= 0x20;
	   _delay_ms(1000);
	   PORTB |= 0x10;
	   _delay_ms(1000);
	   PORTB |= 0x8;
	   _delay_ms(1000);
	   PORTB |= 0x4;
	   _delay_ms(500);
	   PORTB |= 0x2;
	   _delay_ms(500);
	   PORTB |= 0x1;
	   _delay_ms(500);
	   
	   //Left to Right
	   PORTB &= B;
	   _delay_ms(1000);
	   PORTB=0x01;
	   _delay_ms(1000);
	   PORTB |= 0x03;
	   _delay_ms(1000);
	   PORTB |= 0x07;
	   _delay_ms(1000);
	   PORTB |= 0xF;
	   _delay_ms(1000);
	   PORTB |= 0x1F;
	   _delay_ms(1000);
	   PORTB |= 0x3F;
	   _delay_ms(1000);
	   PORTB |= 0x7F;
	   _delay_ms(1000);
	   PORTB |= 0xFF;
	   _delay_ms(1000);
	   
	   //Alternate
	   PORTB = B;
	   _delay_ms(500);
	   PORTB = 0x55;
	   _delay_ms(1000);
	   PORTB = 0xAA;
	   _delay_ms(1000);
	   PORTB = 0x55;
	   _delay_ms(1000);
	   PORTB = 0xAA;
	   _delay_ms(1000);
	   
	   //Center to End
	   PORTB= B;
	   _delay_ms(500);
	   PORTB=0x18;
	   _delay_ms(1000);
	   PORTB=0x18;
	   _delay_ms(1000);
	   PORTB=0x3C;
	   _delay_ms(1000);
	   PORTB=0x7E;
	   _delay_ms(1000);
	   PORTB=0xFF;
	   _delay_ms(1000);
	   
	   //Ascending
	   PORTB=B;
	   _delay_ms(500);
	   PORTB=0x01;
	   _delay_ms(1000);
	   PORTB=0x2;
	   _delay_ms(1000);
	   PORTB=0x4;
	   _delay_ms(1000);
	   PORTB=0x8;
	   _delay_ms(1000);
	   PORTB=0x10;
	   _delay_ms(1000);
	   PORTB=0x20;
	   _delay_ms(1000);
	   PORTB=0x40;
	   _delay_ms(1000);
	   PORTB=0x80;
	   _delay_ms(1000);
	   
	   //Descending
	   PORTB=B;
	   _delay_ms(500);
	   PORTB=0x80;
	   _delay_ms(1000);
	   PORTB=0x40;
	   _delay_ms(1000);
	   PORTB=0x20;
	   _delay_ms(1000);
	   PORTB=0x10;
	   _delay_ms(1000);
	   PORTB=0x8;
	   _delay_ms(1000);
	   PORTB=0x4;
	   _delay_ms(1000);
	   PORTB=0x2;
	   _delay_ms(1000);
	   PORTB=0x1;
	   _delay_ms(1000);
   }
}

