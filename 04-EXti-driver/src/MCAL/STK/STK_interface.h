/*
 * STK_inerface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: mazen
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_

void STK_vInit(void);
void STK_vSetBusyWait(u32 A_u32TimerTicks);
void STK_vSetInterval_single(u32 A_u32TimerTicks, void (*fptr)(void) );
void STK_vSetInterval_periodic(u32 A_u32TimerTicks, void (*fptr)(void) );
void STK_VStopInterval(void);
u32  STK_u32GetElapsedTime(void);
u32  STK_u32GetRemainingTime(void);




#endif /* MCAL_STK_STK_INTERFACE_H_ */
