/*
 * UART_prog.c
 *
 *  Created on: Apr 23, 2018
 *      Author: MuhammadElzeiny
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_reg.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART.h"

static u8 RecievedMessage[UART_MSG_BUFFER_SIZE] ={0} ;
static u16 MsgLength =0 ;

void  UART_init(void)
{
	/*set URSEL to one to access UCSRC register*/
	//SET_BIT(UCSRC,URSEL);

	/*configure parity mode*/
	UCSRC &= UART_PARITY_MODE_CLEAR_MSK;
	UCSRC |= UART_PARITY_MODE_MASK;

	/*configure stop bit*/
	UCSRC &= UART_STOP_BIT_CLEAR;
	UCSRC |= UART_STOP_BIT_MASK;
	/*set baud rate to 9600 baud/s*/
	UBRRL = 51;
	/*set data length*/

	UCSRC |= 1<<URSEL	|	1<<UCSZ0	|	1<<UCSZ1	;
	/*
	UCSRC &= UART_DATA_LENGTH_CLR_MSK;
	UCSRC |= UART_DATA_LENGTH;
	*/
	/*enable receive*/
	SET_BIT(UCSRB,RXEN);
	/*enable transmit*/
	SET_BIT(UCSRB,TXEN);
}

void UART_sendByte(u8 DataToSendCpy)
{
	/*wait until UDR is ready*/
	while(GET_BIT(UCSRA,UDRE) == 0);
	/*write data to be transmitted in UDR*/
	UDR = DataToSendCpy;
	/*clear flag*/
	SET_BIT(UCSRA,TXC);
}

void UART_getMessage(u8* MsgPtr,u16* LengthPtr)
{
	u8 i;
	for(i=0;i<MsgLength;i++)
	{
		MsgPtr[i]= RecievedMessage[i];
	}
	*LengthPtr = MsgLength;
	MsgLength =0 ;

}


void UART_enRxInterrupt(void)
{
	/*enable receive complete interrupt*/
	SET_BIT(UCSRB,RXCIE);

}

void UART_enTxInterrupt(void)
{
	/*enable transmit complete interrupt*/
	SET_BIT(UCSRB,TXCIE);

}
void UART_enRegReadyInterrupt(void)
{
	/*enable interrupt of UDR empty */
	SET_BIT(UCSRB,UDRIE);

}


void UART_diRxInterrupt(void)
{
	/*disable receive complete interrupt*/
	CLR_BIT(UCSRB,RXCIE);
}

void UART_diTxInterrupt(void)
{
	/*disable transmit complete interrupt*/
	CLR_BIT(UCSRB,TXCIE);


}
void UART_diRegReadyInterrupt(void)
{
	/*disable interrupt of UDR empty */
	CLR_BIT(UCSRB,UDRIE);
}


/*ISR for receive complete interrupt*/
void __vector_13(void) __attribute__((signal,used));
void __vector_13(void)
{
	RecievedMessage[MsgLength]=UDR;
	MsgLength++;

}
