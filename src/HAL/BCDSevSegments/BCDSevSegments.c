/*
 * BCDSevSegments.c
 *
 * Created: 10/19/2018 4:55:28 PM
 *  Author: MuhammadElzeiny
 */ 

#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "BCDSevSegments_Priv.h"
#include "BCDSevSegments_config.h"
#include "BCDSevSegments.h"

void BCDSevSegments_enable(void)
{
	DIO_setPinValue(BCDSEVSEGMENTS_Enable_PIN,DIO_Pin_high);
	
}
void BCDSevSegments_disable(void)
{
	DIO_setPinValue(BCDSEVSEGMENTS_Enable_PIN,DIO_Pin_low);
}
void BCDSevSegments_displayNo(u8 Val)
{
	if(Val <= 15)
	{
	DIO_setPinValue(BCDSEVSEGMENTS_PIN_0,GET_BIT(Val,0));
	DIO_setPinValue(BCDSEVSEGMENTS_PIN_1,GET_BIT(Val,1));
	DIO_setPinValue(BCDSEVSEGMENTS_PIN_2,GET_BIT(Val,2));
	DIO_setPinValue(BCDSEVSEGMENTS_PIN_3,GET_BIT(Val,3));
	}
}

