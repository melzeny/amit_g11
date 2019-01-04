/*
 * DIO_int.h
 *
 *  Created on: Sep 20, 2018
 *      Author: MuhammadElzeiny
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "../../Lib/STD_TYPES.h"
/*PORTA*/
#define DIO_PIN_A0			0
#define DIO_PIN_A1			1
#define DIO_PIN_A2			2
#define DIO_PIN_A3			3
#define DIO_PIN_A4			4
#define DIO_PIN_A5			5
#define DIO_PIN_A6			6
#define DIO_PIN_A7			7

/*PORTB*/
#define DIO_PIN_B0			8
#define DIO_PIN_B1			9
#define DIO_PIN_B2			10
#define DIO_PIN_B3			11
#define DIO_PIN_B4			12
#define DIO_PIN_B5			13
#define DIO_PIN_B6			14
#define DIO_PIN_B7			15

/*PORTC*/
#define DIO_PIN_C0			16
#define DIO_PIN_C1			17
#define DIO_PIN_C2			18
#define DIO_PIN_C3			19
#define DIO_PIN_C4			20
#define DIO_PIN_C5			21
#define DIO_PIN_C6			22
#define DIO_PIN_C7			23

/*PORTD*/
#define DIO_PIN_D0			24
#define DIO_PIN_D1			25
#define DIO_PIN_D2			26
#define DIO_PIN_D3			27
#define DIO_PIN_D4			28
#define DIO_PIN_D5			29
#define DIO_PIN_D6			30
#define DIO_PIN_D7			31

#define DIO_PORT_A			0
#define DIO_PORT_B			1
#define DIO_PORT_C			2
#define DIO_PORT_D			3

typedef enum
{
	DIO_Pin_low,
	DIO_Pin_high
}DIO_PinValue_t;

void DIO_init(void);
void DIO_setPinValue(u8 PinNum, DIO_PinValue_t Value);
DIO_PinValue_t DIO_getPinValue(u8 PinNum);
void DIO_setPortValue(u8 PortNo, u8 PortVal);
u8 DIO_getPortValue(u8 PortNo);
void DIO_togglePin(u8 PinNum);



#endif /* DIO_INT_H_ */
