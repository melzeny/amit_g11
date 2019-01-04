/*
 * ADC_priv.h
 *
 *  Created on: Oct 21, 2018
 *      Author: MuhammadElzeiny
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_


#define   ADC_VREF_AREF						0
#define   ADC_VREF_AVCC						1
#define	  ADC_VREF_2_56						3


#define  ADC_MODE_SINGEL_CONVERSION			0
#define  ADC_MODE_AUTO_TRIGGER				1

#define	 ADC_TRIGGER_FREE_RUNNING        	0
#define	 ADC_TRIGGER_EXTI		        	2

#define ADC_PRESCALER_2							1
#define ADC_PRESCALER_4							2
#define ADC_PRESCALER_8							3
#define ADC_PRESCALER_16						4
#define ADC_PRESCALER_32						5
#define ADC_PRESCALER_64						6
#define ADC_PRESCALER_128						7

#endif /* MCAL_ADC_ADC_PRIV_H_ */
