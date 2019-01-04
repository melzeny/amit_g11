/*
 * UART_int.h
 *
 *  Created on: Apr 23, 2018
 *      Author: MuhammadElzeiny
 */

#ifndef SYSTEM_COTS_MCAL_UART_UART_INT_H_
#define SYSTEM_COTS_MCAL_UART_UART_INT_H_


void UART_init(void);
void UART_sendByte(u8 DataToSendCpy);
void UART_getMessage(u8* MsgPtr,u16* Length);

void UART_enRxInterrupt(void);
void UART_enTxInterrupt(void);
void UART_enRegReadyInterrupt(void);

void UART_diRxInterrupt(void);
void UART_diTxInterrupt(void);
void UART_diRegReadyInterrupt(void);


#endif /* SYSTEM_COTS_MCAL_UART_UART_INT_H_ */
