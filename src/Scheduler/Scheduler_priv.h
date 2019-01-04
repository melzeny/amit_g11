/*
 * Scheduler_priv.h
 *
 *  Created on: Nov 10, 2018
 *      Author: AVE-LAP-145
 */

#ifndef SCHEDULER_SCHEDULER_PRIV_H_
#define SCHEDULER_SCHEDULER_PRIV_H_

typedef struct
{
	u32 periodicity;
	void(*TaskPtr)(void);
}SCHEDULER_Task_t;


#endif /* SCHEDULER_SCHEDULER_PRIV_H_ */
