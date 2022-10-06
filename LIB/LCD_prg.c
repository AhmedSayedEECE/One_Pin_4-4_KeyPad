#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "LCD_interface.h"
#include "LCD_cfg.h"
#include "DIO_interface.h"
#include "KeyPad_interface.h"
#include "KeyPad_cfg.h"
#define LOW 0
#define HIGH 1
void LCD_VidInitialziation(void)
{
		DIO_VidSetPortDirection(DATA_PORT,0b11111111);
		DIO_VidSetPinDirection(CTRL_PORT,RS,1);
		DIO_VidSetPinDirection(CTRL_PORT,RW,1);
		DIO_VidSetPinDirection(CTRL_PORT,EN,1);
		_delay_ms(35);
		LCD_VidSendCommand(FUN_SET);
		_delay_ms(1);
		LCD_VidSendCommand(DISPLAY_ON_OFF);
		_delay_ms(1);
		LCD_VidSendCommand(LCD_CLR);
		_delay_ms(2);




}
void LCD_VidFourBitModeInit(void)
{
	DIO_VidSetPortDirection(DATA_PORT,0xFF);
	_delay_ms(20);		/* LCD Power ON delay always >15ms */
	LCD_VidSendCommand(0x33);
	LCD_VidSendCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_VidSendCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_VidSendCommand(0x0c);	/* Display on cursor off */
	LCD_VidSendCommand(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_VidSendCommand(0x01);	/* Clear display screen */
}

void LCD_VidSelectCell (u8 Copy_U8Row,u8 Copy_U8Column)
{
	if (Copy_U8Column>=0 && Copy_U8Column<16)
	{
	    switch(Copy_U8Row)
	    {
		    case 0:
		    	LCD_VidSendCommand(Copy_U8Column+128);
		    break;
		    case 1:
		    	LCD_VidSendCommand(Copy_U8Column+192);
		    break;
		    default:
		    break;
	    }
	}
}

void LCD_VidSendCommand(u8 Copy_U8Command)
{
	
	
		DIO_VidSetPinValue(CTRL_PORT, RS, LOW);
		DIO_VidSetPinValue(CTRL_PORT, RW, LOW);
		DIO_VidSetPortValue(DATA_PORT, Copy_U8Command);
		DIO_VidSetPinValue(CTRL_PORT, EN, HIGH);
		_delay_ms(1);
		DIO_VidSetPinValue(CTRL_PORT, EN, LOW);
		_delay_ms(2);

	}
void LCD_VidSendData(u8 Copy_U8Data)
{
	DIO_VidSetPinValue(CTRL_PORT, RS, HIGH);
	DIO_VidSetPinValue(CTRL_PORT, RW, LOW);
	DIO_VidSetPortValue(DATA_PORT, Copy_U8Data);
	DIO_VidSetPinValue(CTRL_PORT, EN, HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(CTRL_PORT, EN, LOW);
	_delay_ms(2);
	
	
	
}


void LCD_VidSendString(u8* Copy_U8Data)
{
	u8* ptr=Copy_U8Data;
for(u8 i=0;ptr[i]!='\0';i++)
{
	LCD_VidSendData(*(ptr+i));
	}
}

void LCD_VidSendVar(s32 Copy_U8Data)
{ s32 LOC_U32Temp=Copy_U8Data;
  u8 LOC_U8arr[10];
  u8 i=0,NegativeFlag=0;
  if(LOC_U32Temp<0)
  {
	  NegativeFlag=1;
	  LOC_U32Temp=LOC_U32Temp*-1;
  }
  while(LOC_U32Temp)
  {

	  LOC_U8arr[i]=(LOC_U32Temp%10);
	  LOC_U32Temp=LOC_U32Temp/10;
i++;
  }
while(i>0)
{i--;
if(NegativeFlag==1)
{
	LCD_VidSendData('-');
	NegativeFlag=0;
}
	  LCD_VidSendData(LOC_U8arr[i]+'0');

  }
	}
void LCD_VidShiftDisplay(u8* Copy_U8Data)
{
	u8* ptr=Copy_U8Data;
	u8  WordCounter;
	u8  RowCounter=0;
	u8 ColumnsCounter=0;
	u8 ShiftCounter=0;
	for(WordCounter=0;ptr[WordCounter]!='\0';WordCounter++)
	{
		WordCounter++;
	}
	for(RowCounter=0;RowCounter<2;RowCounter++)
	{
	for(ColumnsCounter=0;ColumnsCounter<16;ColumnsCounter++)
	{
		LCD_VidSendCommand(LCD_CLR);
		LCD_VidSelectCell(RowCounter,ColumnsCounter);
		LCD_VidSendString(ptr);
		if((ColumnsCounter>20-WordCounter)&&RowCounter==0)
		{ShiftCounter=0;
			while(ShiftCounter<WordCounter)
			{
				LCD_VidSendCommand(LCD_CLR);

			LCD_VidSelectCell(1,ShiftCounter);
			LCD_VidSendData(*(ptr+WordCounter-ShiftCounter));
			ShiftCounter++;
			}
		}
		else if((ColumnsCounter>20-WordCounter)&&RowCounter==1)
				{ShiftCounter=0;
					while(ShiftCounter<WordCounter)
					{
						LCD_VidSendCommand(LCD_CLR);

					LCD_VidSelectCell(0,ShiftCounter);
					LCD_VidSendData(*(ptr+WordCounter-ShiftCounter));
					ShiftCounter++;
					}
				}


		_delay_ms(500);
	}
	}
}
void LCD_VidCalculator(u8 Copy_U8KeyPadPort)
{u32  LOC_U32OperandOne=0,LOC_U32OperandTwo=0;
u8 	 LOC_U8Operation,LOC_U8LastPressed=INTIAL_VALUE;
u8 	 LOC_U8FlagOperandOne=0,LOC_U8FlagOperandTwo=0,LOC_U8FlagOperation=0,LOC_U8WorkFlag=0;
u8 i;
LOC_U8LastPressed=KeyPad_U8GetPressedKey(Copy_U8KeyPadPort);
if(LOC_U8LastPressed!=INTIAL_VALUE)
{LOC_U8WorkFlag=1;
while(LOC_U8WorkFlag==1)
{
if(LOC_U8LastPressed<CLEAR && LOC_U8FlagOperandOne==LOW)
{	i=1;
	while(LOC_U8LastPressed<CLEAR)
       {LCD_VidSendCommand(LCD_CLR);
       LOC_U32OperandOne=LOC_U8LastPressed*i+LOC_U32OperandOne;
       LCD_VidSendVar(LOC_U32OperandOne);
       _delay_ms(100);
    if(KeyPad_U8GetPressedKey(Copy_U8KeyPadPort)!=INTIAL_VALUE)
    {       LOC_U8LastPressed=KeyPad_U8GetPressedKey(Copy_U8KeyPadPort);
    i=i*10;
    }
    else
    {
    	LOC_U8LastPressed=0;}
    }
}

}
}
}

void LCD_VidZigzagDisplay(u8* Copy_U8Data)
{
	u8* ptr=Copy_U8Data;
	u8  WordCounter;
	u8  RowCounter=1;
	u8 ColumnsCursor=1;

	for(WordCounter=0;ptr[WordCounter]!='\0';WordCounter++)
	{
		WordCounter++;
	}

	while(ColumnsCursor<=16-WordCounter+2)
	{
		LCD_VidSendCommand(LCD_CLR);
		LCD_VidSelectCell(RowCounter,ColumnsCursor);
		LCD_VidSendString(Copy_U8Data);
		_delay_ms(1000);
		ColumnsCursor=ColumnsCursor+1;
	if(RowCounter==0)
	{
		RowCounter=1;
	}
	else
	{
		RowCounter=0;
	}
	}


}
void LCD_VidArabicDisplay(u8 Copy_U8PatternNum,u8* Copy_U8PatternArray)
{

	if(Copy_U8PatternNum<8)
	{
	LCD_VidSendCommand(0x40+(8*Copy_U8PatternNum));
	for(u8 i=0;i<8;i++)
	{
		LCD_VidSendData(Copy_U8PatternArray[i]);
	}
	_delay_ms(500);
	}

}
void LCD_VidArabicPrint(u8 Copy_U8LettersNum)
{
	if(Copy_U8LettersNum<8)
	{
		LCD_VidSendCommand(LCD_ENTRY_MODE);
		LCD_VidSelectCell(0,15-Copy_U8LettersNum);
		for(u8 i=0;i<Copy_U8LettersNum;i++)
		{
			LCD_VidSendData(i);
		}
	}
	}
void LCD_VidDisplayOnePattern(u8 Copy_U8PatternNum,u8 Copy_U8Row,u8 Copy_U8Column)
{

	LCD_VidSelectCell(Copy_U8Row,Copy_U8Column);
	LCD_VidSendData(Copy_U8PatternNum);
}
