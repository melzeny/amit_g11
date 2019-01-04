/*
 * _Lab_07_ADC.c
 *
 *  Created on: Oct 21, 2018
 *      Author: MuhammadElzeiny
 */
#include <stdlib.h>
#include <util/delay.h>

#include "../Lib/STD_TYPES.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/ADC/ADC.h"

void _Lab_07_ADC(void)
{
	u8 str[5]={0};
	DIO_init();
	ADC_init();
	LCD_init();

	GIE_enInterrupt();
	ADC_enInterrupt();

	ADC_startConversion(ADC_Ch0);

	while(1)
	{
		itoa(ADC_LastConvertedVal,str,10);
		LCD_writeString(str,0,0);
	}
}
