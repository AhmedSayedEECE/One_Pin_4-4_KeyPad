/**************************************************************************************************************************/
/********************Author 	: Ahmed Sayed    					***********************************************************************************/
/********************File   		: Interface of ADC 	***********************************************************************************/
/********************Date   	: 28/9/2022        						**********************************************************************************/
/********************Ver    		: V1                     						*********************************************************************************/
/********************Desc   	:                         						*********************************************************************************/
/***********************************************************************************************************************/

#ifndef  ADC_interface_H_
#define ADC_interface_H_

void ADC_VidInit(void);
u16 ADC_U16Convert(u8 Copy_U8Pin);
/*
u16 ADC_U16Mapping(u16 Copy_U16Digital,u16 Copy_U16FromLow,u16 Copy_U16FromHigh,u16 Copy_U16ToLow,u16 Copy_U16ToHigh);
*/
/*
u16 ADC_U16PotCalculation(u16 Copy_U16Digital);
*/

s16 ADC_U16Mapping(s16 Copy_U16DigitalValue,s16 Copy_U16MinIn,s16 Copy_U16MaxIn,s16 Copy_U16MinOut,s16 Copy_U16MaxOut);

#endif
