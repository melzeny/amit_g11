/*****************************************
Author : Muhammad Elzeiny
Date 1/2018
Release : v1
****************************************/

#ifndef _LCD_INT_H
#define _LCD_INT_H

/************************************************/
/* 			 this function is used to          */
/*         initialize	 LCD                  */
/*********************************************/

extern void LCD_init(void);

/************************************************/
/* 			 this function is used to          */
/*         write data on LCD                  */
/*********************************************/
extern void LCD_wrtiteData(u8 u8DataCpy);

/********************************************* ***/
/* 			 this function is used to           */
/*         execute LCD command                 */
/**********************************************/
extern void LCD_writeCommand(u8 u8CommandCpy);

extern void LCD_writeString(u8 *ptr, u8 xpos, u8 ypos);
extern void LCD_clear();


#endif
