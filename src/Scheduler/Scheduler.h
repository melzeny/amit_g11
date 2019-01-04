/*
 * Scheduler.h
 *
 *  Created on: Nov 10, 2018
 *      Author: AVE-LAP-145
 */

#ifndef SCHEDULER_SCHEDULER_H_
#define SCHEDULER_SCHEDULER_H_



void Scheduler_creatTask(u32 Periodicity,void(*TaskPtr)(void));
void Scheduler_start(void);


#endif /* SCHEDULER_SCHEDULER_H_ */
