/*
 * EXTI.h
 *
 *  Created on: Oct 26, 2018
 *      Author: MuhammadElzeiny
 */

#ifndef MCAL_EXTI_EXTI_H_
#define MCAL_EXTI_EXTI_H_

/* This function shall intialize the EXTI and
 * Set its operation initially disable*/
void EXTI_init(void);

/*This function shall set the callback pointer
 * to the received the address*/
void EXTI_setCallBack(void (*ptrcpy) (void) );
/*This function shall enable the external interrupt*/
void EXTI_enInterrupt(void);

/*This function shall disable the external interrupt*/
void EXTI_diInterrupt (void);












#endif /* MCAL_EXTI_EXTI_H_ */
