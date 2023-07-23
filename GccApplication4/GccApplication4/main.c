/*
 * GccApplication4.c
 *
 * Created: 04-10-2021 10.59.53 AM
 * Author : Sahil
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#define RS PC0 //register selection
#define EN PC1 //enable ip

void lcd_comm (char);
void lcd_data(char);
void lcd_init (void);


void LCD_String (char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)  //send each char of string till the NULL 
	{
		LCD_Char (str[i]);  //Call LCD data write 
	}
}


int main(void)
{
	lcd_init();
	LCD_String("ElectronicWINGS");	//Output Display
	LCD_Command(0xC0);		
	LCD_String("Hello World");	


	while(1)
	{
		
	}
}

void lcd_comm(char x){
	PORTD = x;
	PORTC &= ~(1<<RS);
	PORTC |= 1<<EN;
	_delay_ms(50);
	PORTC &= ~(1<<EN);
}

void lcd_data(char x){
	PORTD = x;
	PORTC |= 1<<RS;
	PORTC |= 1<<EN;
	_delay_ms(50);
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

