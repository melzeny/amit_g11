/*
 * TIMER0.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Mostafa
 */
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "TIMER0_reg.h"
#include "TIMER0_priv.h"
#include "TIMER0_config.h"
#include "TIMER0.h"

static void(*CallBackFuncPtr)(void);

void TIMER0_init(void)
{
	DIO_setPinValue(DIO_PIN_A0,DIO_Pin_low);
	/*select mode*/
	TCCR0 &= TIMER0_MODE_CLR;
	TCCR0 |= TIMER0_MODE_SELECTOR_MSK;

	/*select prescaler*/
	TCCR0 &= TIMER0_PRESCASLER_CLR_MSK;
	TCCR0 |= TIMER0_PRESCALER_SELECTOR_MSK;

	/*init register*/
#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	TCNT0=255-TIMER0_DESIRED_STEPS;

#elif TIMER0_MODE_SELECTOR_MSK==TIMER0_MODE_CTC_MSK
	OCR0 = TIMER0_DESIRED_STEPS;
#else
	/*PWM mode*/
	TCCR0 &= TIMER0_FAST_PWM_EDGE_CLR;
	TCCR0 |= TIMER0_FAST_PWM_START_EDGE_MSK;

	OCR0 = TIMER0_DESIRED_STEPS;
#endif


}

void TIMER0_enInterrupt(void)
{

#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	SET_BIT(TIMSK,0);
#else
	SET_BIT(TIMSK,1);
#endif
}
void TIMER0_diInterrupt(void)
{
#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	CLR_BIT(TIMSK,0);
#else
	CLR_BIT(TIMSK,1);
#endif

}
void TIMER0_setCallBackFunc(void(*funcPtr)(void))
{
	CallBackFuncPtr = funcPtr;
}

u32 TIMER0_getTime_us(void)
{
	u32 Time_us = 0 ;
	/*implement function to get time in micro-seconds*/



	return Time_us;
}
void TIMER0_initCounter(u8 val)
{
#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	TCNT0 = 0;
#endif
}

/*ISR for CTC mode*/
void __vector_10(void)__attribute__((signal,used));
void __vector_10(void)
{
	CallBackFuncPtr();
}

/*ISR for overflow mode*/
void __vector_11(void)__attribute__((signal,used));
void __vector_11(void)
{
	TCNT0=255-TIMER0_DESIRED_STEPS;
	CallBackFuncPtr();
}
