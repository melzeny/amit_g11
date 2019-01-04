/********************************************/
/*  Author : Muhammad Elzeiny			   */
/*  Date 1/2018							  */
/*  Release : v1    	  				 */
/****************************************/
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD_config.h"
#include "LCD_priv.h"
#include "LCD.h"

/************************************************/
/* 			 this function is used to          */
/*         initialze  LCD                    */
/*********************************************/
void LCD_init(void){

	/* 15ms should be waited  between power up and LCD_init()*/

#if (LCD_MODE_PINS_NO == LCD_MODE_PINS_8)
	/*
	 * To init LCD in 8-bit mode
	 * sequence 0x38,0x0E,0x01 should be written as command
	 * */

	LCD_writeCommand(0x38);  /*init. LCD 2 line, 5x7 matrix*/
	_delay_ms(1);

#else
	/*
	 * To init LCD in 4-bit mode
	 * sequence 0x33,0x32,0x28 should be written as command
	 * */
	LCD_writeCommand(0x33); /*init*/
	_delay_ms(1);

	LCD_writeCommand(0x32); /*init*/
	_delay_ms(1);

	LCD_writeCommand(0x28); /*init. LCD 2 line, 5x7 matrix*/
	_delay_ms(1);

#endif

	LCD_writeCommand(0x0E); /*display on, cursor on*/
	_delay_ms(1);

	LCD_writeCommand(0x01); /*clear LCD*/
	_delay_ms(2);

}

/************************************************/
/* 			 this function is used to          */
/*         write data on LCD                  */
/*********************************************/
void LCD_wrtiteData(u8 u8DataCpy){

	/* set RS to high  */
	DIO_setPinValue(LCD_u8_RS_PIN,DIO_Pin_high);
	/* Execute command */
	LCD_excute(u8DataCpy);
}

/********************************************* ***/
/* 			 this function is used to           */
/*         execute LCD command                 */
/**********************************************/
void LCD_writeCommand(u8 u8CommandCpy){

	/* set RS to LOW */
	DIO_setPinValue(LCD_u8_RS_PIN,DIO_Pin_low);
	/* Execute command */
	LCD_excute(u8CommandCpy);
}

void LCD_writeString(u8 *ptr, u8 xpos, u8 ypos)
{
	/*cmd to move cursor*/
	LCD_writeCommand((0x80 | ypos<<6 | xpos));

	while(*ptr !='\0')
	{
		LCD_wrtiteData(*ptr);
		ptr++;
	}
}
void LCD_clear()
{
	DIO_setPinValue(LCD_u8_RS_PIN,DIO_Pin_low);
	DIO_setPinValue(LCD_u8_RW_PIN,DIO_Pin_low);
	LCD_writeCommand(0b00000001);
	//	_delay_ms(1.5);
}

static void LCD_excute(u8 u8ValueCpy){

	/*set RW to low */
	DIO_setPinValue(LCD_u8_RW_PIN,DIO_Pin_low);

	/* set received data to LCD data lines*/
#if(LCD_MODE_PINS_NO == LCD_MODE_PINS_8)
	DIO_setPinValue(LCD_u8_DATA_PIN_0,  GET_BIT(u8ValueCpy,0));
	DIO_setPinValue(LCD_u8_DATA_PIN_1,  GET_BIT(u8ValueCpy,1));
	DIO_setPinValue(LCD_u8_DATA_PIN_2,  GET_BIT(u8ValueCpy,2));
	DIO_setPinValue(LCD_u8_DATA_PIN_3,  GET_BIT(u8ValueCpy,3));
#endif


	DIO_setPinValue(LCD_u8_DATA_PIN_4,  GET_BIT(u8ValueCpy,4));
	DIO_setPinValue(LCD_u8_DATA_PIN_5,  GET_BIT(u8ValueCpy,5));
	DIO_setPinValue(LCD_u8_DATA_PIN_6,  GET_BIT(u8ValueCpy,6));
	DIO_setPinValue(LCD_u8_DATA_PIN_7,  GET_BIT(u8ValueCpy,7));

	/* set ENABLE high */
	DIO_setPinValue(LCD_u8_E_PIN,DIO_Pin_high);
	/* Delay 1 ms */
	_delay_ms(1);
	/*set Enable LOW */
	DIO_setPinValue(LCD_u8_E_PIN,DIO_Pin_low);



#if (LCD_MODE_PINS_NO == LCD_MODE_PINS_4)

	DIO_setPinValue(LCD_u8_DATA_PIN_4,  GET_BIT(u8ValueCpy,0));
	DIO_setPinValue(LCD_u8_DATA_PIN_5,  GET_BIT(u8ValueCpy,1));
	DIO_setPinValue(LCD_u8_DATA_PIN_6,  GET_BIT(u8ValueCpy,2));
	DIO_setPinValue(LCD_u8_DATA_PIN_7,  GET_BIT(u8ValueCpy,3));

	/* set ENABLE high */
	DIO_setPinValue(LCD_u8_E_PIN,DIO_Pin_high);
	/* Delay 1 ms */
	_delay_ms(1);
	/*set Enable LOW */
	DIO_setPinValue(LCD_u8_E_PIN,DIO_Pin_low);

#endif

}
