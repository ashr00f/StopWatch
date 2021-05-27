
//#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "SEGMENT.h"



#define SETTIME 30 
#define PLAY_BUTTON PIND2
#define RESET_BUTTON PIND3
#define INCREMENT_BUTTON PIND2
#define DECREMENT_BUTTON PIND3
#define MODE_BUTTON PIND4

u8 t=SETTIME,update_t=SETTIME;

u8 play_flag=0,mode_flag=1;


int main(void)
{
	DIO_Init();
	
	u16 i;

    
    while (1) 
    {
		if(!DIO_ReadPin(MODE_BUTTON))
		{
			mode_flag^=1;
			while(!DIO_ReadPin(MODE_BUTTON));
		}
		if(mode_flag)
			
		{
	    	if(!DIO_ReadPin(PLAY_BUTTON))
		  {
			play_flag^=1;
			while(!DIO_ReadPin(PLAY_BUTTON));
		  }
	    	if(!DIO_ReadPin(RESET_BUTTON))
		  {
			t=update_t;
		  }
		
		  if(play_flag)
		   {
			   for(i=0;i<500;i++)
			  {
				SEGMENT_Display_MX2(t);
				i++;

				   if(!DIO_ReadPin(PLAY_BUTTON))
				  {
					//while(!DIO_ReadPin(PLAY_BUTTON));
					break;
				  }
				   if(!DIO_ReadPin(RESET_BUTTON))
				    break;
					if(!DIO_ReadPin(MODE_BUTTON))
					break;
			  }
			        t--;
			     if(255==t)
			     {
				     t=0;
			     }
		   }
		  else
		  {
			for(i=0;i<500;i++)
			{
				SEGMENT_Display_MX2(t);
				i++;
				if(!DIO_ReadPin(RESET_BUTTON))
				break;
				if(!DIO_ReadPin(PLAY_BUTTON))
				break;
				if(!DIO_ReadPin(MODE_BUTTON))
				break;
			}
			
		  }
			
		}
		else
		{
			
			if(!DIO_ReadPin(INCREMENT_BUTTON))
			{
				update_t++;
				while(!DIO_ReadPin(INCREMENT_BUTTON));
			}
			else if(!DIO_ReadPin(DECREMENT_BUTTON))
			{
				update_t--;
				while(!DIO_ReadPin(DECREMENT_BUTTON));
			}
				  else
				  {
					  for(i=0;i<500;i++)
					  {
						  SEGMENT_Display_MX2(update_t);
						  i++;
						  if(!DIO_ReadPin(INCREMENT_BUTTON))
						  break;
						  if(!DIO_ReadPin(DECREMENT_BUTTON))
						  break;
						  if(!DIO_ReadPin(MODE_BUTTON))
						  break;
						  
					  }
				  }
			
		}
		
		
    }
}

