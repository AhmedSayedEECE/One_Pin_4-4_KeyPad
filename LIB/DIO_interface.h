/** *********************************** *************************************************************************************/
/********************Author : Ahmed Sayed    *** ********************************************************************************/
/********************File      : Interface of DIO ***********************************************************************************/
/********************Date    : 3/9/2022          **********************************************************************************/
/********************Ver      : V1                     *********************************************************************************/
/********************Desc    :                         *********************************************************************************/
/***********************************************************************************************************************/
#ifndef  DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define  A 			0
#define  B 			1
#define  C			2
#define  D 			3

#define PIN_7					7
#define PIN_6					6
#define PIN_5					5
#define PIN_4					4
#define PIN_3					3
#define PIN_2					2
#define PIN_1					1
#define PIN_0					0

#define  HIGH		1
#define  LOW		0

#define  INPUT 			0
#define  OUTPUT			1

void  DIO_VidSetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction);
void  DIO_VidSetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value);
u8    DIO_U8GetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin);
void  DIO_VidTogglePinValue(u8 Copy_U8Port, u8 Copy_U8Pin);
void  DIO_VidSetPortValue(u8 Copy_U8Port, u8 Copy_U8Value);
void  DIO_VidSetPortDirection(u8 Copy_U8Port, u8 Copy_U8Dir);






#endif
