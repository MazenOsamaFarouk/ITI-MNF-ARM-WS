/*
 * OS_interface.h
 *
 *  Created on: Oct 24, 2022
 *      Author: mazen
 */

#ifndef OS_OS_INTERFACE_H_
#define OS_OS_INTERFACE_H_

typedef enum
{
	RUNNING,
	READY,
	SUSPENDED,
	DELETED,
}TaskState_t;


void OS_vTaskCreate(u8 priority,
				  u8 periodicity ,
				  void (*TaskCode)(void));

void OS_vStartSchdeuler(void);


/* Assignement */
void OS_vTaskDelete(u8 priority);
void OS_vTaskSuspend(u8 priority);


#endif /* OS_OS_INTERFACE_H_ */
