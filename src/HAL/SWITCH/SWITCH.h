/*
 * SWITCH.c
 *
 *  Created on: Nov 10, 2018
 *      Author: AVE-LAP-145
 */

#ifndef HAL_SWITCH_SWITCH_C_
#define HAL_SWITCH_SWITCH_C_


typedef enum
{
	SWITCH_released=0,
	SWITCH_pressed = !SWITCH_released
}SWITCH_T;

SWITCH_T SWITCH_getSwitchStatus(void);
void SWITCH_Task(void);

#endif /* HAL_SWITCH_SWITCH_C_ */
