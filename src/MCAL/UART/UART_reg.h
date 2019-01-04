/*
 * UART_reg.h
 *
 *  Created on: Apr 23, 2018
 *      Author: MuhammadElzeiny
 */

#ifndef SYSTEM_COTS_MCAL_UART_UART_REG_H_
#define SYSTEM_COTS_MCAL_UART_UART_REG_H_

#define UBRRH			*((u8*)0x40)
#define UCSRC			*((u8*)0x40)

#define UDR				*((u8*)0x2C)
#define UCSRA			*((u8*)0x2B)
#define UCSRB			*((u8*)0x2A)
#define UBRRL			*((u8*)0x29)


/*bits of UCSRA*/
#define UDRE			5
#define TXC				6
#define RXC				7

/*bit in UCSRB*/
#define RXCIE			7
#define TXCIE			6
#define UDRIE 			5
#define RXEN			4
#define TXEN			3
#define UCSZ2			2
#define RXB8			1
#define TXB8			0
/*bits in UCSRC*/
#define URSEL			7
#define UCSZ0			1
#define UCSZ1			2

#endif /* SYSTEM_COTS_MCAL_UART_UART_REG_H_ */
