#ifndef  ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
/*************************************************************************************************************/
/*ADC driver Needed Registers*/
#define SFIOR	 							*((volatile u8*)0x50)						/*Special function I/O Register*/
#define ADMUX	 							*((volatile u8*)0x27)						/*ADC MUX Selection Register*/
#define ADCSRA	 							*((volatile u8*)0x26)						/*ADC Control and Selection Register*/

//#define ADCH	 							*((volatile u8*)0x25)						/*ADC Data Register High Byte*/
//#define ADCL	 							*((volatile u8*)0x24)						/*ADC Data Register Low Byte*/

/*Mandatory Volatile*/
#define ADC_RESULT	 						*((volatile u16*)0x24)						/*ADC Data Register Low Byte*/

/*************************************************************************************************************/
/*ADMUX Bits*/
#define REFS1								7														/*Voltage Reference Highest Bit*/
#define REFS0								6														/*Voltage Reference Lowest Bit*/
#define ADLAR								5														/*Digital Result Shift Left/Right*/
/*Bits 4 -> 0 are MUX selection bits MUX 4,3,2,1,0*/
/*************************************************************************************************************/
/*ADCSRA Bits*/
#define ADEN								7														/*ADC Enable*/
#define ADSC								6														/*ADC Start Conversion*/
#define ADATE								5														/*ADC Auto Triggering Enable*/
#define ADIF								4														/*Voltage Reference Highest Bit*/
#define ADIE								3														/*Voltage Reference Lowest Bit*/
/*Prescaler Ratio bits Selection*/
#define ADPS2								2														/*Digital Result Shift Left/Right*/
#define ADPS1								1														/*Digital Result Shift Left/Right*/
#define ADPS0								0														/*Digital Result Shift Left/Right*/
/*************************************************************************************************************/
#define HIGH 						1
#define LOW 						0
#define EIGHT_SHIFT 				8
/*ADLAR OPTIONS*/
#define LEFT		1
#define RIGHT 		0
/*VOLTAGE REFERENCE OPTIONS*/
#define AREF				0
#define AVCC				1
#define INTERNAL_VREF		3
/*PRESCALER RATIO OPTIONS*/
#define ADC_128_SCALE				7
#define ADC_64_SCALE				6
#define ADC_32_SCALE				5
#define ADC_16_SCALE				4
#define ADC_8_SCALE					3
#define ADC_4_SCALE					2
#define ADC_2_SCALE					1

#endif
