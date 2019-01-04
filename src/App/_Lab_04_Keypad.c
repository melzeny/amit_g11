/*
 * _Lab_3_Keypad.c
 *
 * Created: 10/20/2018 6:00:06 PM
 *  Author: MuhammadElzeiny
 */ 
#include "../Lib/STD_TYPES.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCDSevSegments/BCDSevSegments.h"
#include "../HAL/Keypad/Keypad.h"

void _Lab_04_Keypad(void)
{
	u8 PressedSw =-1;
	DIO_init();
	Keypad_init();
		
	while(1)
	{
		PressedSw = Keypad_getPressedButton();
		if(PressedSw != -1)
		{
			BCDSevSegments_enable();
			BCDSevSegments_displayNo(PressedSw);
		}
		else
		{
			BCDSevSegments_disable();
		}
		
	}
}