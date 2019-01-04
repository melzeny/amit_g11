/*
 * ADC_reg.h
 *
 *  Created on: Apr 19, 2018
 *      Author: MuhammadElzeiny
 */

#ifndef SYSTEM_COTS_MCAL_ADC_ADC_REG_H_
#define SYSTEM_COTS_MCAL_ADC_ADC_REG_H_

#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADCH		*((volatile u8*)0X25)
#define ADCL		*((volatile u8*)0X24)
#define ADC			*((volatile u16*)0X24)
#define SFIOR		*((volatile u8*)0X50)
/*bits in ADMUX register*/
#define REFS1		7
#define REFS0		6
#define ADLAR		5

/*bits in ADCSRA register*/
#define ADEN		7
#define ADSC		6
#define ADATE		5
#define ADIF		4
#define ADIE		3
#define ADPS2		2
#define ADPS1		1
#define ADPS0		0

#endif /* SYSTEM_COTS_MCAL_ADC_ADC_REG_H_ */
