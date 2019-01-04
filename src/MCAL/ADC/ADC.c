/*
 * ADC.c
 *
 *  Created on: Oct 21, 2018
 *      Author: MuhammadElzeiny
 */
#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"

#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_reg.h"
#include "ADC.h"

#include <avr/interrupt.h>

u16 ADC_LastConvertedVal =0 ;

void ADC_init(void)
{

	/*Select Vref source*/
	ADMUX &= 0b00111111;
	ADMUX |=(ADC_VREF_SOURCE_SELECTOR<<6);

	/*select mode*/
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
	SET_BIT(ADCSRA,5);

	/*Select trigger type*/
	SFIOR &=0b00011111;
	SFIOR |= (ADC_TRIGGER_TYPE<<5);
#endif

	/*select prescaler*/
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_PRESCALER_SELECTOR;

	/*enable ADC peripheral*/
	SET_BIT(ADCSRA,7);

}
void ADC_enInterrupt(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_diInterrupt(void)
{
	CLR_BIT(ADCSRA,ADIE);
}
void ADC_startConversion(ADC_Ch_t ChannelNo)
{
	/*choose channel*/
	ADMUX &=0b11100000;
	ADMUX |= ChannelNo;

	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);

	/*check if interrupt disabled*/
	if(GET_BIT(ADMUX,ADIE) == 0)
	{
		/*wait until ADC conversion is finished*/
		while(GET_BIT(ADCSRA,ADIF));
		/*update value*/
		ADC_LastConvertedVal = ADC;
	}
}

void __vector_16(void) __attribute__((signal,used));

void __vector_16(void)
{
	/*update value*/
	ADC_LastConvertedVal = ADC;
}

