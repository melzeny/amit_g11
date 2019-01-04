/*
 * _Lab_05_LCD.c
 *
 *  Created on: Oct 21, 2018
 *      Author: MuhammadElzeiny
 */

#include "../Lib/STD_TYPES.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/DIO/DIO.h"

void _Lab_05_LCD(void)
{

	DIO_init();
	LCD_init();
	LCD_wrtiteData('a');
	LCD_wrtiteData('h');
	LCD_wrtiteData('m');
	LCD_wrtiteData('e');
	LCD_wrtiteData('d');
	while(1)
	{



	}

}
