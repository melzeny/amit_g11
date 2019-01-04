/*
 * Scheduler.c
 *
 *  Created on: Nov 10, 2018
 *      Author: AVE-LAP-145
 */
#include "../MCAL/DIO/DIO.h"
#include "Scheduler_priv.h"
#include "Scheduler_config.h"
#include "Scheduler.h"

static u8 CurrentTaskNo = 0;

SCHEDULER_Task_t Tasks[SCHEDULER_MAX_NO_OF_TASK];

void Scheduler_creatTask(u32 PeriodicityLoc,void(*TaskPtrLoc)(void))
{


	if(CurrentTaskNo < SCHEDULER_MAX_NO_OF_TASK)
	{
		Tasks[CurrentTaskNo].periodicity = PeriodicityLoc;
		Tasks[CurrentTaskNo].TaskPtr = TaskPtrLoc;
		CurrentTaskNo++;
	}
}



void Scheduler_start(void)
{
	static u8 SchedulerCounter = 0;
	u8 i;
	for(i=0;i<CurrentTaskNo;i++)
	{
		if(SchedulerCounter % Tasks[i].periodicity == 0)
		{
			Tasks[i].TaskPtr();
		}
	}
	SchedulerCounter++;

}
