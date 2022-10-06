#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_cfg.h"
#include "ADC_interface.h"
#include "SevSeg_interface.h"
#include "SevSeg_cfg.h"
/*****************Task: Operating 4*4 Keypad using One Pin only*****************/

#define	VOLT_MAX				5000					/*Maximum Voltage in in mV*/
#define	MAX_SIZE				1023					/*Maximum Digital ADC Output*/


void main(void)
{
	u16 LOC_MilliVolt=0;
	DIO_VidSetPinDirection(A, PIN_0, INPUT);
	DIO_VidSetPinValue(A, PIN_0, HIGH);			/*Enable Internal Pull up Resistor*/
	DIO_VidSetPortDirection(B,0xFF);			/*Setting Seven segment pin to show results*/
	ADC_VidInit();								/*ADC Initialization*/


	while(1)
	{
		LOC_MilliVolt=0;
		LOC_MilliVolt=ADC_U16Convert(PIN_0);			/*Storing value of ADC*/
/*
 * 			5v
 * 			|		Rin
 * 	Vout-----
 * 			|R1					Switch
 * 			___________________---______R2
 * 										|
 * 									   ---
 * 										-			GND
 *
 * Vout (Switch Not pressed) = 5v
 *
 * Vout (Switch Pressed) =   5*((R1+R2)/(R1+R2+Rin))
 *
 * */
		LOC_MilliVolt=((float)LOC_MilliVolt/MAX_SIZE)*VOLT_MAX;		/*Convert to value of Voltage divider result*/
			/*Seven Segment Display*/
		if(LOC_MilliVolt<1900 && LOC_MilliVolt>1800)
		{
			/*Switch 1*/
		SevSeg_VidDisplayNum(B,1);
		_delay_ms(100);
		}
		else if(LOC_MilliVolt<2100 && LOC_MilliVolt>2000)
				{
			/*Switch 2*/
				SevSeg_VidDisplayNum(B,2);
				_delay_ms(100);
				}
		else if(LOC_MilliVolt<2300 && LOC_MilliVolt>2200)
				{
			/*Switch 3*/
			SevSeg_VidDisplayNum(B,3);
				_delay_ms(100);
				}
		else if(LOC_MilliVolt<2400 && LOC_MilliVolt>2300)
				{
			/*Switch 4*/
				SevSeg_VidDisplayNum(B,4);
				_delay_ms(100);
				}
		else if(LOC_MilliVolt<2650 && LOC_MilliVolt>2550)
				{
				SevSeg_VidDisplayNum(B,5);
				_delay_ms(100);
				}
		else if(LOC_MilliVolt<2750 && LOC_MilliVolt>2650)
						{
						SevSeg_VidDisplayNum(B,6);
						_delay_ms(100);
						}

		else if(LOC_MilliVolt<2850 && LOC_MilliVolt>2750)
						{
						SevSeg_VidDisplayNum(B,7);
						_delay_ms(100);
						}

		else if(LOC_MilliVolt<2950 && LOC_MilliVolt>2850)
						{
						SevSeg_VidDisplayNum(B,8);
						_delay_ms(100);
						}
		else if(LOC_MilliVolt<3250 && LOC_MilliVolt>3150)
								{
								SevSeg_VidDisplayNum(B,9);
								_delay_ms(100);
								}
		else
		{
			/*Normal Mode*/
			SevSeg_VidDisplayNum(B,0b01111001);
						_delay_ms(100);

		}

	}

}
