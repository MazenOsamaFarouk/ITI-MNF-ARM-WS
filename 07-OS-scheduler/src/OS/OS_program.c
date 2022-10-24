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
}


void OS_vTaskCreate(u8 priority,
				  u8 periodicity ,
				  void (*TaskCode)(void))
{
	OS_Tasks[priority].periodicity = periodicity ;
	OS_Tasks[priority].TaskCode    = TaskCode  ;
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







