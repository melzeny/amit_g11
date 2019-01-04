/*
 * SWITCH.c
 *
 *  Created on: Nov 10, 2018
 *      Author: AVE-LAP-145
 */
#include "../../MCAL/DIO/DIO.h"
#include "SWITCH_priv.h"
#include "SWITCH_config.h"
#include "SWITCH.h"

static SWITCH_T UpdatedSWStatus = SWITCH_released;

void SWITCH_Task(void)
{
	static u8 counter =0;
	static SWITCH_T CurrStatus = SWITCH_released,
			PrevStatus = SWITCH_released;
	CurrStatus = DIO_getPinValue(SWITCH_ATTACHED_PIN);
	if(CurrStatus == PrevStatus)
	{
		if(counter >= 5)
		{
			UpdatedSWStatus = CurrStatus;

		}
		counter++;
	}
	else
	{
		counter=0;
	}
	PrevStatus = CurrStatus;
}

SWITCH_T SWITCH_getSwitchStatus(void)
{
#if SWITCH_ACTIVE_MODE == SWITCH_ACTIVE_HIGH
	return UpdatedSWStatus;
#else
	return !UpdatedSWStatus;
#endif
}
