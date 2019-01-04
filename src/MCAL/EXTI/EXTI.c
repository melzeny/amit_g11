/*
 * EXTI.c
 *
 *  Created on: Oct 26, 2018
 *      Author: MuhammadElzeiny
 */
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "EXTI_reg.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI.h"

static void (*CallBackFunc)(void);
/* This function shall intialize the EXTI and
 * Set its operation initially disable*/
void EXTI_init(void)
{
	/*Select Edge*/
#if (EXTI_EDGE_SELECTOR == EXTI_ON_CHANGE)
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif (EXTI_EDGE_SELECTOR == EXTI_EDGE_FALL)
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#else
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif
}

/*This function shall set the callback pointer
 * to the received the address*/
void EXTI_setCallBack(void (*FuncPtr) (void) )
{
	CallBackFunc = FuncPtr;
}
/*This function shall enable the external interrupt*/
void EXTI_enInterrupt(void)
{
	SET_BIT(GICR,6);
}

/*This function shall disable the external interrupt*/
void EXTI_diInterrupt (void)
{
	CLR_BIT(GICR,6);
}

/*ISR for External interrupt_0*/
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	CallBackFunc();

}
