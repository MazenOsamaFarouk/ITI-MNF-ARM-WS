/*
 * STK_private.h
 *
 *  Created on: Oct 22, 2022
 *      Author: mazen
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

#define ENABLE 1
#define DISABLE 0


#define STK_BASE_ADDR	0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_MemMap_t;

#define STK  ((volatile STK_MemMap_t*)(STK_BASE_ADDR))



#endif /* MCAL_STK_STK_PRIVATE_H_ */
