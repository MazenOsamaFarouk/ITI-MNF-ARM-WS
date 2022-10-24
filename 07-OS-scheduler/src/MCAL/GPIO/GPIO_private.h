/*
 * GPIO_private.h
 *
 *  Created on: Oct 17, 2022
 *      Author: mazen
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDR		0x40010800
#define GPIOB_BASE_ADDR		0x40010C00
#define GPIOC_BASE_ADDR		0x40011000


typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_MemMap_t;

#define GPIOA     ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDR))
#define GPIOB     ((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDR))





#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
