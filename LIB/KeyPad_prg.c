#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_private.h"
#include "DIO_interface.h"
#include "KeyPad_interface.h"
#include "KeyPad_cfg.h"


void KeyPad_VidInitialziation(u8 Copy_U8Port)
{

	DIO_VidSetPortDirection(Copy_U8Port, 0xF0); /*Pin 7 -> 4 Columns ************** Pin 3 -> 0 Rows   */
	DIO_VidSetPortValue(Copy_U8Port, 0xFF);
	
}

u8 KeyPad_U8GetPressedKey(u8 Copy_U8Port)
{
	u8 LOC_U8PressedKey=INTIAL_VALUE;
	u8 LOC_U8PressedFlag=HIGH;
	for(u8 c=0;c<COLUMNS;c++)
	{
		DIO_VidSetPinValue(Copy_U8Port,c+4,LOW);
		for(u8 r=0;r<ROWS;r++)
		{
			LOC_U8PressedFlag= DIO_U8GetPinValue(Copy_U8Port,r);
			if(LOW==LOC_U8PressedFlag)
			{	_delay_ms(25);

				while(LOW==LOC_U8PressedFlag)
				{
					LOC_U8PressedFlag=DIO_U8GetPinValue(Copy_U8Port,r);
				}	

				LOC_U8PressedKey=(ROWS*r)+c;
			}
			
			

		}
		
		DIO_VidSetPinValue(Copy_U8Port,c+COLUMNS,HIGH);
		
	}
	
return LOC_U8PressedKey;

}
