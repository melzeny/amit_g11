/*
 * _Lab_12_SwitchDebouncing.c
 *
 *  Created on: Nov 16, 2018
 *      Author: AVE-LAP-145
 */
/*
 * _Lab_11_Scheduler.c
 *
 *  Created on: Nov 10, 2018
 *      Author: AVE-LAP-145
 */
#include "../MCAL/DIO/DIO.h"
#include "../Scheduler/Scheduler.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GIE/GIE.h"
#include "../HAL/SWITCH/SWITCH.h"



void _Lab_12_SwitchDebouncing(void)
{

	Scheduler_creatTask(5,SWITCH_Task);/*create switch task for denouncing*/
	TIMER0_setCallBackFunc(Scheduler_start);
	DIO_init();
	TIMER0_init();
	TIMER0_enInterrupt();
	GIE_enInterrupt();

	while(1)
	{
		if(SWITCH_getSwitchStatus() == SWITCH_pressed)
		{
			/*do something*/
		}
		else
		{
			/*do something*/
		}
	}

}

