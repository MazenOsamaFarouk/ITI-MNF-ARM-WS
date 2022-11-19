/*
 * NVIC_interface.h
 *
 *  Created on: Oct 19, 2022
 *      Author: mazen
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_


#define NVIC_EN_EXTI0    6
#define NVIC_EN_EXTI1    7

void NVIC_vInit(void);
void NVIC_vEnableInterrupt(u8 A_u8InterruptId);
void NVIC_vDisableInterrupt(u8 A_u8InterruptId);

void NVIC_vSetPendingFlag(u8 A_u8InterruptId);
void NVIC_vClrPendingFlag(u8 A_u8InterruptId);
u8   NVIC_u8GetActiveFlag(u8 A_u8InterruptId);

void NVIC_vSetSwPriority(u8 A_u8InterruptId, u8 A_u8Priority);




#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
