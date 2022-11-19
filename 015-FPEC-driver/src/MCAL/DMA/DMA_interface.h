/*
 * DMA_interface.h
 *
 *  Created on: Nov 16, 2022
 *      Author: mazen
 */

#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_

enum Priority
{
	PR_LOW=0b00,
	PR_MED=0b01,
	PR_HIGH=0b10,
	PR_VHIGH=0b11
};

enum ElementSize
{
	SZ_8bits,
	SZ_16bits,
	SZ_32bits
};

enum Direction
{
	ReadFromPeripheral,
	ReadFromMemory
};

enum Status
{
	DISABLE,ENABLE
};

typedef struct
{
	u16 Memory2Memory 	:1 ;
	u16 PriorityLevel 	:2 ;
	u16 MemorySize    	:2 ;
	u16 PeripheralSize  :2 ;
	u16 MemoryIncrement :1 ;
	u16 PeripheralIncrement :1 ;
	u16 CircularMode    :1;
	u16 DataDirection   :1;
	u16 TransferErrorInterruptEnable :1;
	u16 HalfTransferInterruptEnable :1 ;
	u16 TransferInterruptEnable :1;
}DMA_Config_t;

void DMA_vConfigureChannel(u8 ChannelNo, DMA_Config_t* dma);
void DMA_vStartTransfer(u8 ChannelNo,
						u32* src,
						u32* dest,
						u16  number_of_elements);
void DMA_vSetCallback(u8 ChannelNo , void (*fptr)(void));



#endif /* MCAL_DMA_DMA_INTERFACE_H_ */
