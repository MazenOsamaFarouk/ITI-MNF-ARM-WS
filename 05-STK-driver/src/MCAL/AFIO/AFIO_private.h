/*
 * AFIO_private.h
 *
 *  Created on: Oct 21, 2022
 *      Author: mazen
 */

#ifndef MCAL_AFIO_AFIO_PRIVATE_H_
#define MCAL_AFIO_AFIO_PRIVATE_H_

#define AFIO_BASE_REG   0x40010000

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 AFIO_MAPR2;
}AFIO_MemMap_t;


#define AFIO   ((volatile AFIO_MemMap_t*)(AFIO_BASE_REG))


#endif /* MCAL_AFIO_AFIO_PRIVATE_H_ */
