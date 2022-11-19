/*
 * DMA_private.h
 *
 *  Created on: Nov 16, 2022
 *      Author: mazen
 */

#ifndef MCAL_DMA_DMA_PRIVATE_H_
#define MCAL_DMA_DMA_PRIVATE_H_

#define DMA1_BASE_ADDR		0x40020000

#define BIT_MEM2MEM     14


typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 reserved;
}DMA_Channel_t;


typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel_t Channel[7];

}DMA_MemMap_t;

#define DMA1       ((volatile DMA_MemMap_t*)(DMA1_BASE_ADDR))


#endif /* MCAL_DMA_DMA_PRIVATE_H_ */
