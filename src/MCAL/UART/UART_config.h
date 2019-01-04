#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/****************************************************/
/*	choose between the following to configure parity*/
/*			UART_DATA_LENGTH_5_MSK					*/
/* 			UART_DATA_LENGTH_6_MSK					*/
/* 			UART_DATA_LENGTH_7_MSK					*/
/* 			UART_DATA_LENGTH_8_MSK					*/
/****************************************************/
#define UART_DATA_LENGTH	UART_DATA_LENGTH_8_MSK

/****************************************************/
/*	choose between the following to configure parity*/
/*			UART_PARITY_MODE_DISABLE				*/
/* 			UART_PARITY_MODE_EVEN					*/
/* 			UART_PARITY_MODE_ODD					*/
/****************************************************/
#define UART_PARITY_MODE_MASK	UART_PARITY_MODE_DISABLE

/*****************************************************************/
/*	choose between the following to configure number of stop bit*/
/*			UART_STOP_BIT_1_BIT								   */
/* 			UART_STOP_BIT_2_BIT						     	  */
/*************************************************************/
#define UART_STOP_BIT_MASK		UART_STOP_BIT_1_BIT

/*
 * determine received message buffer size
 *
 * */
#define UART_MSG_BUFFER_SIZE		1000




#endif
