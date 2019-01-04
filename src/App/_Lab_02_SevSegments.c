/*
 * Lab_2.c
 *
 * Created: 10/19/2018 7:46:57 PM
 *  Author: MuhammadElzeiny
 */ 
#include "avr/delay.h"
#include "../Lib/STD_TYPES.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/SevSegments/SevSegments.h"
#include "../HAL/BCDSevSegments/BCDSevSegments.h"
void _Lab_02_SevSegments(void)
{
	u8 i;
	DIO_init();
	SevSegments_enable();
	BCDSevSegments_enable();
	BCDSevSegments_displayNo(5);
	while(1)
	{
		
		for(i=0;i<10;i++)
		{
			SevSegments_displayNo(i);
			_delay_ms(500);
		}
	}
}