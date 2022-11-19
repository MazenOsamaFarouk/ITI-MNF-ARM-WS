/*
 * RCC_interface.h
 *
 *  Created on: Oct 12, 2022
 *      Author: mazen
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2


#define RCC_EN_GPIOA   2



void RCC_vInit(void);
void RCC_vEnableClock( u8 A_u8BusId,
       				   u16 A_u16PeripheralId);
void RCC_vDisableClock( u8 A_u8BusId,
       				   u16 A_u16PeripheralId);


#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
