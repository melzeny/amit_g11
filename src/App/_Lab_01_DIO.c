/*
 * Lab_1.c
 *
 * Created: 10/19/2018 4:46:32 PM
 *  Author: MuhammadElzeiny
 */ 
#include "../Lib/BIT_MATH.h"
#include "../Lib/STD_TYPES.h"
#include "../MCAL/DIO/DIO.h"

#define PIN_SW_1		DIO_PIN_D0
#define PIN_LED_1		DIO_PIN_C0
void _Lab_01_DIO(void)
{
	DIO_init();
	DIO_PinValue_t CurrentPinVal = DIO_Pin_low,PrevPinVal = DIO_Pin_low;
	while(1)
	{
		CurrentPinVal = DIO_getPinValue(PIN_SW_1);
		if(CurrentPinVal == DIO_Pin_high)
		{
			if(PrevPinVal == DIO_Pin_low)
			{
				DIO_togglePin(PIN_LED_1);	
			}
		}
		PrevPinVal = CurrentPinVal;
		
		
	}
}