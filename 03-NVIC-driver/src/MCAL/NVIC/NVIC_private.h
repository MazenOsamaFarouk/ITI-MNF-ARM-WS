/*
 * NVIC_private.h
 *
 *  Created on: Oct 19, 2022
 *      Author: mazen
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS  0xE000E100

#define NVIC_REG32_DEF(offset)    *((volatile u32*)(NVIC_BASE_ADDRESS+offset))

#define NVIC_ISER0   NVIC_REG32_DEF(0x000)
#define NVIC_ISER1   NVIC_REG32_DEF(0x004)
#define NVIC_ISER2   NVIC_REG32_DEF(0x008)

#define NVIC_ICER0   NVIC_REG32_DEF(0x080)
#define NVIC_ICER1   NVIC_REG32_DEF(0x084)
#define NVIC_ICER2   NVIC_REG32_DEF(0x088)

#define NVIC_ISPR0   NVIC_REG32_DEF(0x100)
#define NVIC_ISPR1   NVIC_REG32_DEF(0x104)
#define NVIC_ISPR2   NVIC_REG32_DEF(0x108)

#define NVIC_ICPR0   NVIC_REG32_DEF(0x180)
#define NVIC_ICPR1   NVIC_REG32_DEF(0x184)
#define NVIC_ICPR2   NVIC_REG32_DEF(0x188)

#define NVIC_IABR0   NVIC_REG32_DEF(0x200)
#define NVIC_IABR1   NVIC_REG32_DEF(0x204)
#define NVIC_IABR2   NVIC_REG32_DEF(0x208)

#define NVIC_IPR	((volatile u8*)(NVIC_BASE_ADDRESS+0x300))

















/*
typedef struct
{

}NVIC_MemMap_t;



#define NVIC    ((volatile NVIC_MemMap_t*)(NVIC_BASE_ADDRESS))
*/


#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
