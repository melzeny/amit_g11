/*
 * Keypad.c
 *
 * Created: 10/20/2018 5:31:35 PM
 *  Author: MuhammadElzeiny
 */
#include "../../Lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "Keypad_config.h"
#include "Keypad.h"
static u8 Keypad_PressedButton = 0; 

void Keypad_init(void)
{
	DIO_setPinValue(KEYPAD_PIN_COL0,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_COL1,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_COL2,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_COL3,DIO_Pin_high);
	
}

static void Keypad_checKCol(u8 ActiveRowNo)
{
	if(DIO_getPinValue(KEYPAD_PIN_COL0) == DIO_Pin_low)
	{
		Keypad_PressedButton = ActiveRowNo*4;
	}
	else if(DIO_getPinValue(KEYPAD_PIN_COL1) == DIO_Pin_low)
	{
		Keypad_PressedButton = (ActiveRowNo*4)+1;
	}
	else if(DIO_getPinValue(KEYPAD_PIN_COL2) == DIO_Pin_low)
	{
		Keypad_PressedButton = (ActiveRowNo*4)+2;
	}
	else if(DIO_getPinValue(KEYPAD_PIN_COL3) == DIO_Pin_low)
	{
		Keypad_PressedButton = (ActiveRowNo*4)+3;
	}
}

u8 Keypad_getPressedButton(void)
{
	Keypad_PressedButton = -1;
	/*row0 activated*/
	DIO_setPinValue(KEYPAD_PIN_R0,DIO_Pin_low); /*activate*/
	DIO_setPinValue(KEYPAD_PIN_R1,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_R2,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_R3,DIO_Pin_high);
	Keypad_checKCol(0);
	
	/*row1 activated*/
	DIO_setPinValue(KEYPAD_PIN_R0,DIO_Pin_high); 
	DIO_setPinValue(KEYPAD_PIN_R1,DIO_Pin_low);
	DIO_setPinValue(KEYPAD_PIN_R2,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_R3,DIO_Pin_high);
	Keypad_checKCol(1);
	
	/*row2 activated*/
	DIO_setPinValue(KEYPAD_PIN_R0,DIO_Pin_high); 
	DIO_setPinValue(KEYPAD_PIN_R1,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_R2,DIO_Pin_low);
	DIO_setPinValue(KEYPAD_PIN_R3,DIO_Pin_high);
	Keypad_checKCol(2);
	
	/*row3 activated*/
	DIO_setPinValue(KEYPAD_PIN_R0,DIO_Pin_high); 
	DIO_setPinValue(KEYPAD_PIN_R1,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_R2,DIO_Pin_high);
	DIO_setPinValue(KEYPAD_PIN_R3,DIO_Pin_low);
	Keypad_checKCol(3);
	
	return Keypad_PressedButton;
}
