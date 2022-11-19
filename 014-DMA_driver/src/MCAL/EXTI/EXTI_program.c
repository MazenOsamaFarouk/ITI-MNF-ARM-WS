/*
 * EXTI_program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

typedef void (*Exti_Callback_t)(void);

static Exti_Callback_t EXTI_Callbacks[16] ;



void EXTI_vInit(void)
{

}

void EXTI_vSetTrigger(EXTI_Line_t A_xLineId,EXTI_Trigger_t A_xTrigger)
{
	switch(A_xTrigger)
	{
	case EXTI_RISING:
		SET_BIT(EXTI->RTSR, A_xLineId);
		CLR_BIT(EXTI->FTSR, A_xLineId);
		break;

	case EXTI_FALLING:
		SET_BIT(EXTI->FTSR, A_xLineId);
		CLR_BIT(EXTI->RTSR, A_xLineId);
		break;

	case EXTI_ONCHANGE:
		SET_BIT(EXTI->RTSR, A_xLineId);
		SET_BIT(EXTI->FTSR, A_xLineId);
		break;
	}
}

void EXTI_vEnableInterrupt(EXTI_Line_t A_xLineId)
{
	SET_BIT(EXTI->IMR, A_xLineId);
}

void EXTI_vDisableInterrupt(EXTI_Line_t A_xLineId)
{
	CLR_BIT(EXTI->IMR, A_xLineId);
}


void EXTI_vRegisterCallback(EXTI_Line_t A_xLineId,
		                    void (*fptr)(void))
{
	if(A_xLineId < 16)
	{
		EXTI_Callbacks[A_xLineId] = fptr ;
	}
}

void EXTI_vTriggerSwInterrupt(EXTI_Line_t A_xLineId)
{
	SET_BIT(EXTI->SWIER, A_xLineId);
}



void EXTI0_IRQHandler(void)
{
	if(EXTI_Callbacks[EXTI_LINE0] != NULL)
	{
		EXTI_Callbacks[EXTI_LINE0]();
	}
//	SET_BIT(EXTI->PR, EXTI_LINE0);
//	EXTI->PR |= (1<<0);
}

void EXTI1_IRQHandler(void)
{
	if(EXTI_Callbacks[EXTI_LINE1] != NULL)
	{
		EXTI_Callbacks[EXTI_LINE1]();
	}
//	SET_BIT(EXTI->PR, EXTI_LINE1);
//	EXTI->PR |= (1<<1);
}







