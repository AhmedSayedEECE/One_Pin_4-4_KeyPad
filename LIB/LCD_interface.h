/********************************************************************************/
/*******************Author : Ahmed Sayed  **********************************/
/*******************File   : Interface of LCD **********************************/
/*******************Date   : 10/9/2022           **********************************/
/*******************Ver    : V1                 **********************************/
/*******************Desc   :                    **********************************/
/********************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
void LCD_VidInitialziation(void);
void LCD_VidFourBitModeInit(void);
void LCD_VidSendCommand(u8 Copy_U8Command);
void LCD_VidSelectCell (u8 Copy_U8Row,u8 Copy_U8Column);
void LCD_VidSendData(u8 Copy_U8Data);
void LCD_VidSendString(u8* Copy_U8Data);
void LCD_VidZigzagDisplay(u8* Copy_U8Data);
void LCD_VidCalculator(u8 Copy_U8Port);
void LCD_VidSendVar(s32 Copy_U8Data);
void LCD_VidShiftDisplay(u8* Copy_U8Data);
void LCD_VidArabicDisplay(u8 Copy_U8PatternNum,u8* Copy_U8PatternArray);
void LCD_VidArabicPrint(u8 Copy_U8LettersNum);
void LCD_VidDisplayOnePattern(u8 Copy_U8PatternNum,u8 Copy_U8Row,u8 Copy_U8Column);

#endif
