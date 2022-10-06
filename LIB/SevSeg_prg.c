#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include"SevSeg_Private.h"
#include"SevSeg_cfg.h"
u8 SevSeg_U8SegNum[10]={zero,one,two,three,four,five,six,seven,eight,nine};
void SevSeg_VidDisplayNum(u8 Copy_U8Port,u8 Copy_U8Num )
{
	if(Copy_U8Num>-1 && Copy_U8Num<10)
	{
	#if 	SEG_TYPE == COM_KA
	DIO_VidSetPortValue(Copy_U8Port, SevSeg_U8SegNum[Copy_U8Num]);
	#elif	SEG_TYPE == COM_ANA
	DIO_VidSetPortValue(Copy_U8Port, ~(SevSeg_U8SegNum[Copy_U8Num]));
	#else
		#error "WRONG INPUT"
	#endif
	}
	else
	{
		DIO_VidSetPortValue(Copy_U8Port, Copy_U8Num);

	}
	}
