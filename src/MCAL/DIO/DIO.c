/*
 * DIO_prog.c
 *
 *  Created on: Sep 20, 2018
 *      Author: MuhammadElzeiny
 */

/*TODO: include necessary header files*/
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"

#include "DIO_reg.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO.h"

void DIO_init(void)
{
	/* initialize DIO module by setting DDR registers with PORT direction*/
	DDRA = BIT_CONC(DIO_u8_PIN_DIR_7,DIO_u8_PIN_DIR_6,DIO_u8_PIN_DIR_5,DIO_u8_PIN_DIR_4,DIO_u8_PIN_DIR_3,DIO_u8_PIN_DIR_2,DIO_u8_PIN_DIR_1,DIO_u8_PIN_DIR_0);
	DDRB = BIT_CONC(DIO_u8_PIN_DIR_15,DIO_u8_PIN_DIR_14,DIO_u8_PIN_DIR_13,DIO_u8_PIN_DIR_12,DIO_u8_PIN_DIR_11,DIO_u8_PIN_DIR_10,DIO_u8_PIN_DIR_9,DIO_u8_PIN_DIR_8);
	DDRC = BIT_CONC(DIO_u8_PIN_DIR_23,DIO_u8_PIN_DIR_22,DIO_u8_PIN_DIR_21,DIO_u8_PIN_DIR_20,DIO_u8_PIN_DIR_19,DIO_u8_PIN_DIR_18,DIO_u8_PIN_DIR_17,DIO_u8_PIN_DIR_16);
	DDRD = BIT_CONC(DIO_u8_PIN_DIR_31,DIO_u8_PIN_DIR_30,DIO_u8_PIN_DIR_29,DIO_u8_PIN_DIR_28,DIO_u8_PIN_DIR_27,DIO_u8_PIN_DIR_26,DIO_u8_PIN_DIR_25,DIO_u8_PIN_DIR_24);
}
void DIO_setPinValue(u8 PinNum, DIO_PinValue_t ValueCpy)
{
	/* switch between PORTS,
	 * assign the right bit in corresponding register with ValueCpy */
	if(PinNum <= DIO_u8_PORTA_END)
	{
		/*in PORTA*/
		ASSIGN_BIT(PORTA,PinNum,ValueCpy);	
	}
	else if(PinNum >=DIO_u8_PORTB_START && PinNum <= DIO_u8_PORTB_END)
	{
		/*in PORTB*/
		PinNum -= DIO_u8_PORTB_OFFSET;
		ASSIGN_BIT(PORTB,PinNum,ValueCpy);
		
	}
	else if(PinNum >=DIO_u8_PORTC_START && PinNum <= DIO_u8_PORTC_END)
	{
			/*in PORTC*/
			PinNum -= DIO_u8_PORTC_OFFSET;
			ASSIGN_BIT(PORTC,PinNum,ValueCpy);
			
	}
	else if(PinNum >=DIO_u8_PORTD_START && PinNum <= DIO_u8_PORTD_END)
	{
			/*in PORTD*/
			PinNum -= DIO_u8_PORTD_OFFSET;
			ASSIGN_BIT(PORTD,PinNum,ValueCpy);
				
	}


}
DIO_PinValue_t DIO_getPinValue(u8 PinNum)
{
	DIO_PinValue_t PinValue = DIO_Pin_low;

	/*TODO: switch between PORTS,
	 * get the right bit in corresponding register (PINx)
	 * and assign the value to PinValue*/
		
	if(PinNum <= DIO_u8_PORTA_END)
	{
		/*in PORTA*/
		PinValue = GET_BIT(PINA,PinNum);	
	}
	else if(PinNum >=DIO_u8_PORTB_START && PinNum <= DIO_u8_PORTB_END)
	{
		/*in PORTB*/
		PinNum -= DIO_u8_PORTB_OFFSET;
		PinValue = GET_BIT(PINB,PinNum);
		
	}
	else if(PinNum >=DIO_u8_PORTC_START && PinNum <= DIO_u8_PORTC_END)
	{
			/*in PORTC*/
			PinNum -= DIO_u8_PORTC_OFFSET;
			PinValue = GET_BIT(PINC,PinNum);
			
	}
	else if(PinNum >=DIO_u8_PORTD_START && PinNum <= DIO_u8_PORTD_END)
	{
			/*in PORTD*/
			PinNum -= DIO_u8_PORTD_OFFSET;
			PinValue = GET_BIT(PIND,PinNum);			
	}

	return PinValue;
}

void DIO_setPortValue(u8 PortNo, u8 PortVal)
{
	switch(PortNo)
	{
		case DIO_PORT_A:
		PORTA = PortVal;
		break;
		
		case DIO_PORT_B:
		PORTB = PortVal;
		break;
		
		case DIO_PORT_C:
		PORTC = PortVal;
		break;
		
		case DIO_PORT_D:
		PORTD = PortVal;
		break;
		
		default:
		/*invalid Port no*/
		break;
	}	
}
u8 DIO_getPortValue(u8 PortNo)
{
	u8 PortVal = 0;
		switch(PortNo)
		{
			case DIO_PORT_A:
			PortVal = PINA;
			break;
			
			case DIO_PORT_B:
			PortVal = PINB;
			break;
			
			case DIO_PORT_C:
			PortVal = PINC;
			break;
			
			case DIO_PORT_D:
			PortVal = PIND;
			break;
			
			default:
			/*invalid Port no*/
			break;
		}
	
	return PortVal;
}

void DIO_togglePin(u8 PinNum)
{
	/*TODO: switch between PORTS,
	 * assign the right bit in corresponding register with ValueCpy */
	if(PinNum <= DIO_u8_PORTA_END)
	{
		/*in PORTA*/
		TOGGLE_BIT(PORTA,PinNum);	
	}
	else if(PinNum >=DIO_u8_PORTB_START && PinNum <= DIO_u8_PORTB_END)
	{
		/*in PORTB*/
		PinNum -= DIO_u8_PORTB_OFFSET;
		TOGGLE_BIT(PORTB,PinNum);
		
	}
	else if(PinNum >=DIO_u8_PORTC_START && PinNum <= DIO_u8_PORTC_END)
	{
			/*in PORTC*/
			PinNum -= DIO_u8_PORTC_OFFSET;
			TOGGLE_BIT(PORTC,PinNum);
			
	}
	else if(PinNum >=DIO_u8_PORTD_START && PinNum <= DIO_u8_PORTD_END)
	{
			/*in PORTD*/
			PinNum -= DIO_u8_PORTD_OFFSET;
			TOGGLE_BIT(PORTD,PinNum);			
	}
}


