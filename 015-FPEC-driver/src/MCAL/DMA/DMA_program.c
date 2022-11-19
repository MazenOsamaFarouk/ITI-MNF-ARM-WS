/*
 * DMA_program.c
 *
 *  Created on: Nov 16, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_vConfigureChannel(u8 ChannelNo, DMA_Config_t* dma)
{
	if(ChannelNo < 7)
	{
		u16 CCR_setting;
		CCR_setting = ((dma->Memory2Memory)<<BIT_MEM2MEM  |
				       (dma->PriorityLevel)<<12           |
					   (dma->MemorySize   )<<10           |
					   (dma->PeripheralSize)<<8           |
					   (dma->MemoryIncrement)<<7          |
					   (dma->PeripheralIncrement)<<6      |
					   (dma->CircularMode)   <<5          |
					   (dma->DataDirection)  <<4          |
					   (dma->TransferErrorInterruptEnable)<<3|
					   (dma->HalfTransferInterruptEnable)<<2 |
					   (dma->TransferInterruptEnable)<<1)  ;


		DMA1->Channel[ChannelNo].CCR |= CCR_setting ;
	}
}

void DMA_vStartTransfer(u8 ChannelNo,
						u32* src,
						u32* dest,
						u16  number_of_elements)
{
	if(ChannelNo < 7)
	{
		DMA1->Channel[ChannelNo].CPAR = (u32)src ;
		DMA1->Channel[ChannelNo].CPAR = dest ;
		DMA1->Channel[ChannelNo].CNDTR = number_of_elements ;

		SET_BIT(DMA1->Channel[ChannelNo].CCR, 0); // BIT_EN

	}
}


void DMA_vSetCallback(u8 ChannelNo , void (*fptr)(void))
{

}


