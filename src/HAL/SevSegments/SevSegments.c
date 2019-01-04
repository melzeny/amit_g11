/*
 * SevSegments.c
 *
 * Created: 10/19/2018 6:57:29 PM
 *  Author: MuhammadElzeiny
 */ 
#include "../../Lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"

#include "SevSegments_Priv.h"
#include "SevSegments_config.h"
#include "SevSegments.h"
void SevSegments_enable(void)
{
	#if (SEVSEGMENTS_COMMON_TYPE == SEVSEGMENTS_COMMON_CATHOD)
		/*set enable pin Low*/
		DIO_setPinValue(SEVSEGMENTS_COMMON_PIN,DIO_Pin_low);
	#else
		/*set enable pin High*/
		DIO_setPinValue(SEVSEGMENTS_COMMON_PIN,DIO_Pin_high);
	#endif
}
void SevSegments_disable(void)
{
		#if (SEVSEGMENTS_COMMON_TYPE == SEVSEGMENTS_COMMON_CATHOD)
		/*set enable pin Low*/
		DIO_setPinValue(SEVSEGMENTS_COMMON_PIN,DIO_Pin_high);
		#else
		/*set enable pin High*/
		DIO_setPinValue(SEVSEGMENTS_COMMON_PIN,DIO_Pin_low);
		#endif
	
}
void SevSegments_displayNo(u8 Val)
{
	u8 EncodedValue;
	switch(Val)
	{
		case 0:
			EncodedValue = 0b00111111;
			break;
		case 1:
			EncodedValue = 0b00000110;
			break;
		case 2:
			EncodedValue = 0b01011011;
			break;
		case 3:
			EncodedValue = 0b01001111;
			break;
		case 4:
			EncodedValue = 0b01100110;
			break;
		case 5:
			EncodedValue = 0b01101101;
			break;
		case 6:
			EncodedValue = 0b01111101;
			break;
		case 7:
			EncodedValue = 0b00000111;
			break;
		case 8:
			EncodedValue = 0b01111111;
			break;
		case 9:
			EncodedValue = 0b01101111;
			break;
		default:
			EncodedValue = 0b00000000;
			break;
	}
		#if (SEVSEGMENTS_COMMON_TYPE == SEVSEGMENTS_COMMON_CATHOD)
			DIO_setPortValue(SEVSEGMENTS_ATTACHED_PORT,EncodedValue);
		#else
			DIO_setPortValue(SEVSEGMENTS_ATTACHED_PORT,~EncodedValue);
		#endif
	
}