
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define   FUN_SET 						0b00111000					 /*0b001 DL NF00   DL:Data length 			N: NUMBER OF LINES			F: Font lenghth			SEE LCD_DATA_SHEET*/
#define   DISPLAY_ON_OFF 				0b00001100					 /*0b00001DCB   D:LCD ON OR OFF 			C: CURSOR ON OR OFF			B: CURSOR BLINK ON OR OFF			SEE LCD_DATA_SHEET*/
#define   LCD_CLR 						0b00000001					 
#define   LCD_ENTRY_MODE       			0b00000101
/****************************************4 Bit Mode************************************************************/
#define   FUN_SET_FOUR_BIT 						0b00101000					 /*0b001 DL NF00   DL:Data length 			N: NUMBER OF LINES			F: Font lenghth			SEE LCD_DATA_SHEET*/
/***********************************Check entry mode set**********************************************************/
#define DATA_PORT							2
#define CTRL_PORT							3
#define KEYPAD_PORT							0
#define RS 									0
#define RW 									1
#define EN 									2

#endif
