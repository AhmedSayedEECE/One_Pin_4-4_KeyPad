#ifndef  	ADC_cfg_H_
#define		ADC_cfg_H_
#define FREE_RUNNING			1
#define SINGLE_CONVERSION		0


/*ADLAR SETUP Bit will added as Configure option*/
/*Prescaler ratio also*/
/*ADLAR -> 1 Left Adjust*/
#define 	ADLAR_SETUP 		RIGHT
/*************************************************************************************************************/
/*
0		("AREF")		     		AREF, Internal Vref turned off
1		 							AVCC with external capacitor at AREF pin		5v used
2		("AVCC")				 	Reserved
3 		("INTERNAL_VREF")		 	Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define  	VREF				AVCC
/*ADC Enable configuation required*/

/*SFIOR OPTIONS REQUIRED*/

/*ADC CONVERSION MOOD*/
/*
Select
("FREE_RUNNING		")			("1")
("SINGLE_CONVERSION	")			("0")

*/
#define   CONVERSION_MOOD			SINGLE_CONVERION






#endif
