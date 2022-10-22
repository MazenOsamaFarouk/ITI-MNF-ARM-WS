/*
 * AFIO_program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"



void AFIO_vSetExtiPin(u8 Port,  u8 ExtiLine)
{
	u8 L_u8Index = ExtiLine / 4 ;
	u8 L_u8ShiftAmount = (4*(ExtiLine%4));
	AFIO->EXTICR[L_u8Index] &=~(0b1111)<<L_u8ShiftAmount ;
	AFIO->EXTICR[L_u8Index] |= (Port)<<L_u8ShiftAmount ;
}
