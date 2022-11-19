/*
 * FPEC_private.h
 *
 *  Created on: Nov 19, 2022
 *      Author: mazen
 */

#ifndef MCAL_FPEC_FPEC_PRIVATE_H_
#define MCAL_FPEC_FPEC_PRIVATE_H_

#define FPEC_BASE_ADDR  0x40022000

typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 reserved;
	u32 OBR;
	u32 WRPR;
}FPEC_MemMap_t;

#define FPEC    ((volatile FPEC_MemMap_t*)(FPEC_BASE_ADDR))


#endif /* MCAL_FPEC_FPEC_PRIVATE_H_ */
