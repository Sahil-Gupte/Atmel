/*
 * LCD AND KEYPAD 2.c
 *
 * Created: 05-10-2021 11.53.07 AM
 * Author : Sahil
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define HIGH 0xFF
#define LOW 0x00
#define KDDR DDRA 
#define KPIN PINA 
#define KPORT PORTA 
#define L_DD DDRD 
#define L_CD DDRC
#define L_DP PORTD 
#define L_CP PORTC 
#define RS PORTC0 //Register Select Port which talks to Instr Reg or Data Reg of ST7066
#define RW PORTC1 //Read/Write Port. RW=0 is Write
#define EN PORTC2 //Enable signal pin. If this is low, LCD will ignore RS RW D0-7

//k is matrix of keypad, col & row is column and rows of keypad
unsigned char k[4][4]={ {'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};
unsigned char col,row;

void L_CMD(unsigned char cmd)
{
	L_DP=cmd;
	L_CP &= ~(1<<RS); //RS=0
	L_CP &= ~(1<<RW); //RW=0
	L_CP |= (1<<EN); //Enable LCD
	_delay_us(1);
	L_CP &= ~(1<<EN);
	_delay_ms(3);

}  //command to LCD

void L_Char(unsigned char char_d) //write
{
	L_DP = char_d;
	L_CP |= (1<<RS);
	L_CP &= ~(1<<RW);
	L_CP |= (1<<EN);
	_delay_us(1);
	L_CP &= ~(1<<EN);
	_delay_ms(1);
}

void L_init() //function to initialize or start the LCD
{
	L_CD = 0xFF; //make RS,RW,EN as OP. RW pin is GND when in WRITE, we can also just GND RW directly
	L_DD = 0xFF; //make D0-D7, data direction ports as OP
	_delay_ms(20); //delay because LCD needs >15ms when on >4.5V to set reset the busy flag from 1 to 0
	L_CMD(0x38); //Start in 8bit mode. 0x28 starts in 4bit mode.
	L_CMD(0x0C); //Cursor ON OFF
	L_CMD(0x06); //Increment cursor automatically
	L_CMD(0x01); //clr display
	L_CMD(0x80); //cursor at pos0
}

void L_string(char *str) //send string
{
	int i;
	for (i=0;str[i]!=0;i++)
	{
		L_Char(str[i]);
	}
}

void L_Pos(char row,char pos,char *str) //strings x & y pos
{
	if (row==0 && pos<16)
	L_CMD((pos & 0x0F)|0x80); //first row and pos, here 0x80 is pos0 or home
	else if (row==1 && pos<16)
	L_CMD((pos & 0x0F)|0xC0); //second row
	L_string(str);
}

void L_clr() //to clear screen
{
	L_CMD(0x01); //clear display command
	L_CMD(0x80); //cursor back to pos0/home

}

char keypressed()
{
	while(1)
	{
		KDDR = 0xF0; //keypad DDR
		PORTA = 0xFF; //Setting 1-4 pins of keypad in pull-up so they are high
		do
		{
			KPORT &= 0x0F;
			col = (KPIN & 0x0F); //find rowumn

		} while (col != 0x0F);

		do
		{
			do
			{
				_delay_ms(2);
				col = (KPIN & 0x0F);
			}while (col == 0x0F);

			_delay_ms(4);
			col = (KPIN & 0x0F);
		} while (col == 0x0F);

		KPORT = 0xEF; //ROW 1
		col=(KPIN & 0x0F);
		if(col != 0x0F)
		{
			row = 3;
			break;
		}

		KPORT=0xDF; //ROW2
		col=(KPIN & 0x0F);
		if (col != 0x0F)
		{
			row=2;
			break;
		}

		KPORT=0xBF; //ROW3
		col = (KPIN & 0x0F);
		if(col != 0x0F)
		{
			row=1;
			break;
		}

		KPORT=0x7F; //ROW4
		col=(KPIN & 0x0F);
		if(col != 0x0F)
		{
			row=0;
			break;
		}
	}

	if(col == 0x0E) //col4
	return (k[row][3]);
	else if(col == 0x0B) //col3
	return (k[row][1]);
	else if(col == 0x0D) //col2
	return(k[row][2]);
	else
	return(k[row][0]); //col1

} //function to find out the keypressed on the 4x4 matrix

int main(void)
{
	//unsigned char sign;
	//unsigned char *inp;

	L_init();
	L_CMD(0xC0);
	while (1)
	{
		//int i=0;
		
		//L_Pos(1,1,"Hello");
		L_Char(keypressed()); //pressed key to LCD CMND
        char press = keypressed();
		if(press == 'c')
		{
			L_clr ();
		}
	
	}
}

