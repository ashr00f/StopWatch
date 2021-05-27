#include "SEGMENT.h"
#define F_CPU 8000000UL
#include <util/delay.h>
static u8 segment_nums[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};


void SEGMENT_Display_MX2(u8 n)    //n<100
{
	
	if(n<100)
	{
		DIO_writePin(EN1,HIGH);
		DIO_writePin(EN2,LOW);
		DIO_WritePort(SEGMANT_PORT,segment_nums[n%10]<<1);
		_delay_ms(1);
		DIO_writePin(EN2,HIGH);
		DIO_writePin(EN1,LOW);
		DIO_WritePort(SEGMANT_PORT,segment_nums[n/10]<<1);
		_delay_ms(1);
	}
	else
	{
		DIO_writePin(EN1,HIGH);
		DIO_writePin(EN2,LOW);
		DIO_WritePort(SEGMANT_PORT,0x3f<<1);
		_delay_ms(1);
		DIO_writePin(EN2,HIGH);
		DIO_writePin(EN1,LOW);
		DIO_WritePort(SEGMANT_PORT,0x3f<<1);
		_delay_ms(1);
	}
}



void SEGMENT_Display(u8 num)
{
	DIO_WritePort(SEGMANT_PORT,segment_nums[num]);
}
void SEGMENT_Display_BCD(u8 n)//n<100

{
	unsigned char small,big;
	if(n<=99)
	{
		small=n%10;
		big=n/10;
		//PORTC=small|(big<<4);
		DIO_WritePort(SEGMANT_PORT,small|(big<<4));
	}
	else
	{
		DIO_WritePort(SEGMANT_PORT,0);
	}
}
