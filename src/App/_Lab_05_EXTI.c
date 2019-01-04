/*
 * _Lab_08_EXTI.c
 *
 *  Created on: Oct 23, 2018
 *      Author: MuhammadElzeiny
 */
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/EXTI/EXTI.h"

void func()
{
	DIO_togglePin(DIO_PIN_D0);
}


void _Lab_08_EXTI(void)
{


	DIO_init();
	EXTI_init();
	EXTI_setCallBack(func);
	EXTI_enInterrupt();
	GIE_enInterrupt();
	while(1)
	{



	}
}
