/*
 * LCD Hello.c
 *
 * Created: 03-10-2021 12.34.01 PM
 * Author : Sahil
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#define RS PC0
#define EN PC1

void lcd_comm (char);
void lcd_data(char);
void lcd_init (void);


int main(void)
{
	lcd_init();
	lcd_data('H');
	lcd_data('E');
	lcd_data('L');
	lcd_data('L');
	lcd_data('O');

	lcd_comm(20);

	lcd_data('W');
	lcd_data('O');
	lcd_data('R');
	lcd_data('L');
	lcd_data('D');

	while(1)
	{
		
	}
}

void lcd_comm(char x){
	PORTD = x;
	PORTC &= ~(1<<RS);
	PORTC |= 1<<EN;
	_delay_ms(500);
	PORTC &= ~(1<<EN);
}

void lcd_data(char x){
	PORTD = x;
	PORTC |= 1<<RS;
	PORTC |= 1<<EN;
	_delay_ms(5);
	PORTC &= ~(1<<EN);
}

void lcd_init(void){
	DDRD = 0xFF;
	DDRC = 0x03;
	lcd_comm(0x38);
	lcd_comm(0x06);
	lcd_comm(0x0E);
	lcd_comm(0x01);
	lcd_comm(0x80);
}
