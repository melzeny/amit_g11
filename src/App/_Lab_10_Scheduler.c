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

void Task_1(void)
{
	DIO_setPinValue(DIO_PIN_A0,DIO_Pin_high);
}
void Task_2(void)
{
	DIO_setPinValue(DIO_PIN_A0,DIO_Pin_low);
}
void Task_3(void)
{
	DIO_togglePin(DIO_PIN_A2);
}

void _Lab_11_Scheduler(void)
{

	Scheduler_creatTask(16,Task_1);
	Scheduler_creatTask(2,Task_2);
	Scheduler_creatTask(5,Task_3);
	TIMER0_setCallBackFunc(Scheduler_start);
	DIO_init();
	TIMER0_init();
	TIMER0_enInterrupt();
	GIE_enInterrupt();

	while(1);

}

