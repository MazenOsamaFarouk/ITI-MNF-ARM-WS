/*
 * OS_private.h
 *
 *  Created on: Oct 24, 2022
 *      Author: mazen
 */

#ifndef OS_OS_PRIVATE_H_
#define OS_OS_PRIVATE_H_

typedef struct
{
	u8 periodicity;
	u8 TaskState ;
	u16 InitDelay ;
	void (*TaskCode)(void);
}Task_t;



#endif /* OS_OS_PRIVATE_H_ */
