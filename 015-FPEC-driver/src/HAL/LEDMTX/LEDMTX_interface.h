/*
 * LEDMTX_interface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: mazen
 */

#ifndef HAL_LEDMTX_LEDMTX_INTERFACE_H_
#define HAL_LEDMTX_LEDMTX_INTERFACE_H_


void LEDMTX_vInit(void);
void LEDMTX_vDisplayFrame(u8 A_u8RowsArray[], u32 A_u32DisplayTime);

/* ***************************** */
void LEDMTX_vDisplayMatrix(u8 A_u8Matrix[][8] , u32 A_u32DisplayTime);



#endif /* HAL_LEDMTX_LEDMTX_INTERFACE_H_ */
