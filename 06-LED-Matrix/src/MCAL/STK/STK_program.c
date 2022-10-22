/*
 * STK_program.c
 *
 *  Created on: Oct 22, 2022
 *      Author: mazen
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


static void (*STK_Callback)(void);
static u8 single_flag = 0;

void STK_vInit(void)
{
	/* 1- Clock source selection */
	CLR_BIT(STK->CTRL, 2); // CLKSRC
	/* 2- Interrupt enable/ disable */
#if STK_INTERRUPT_ENABLE==ENABLE
	SET_BIT(STK->CTRL, 1); // TICKINT
#elif STK_INTERRUPT_ENABLE==DISABLE
	CLR_BIT(STK->CTRL, 1); // TICKINT
#endif

}

void STK_vSetBusyWait(u32 A_u32TimerTicks)
{
	/* 1- CLEAR Timer VAL register */
	STK->VAL = 0;
	/* 2- Reload the Timer Ticks in LOAD register */
	STK->LOAD = A_u32TimerTicks;
	/* 3- Start timer  */
	SET_BIT(STK->CTRL, 0); // ENABLE
	/* 4- Poll (wait) on COUNTFLAG */
	while(GET_BIT(STK->CTRL, 16) != 1){}
	/* 5- Stop timer and Clear COUNTFLAG */
	CLR_BIT(STK->CTRL, 0); // ENABLE
	STK->VAL = 0;
}

void STK_vSetInterval_single(u32 A_u32TimerTicks, void (*fptr)(void) )
{
	single_flag = 1 ;
	/* 0- register the Callback function */
	STK_Callback = fptr ;
	/* 1- CLEAR Timer VAL register */
		STK->VAL = 0;
		/* 2- Reload the Timer Ticks in LOAD register */
		STK->LOAD = A_u32TimerTicks;
		/* 3- Start timer  */
		SET_BIT(STK->CTRL, 0); // ENABLE
}

void STK_vSetInterval_periodic(u32 A_u32TimerTicks, void (*fptr)(void) )
{
	single_flag = 0;
	/* 0- register the Callback function */
	STK_Callback = fptr ;
	/* 1- CLEAR Timer VAL register */
		STK->VAL = 0;
		/* 2- Reload the Timer Ticks in LOAD register */
		STK->LOAD = A_u32TimerTicks;
		/* 3- Start timer  */
		SET_BIT(STK->CTRL, 0); // ENABLE
}

void STK_VStopInterval(void)
{
	CLR_BIT(STK->CTRL, 0);
}


u32  STK_u32GetElapsedTime(void)
{
	return (STK->LOAD - STK->VAL) ;
}

u32  STK_u32GetRemainingTime(void)
{
	return (STK->VAL) ;
}

void SysTick_Handler(void)
{
	if(STK_Callback != NULL)
	{
		if(single_flag)
		{
			single_flag = 0;
			STK->VAL = 0;
			CLR_BIT(STK->CTRL, 0); //ENABLE BIT
		}
		STK_Callback();
	}
}




