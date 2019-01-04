/*
 * ADC.h
 *
 *  Created on: Oct 21, 2018
 *      Author: MuhammadElzeiny
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

typedef enum
{
	ADC_Ch0=0,
	ADC_Ch1,
	ADC_Ch2,
	ADC_Ch3,
	ADC_Ch4,
	ADC_Ch5,
	ADC_Ch6,
	ADC_Ch7
}ADC_Ch_t;

extern u16 ADC_LastConvertedVal;

void ADC_init(void);
void ADC_enInterrupt(void);
void ADC_diInterrupt(void);
void ADC_startConversion(ADC_Ch_t ChannelNo);




#endif /* MCAL_ADC_ADC_H_ */
