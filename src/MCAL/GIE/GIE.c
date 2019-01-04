/*
 * GIE.c
 *
 *  Created on: Oct 2, 2018
 *      Author: MuhammadElzeiny
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_reg.h"
#include "GIE.h"

void GIE_enInterrupt(void)
{
	SET_BIT(SREG,7);
}
void GIE_diInterrupt(void)
{
	CLR_BIT(SREG,7);
}

