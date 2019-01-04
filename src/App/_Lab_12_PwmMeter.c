/*
 * _Lab_13_PwmMeter.c
 *
 *  Created on: Nov 16, 2018
 *      Author: AVE-LAP-145
 */

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER0/TIMER0.h"

void _Lab_13_PwmMeter(void)
{
	u8 RisingEdgeCounter = 0;
	u32 t0=0,t1=0,t2=0;
	DIO_PinValue_t CurrentStatus = DIO_Pin_low,PrevStatus = DIO_Pin_low;
	DIO_init();
	TIMER0_init();

	while(1)
	{
		CurrentStatus = DIO_getPinValue(DIO_PIN_A0);
		/*check if edge has occurred*/
		if(CurrentStatus == DIO_Pin_high && PrevStatus == DIO_Pin_low)
		{
			/*Rising Edge*/
			if(RisingEdgeCounter == 0)
			{
				TIMER0_initCounter(0);
				RisingEdgeCounter = 1;
			}
			else
			{
				t2 = TIMER0_getTime_us();
				RisingEdgeCounter = 0;
			}

		}
		else if(CurrentStatus == DIO_Pin_low && PrevStatus == DIO_Pin_high)
		{
			/*Falling Edge */
			t1 = TIMER0_getTime_us();

		}
		PrevStatus = CurrentStatus;

	}

}
