/*
 * EXTI_interface.h
 *
 *  Created on: Oct 21, 2022
 *      Author: mazen
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum
{
	EXTI_FALLING,
	EXTI_RISING,
	EXTI_ONCHANGE
}EXTI_Trigger_t;

typedef enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2
}EXTI_Line_t;


void EXTI_vInit(void);
void EXTI_vSetTrigger(EXTI_Line_t A_xLineId,EXTI_Trigger_t A_xTrigger);
void EXTI_vEnableInterrupt(EXTI_Line_t A_xLineId);
void EXTI_vDisableInterrupt(EXTI_Line_t A_xLineId);
void EXTI_vRegisterCallback(EXTI_Line_t A_xLineId,
		                    void (*fptr)(void));
void EXTI_vTriggerSwInterrupt(EXTI_Line_t A_xLineId);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
