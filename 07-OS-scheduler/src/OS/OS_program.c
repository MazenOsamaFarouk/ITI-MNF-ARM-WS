/*
 * OS_program.c
 *
 *  Created on: Oct 24, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/STK/STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


static Task_t OS_Tasks[NO_TASKS];

void Scheduler(void)
{
#if 0
	static u32 TickCount = 0 ;
	TickCount++ ;

	for(u32 i=0; i<NO_TASKS; i++)
	{
		if(OS_Tasks[i].TaskState == READY)
		{
			if(TickCount % OS_Tasks[i].periodicity == 0)
			{
				OS_Tasks[i].TaskCode();
			}
		}
	}
#endif

	for(u32 i=0; i<NO_TASKS; i++)
	{
		if(OS_Tasks[i].TaskState == READY)
		{
			if(OS_Tasks[i].InitDelay == 0)
			{
				OS_Tasks[i].InitDelay = OS_Tasks[i].periodicity ;
				OS_Tasks[i].TaskCode();
			}
			else
			{
				OS_Tasks[i].InitDelay-- ;
			}
		}
	}
}


void OS_vTaskCreate(u8 priority,
				  u8 periodicity ,
				  u16 initDelay,
				  void (*TaskCode)(void))
{
	OS_Tasks[priority].periodicity = periodicity ;
	OS_Tasks[priority].TaskCode    = TaskCode  ;
	OS_Tasks[priority].InitDelay   = initDelay  ;
	OS_Tasks[priority].TaskState   = READY ;
}


void OS_vStartSchdeuler(void)
{
	STK_vInit();
	STK_vSetInterval_periodic(OS_TIME_BASE, Scheduler);

	while(1)
	{

	}
}







