/*
 * _Lab_09_UART.c
 *
 *  Created on: Oct 23, 2018
 *      Author: MuhammadElzeiny
 */

#include "util/delay.h"

#include "../Lib/STD_TYPES.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/GIE/GIE.h"

void _Lab_13_UART(void)
{
	u16 i;
	u8 MsgPtr[16];
	u16 MsgLen=0;

	DIO_init();
	LCD_init();
	UART_init();

	GIE_enInterrupt();
	UART_enRxInterrupt();

	while(1)
	{

		UART_getMessage(MsgPtr,&MsgLen);
		for(i=0;i<MsgLen;i++)
		{
			LCD_wrtiteData(MsgPtr[i]);
		}
		_delay_ms(2000);
	}

}
