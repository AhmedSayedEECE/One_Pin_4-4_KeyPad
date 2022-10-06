#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "ADC_private.h"
#include "ADC_cfg.h"


void ADC_VidInit(void)
{
/*Enable ADC Interrupt*/
SET_BIT(ADCSRA,ADIE);
/*MOOD Condition*/
#if CONVERSION_MOOD == FREE_RUNNING
/*ADC Start Conversion bit*/
SET_BIT(ADCSRA,ADSC);
#endif
/*Voltage reference selection*/
#if 	VREF == AREF
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);
#elif	VREF == AVCC
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#elif	VREF == INTERNAL
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
#else
#warning "UNDEFINED VREF"
#endif
/*ADLAR is set to zero*/
/*Further configurations to be added here*/
#if 	ADLAR_SETUP == RIGHT
CLR_BIT(ADMUX,ADLAR);
#elif	ADLAR_SETUP == LEFT
SET_BIT(ADMUX,ADLAR);
#endif
/*Auto trigger disable*/
/*SFIOR Register bits has no effect*/
/*Starting conversion by setting ADEN to 1*/
CLR_BIT(ADCSRA,ADATE);
/*Prescaler ratio 1/128*/
SET_BIT(ADCSRA,ADPS2);
SET_BIT(ADCSRA,ADPS1);
SET_BIT(ADCSRA,ADPS0);

/*Enable ADC*/
SET_BIT(ADCSRA,ADEN);
}

u16 ADC_U16Convert(u8 Copy_U8Pin)
{
ADMUX &= 0xE0;		/*Maintain */
u16 DigitalValue=0;
/*MUX selection By Port A pin used as ADC circuit*/
ADMUX=(ADMUX | (Copy_U8Pin & 0x1F));

#if CONVERSION_MOOD == SINGLE_CONVERSION
	/*Interrupt Bit cleared to start conversion (No Auto Trigger usage)*/
	CLR_BIT(ADCSRA,ADIF);
	/*ADC Start Conversion bit*/
	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADIF)==LOW)		/*Waiting for Conversion Completion*/
		/*NOP*/ ;
	_delay_ms(1);
	/*Eight left shift as ADLAR is cleared*/
	/*LOGICAL Clear of interrupt flag*/
	SET_BIT(ADCSRA,ADIF);

#endif

DigitalValue=ADC_RESULT;			/*Storing Digital Value 0 -> 1023*/
return 		DigitalValue;


}

s16 ADC_U16Mapping(s16 Copy_U16DigitalValue,s16 Copy_U16MinIn,s16 Copy_U16MaxIn,s16 Copy_U16MinOut,s16 Copy_U16MaxOut)
{/*
********************************************Mapping Function Parameters******************************************************
A-Digital value from ADC Process
B-Min input value (Set to zero)
C-Max input value (2^n-1) "1023" for 10 bit ADC
D-Min output value to your peripheral
E-Max output value to your peripheral	*/

s16 result=0; /*Return Variable*/
/*Float casting for devision needs */
result=((float)(Copy_U16DigitalValue-Copy_U16MinIn) * (Copy_U16MaxOut-Copy_U16MinOut)/(Copy_U16MaxIn-Copy_U16MinIn))
		+Copy_U16MinOut;		/*Normal Mathematical Operation*/

return result;
}






