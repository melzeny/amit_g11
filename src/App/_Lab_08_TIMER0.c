/*
 * _Lab_10.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Mostafa
 */
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GIE/GIE.h"
static void func(void)
{
	DIO_togglePin(DIO_PIN_A0);
}

void _Lab_10_TIMER0(void)
{
	DIO_init();
	TIMER0_init();
	TIMER0_setCallBackFunc(func);
	TIMER0_enInterrupt();
	GIE_enInterrupt();

	while(1);
}

