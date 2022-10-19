/*
 * NVIC_program.c
 *
 *  Created on: Oct 19, 2022
 *      Author: mazen
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_vInit(void)
{

}

void NVIC_vEnableInterrupt(u8 A_u8InterruptId)
{
	if(A_u8InterruptId <32 )
	{
		SET_BIT(NVIC_ISER0, A_u8InterruptId);
	}
	else if(A_u8InterruptId <60)
	{
		SET_BIT(NVIC_ISER1, A_u8InterruptId-32);
	}
}

void NVIC_vDisableInterrupt(u8 A_u8InterruptId)
{
	if(A_u8InterruptId <32 )
	{
		SET_BIT(NVIC_ICER0, A_u8InterruptId);
	}
	else if(A_u8InterruptId <60)
	{
		SET_BIT(NVIC_ICER1, A_u8InterruptId-32);
	}
}


void NVIC_vSetPendingFlag(u8 A_u8InterruptId)
{
	if(A_u8InterruptId <32 )
	{
		SET_BIT(NVIC_ISPR0, A_u8InterruptId);
	}
	else if(A_u8InterruptId <60)
	{
		SET_BIT(NVIC_ISPR1, A_u8InterruptId-32);
	}
}

void NVIC_vClrPendingFlag(u8 A_u8InterruptId)
{
	if(A_u8InterruptId <32 )
	{
		SET_BIT(NVIC_ICPR0, A_u8InterruptId);
	}
	else if(A_u8InterruptId <60)
	{
		SET_BIT(NVIC_ICPR1, A_u8InterruptId-32);
	}
}

u8   NVIC_u8GetActiveFlag(u8 A_u8InterruptId)
{
	u8 L_u8Active = 0;
	if(A_u8InterruptId <32 )
	{
		L_u8Active = GET_BIT(NVIC_IABR0, A_u8InterruptId);
	}
	else if(A_u8InterruptId <60)
	{
		L_u8Active = GET_BIT(NVIC_IABR1, A_u8InterruptId-32);
	}
	return L_u8Active;
}

void NVIC_vSetSwPriority(u8 A_u8InterruptId, u8 A_u8Priority)
{

}
