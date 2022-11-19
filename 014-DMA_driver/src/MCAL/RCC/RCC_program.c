/*
 * RCC_program.c
 *
 *  Created on: Oct 12, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_vInit(void)
{

	RCC_CR |=  0x00010000 ;
	RCC_CFGR = 0x00000001  ;

	/* HSE settings */
	// 2- HSE BYPASS ?
	// 1- HSE ON ?

	/* HSI settings */
	// - HSITRIM ?
	// - HSION ?


	/* PLL settings */
	// 1- PLLON ?
	// 2- PLLSRC ? -> HSI/2, HSE/2 , HSE ?
	// 3- PLLMUL ? 2:16 but DO NOT EXCEED 72 MHZ


	/* other settings */
	// - CSS ON ?
	// - MCO ?
	// - AHB, APB1, APB2 Prescalers ?
	// - ADC_PRESCALER ?


	/* SYSCLK settings */
	// SYSTEM CLOCK Switch bits: HSI/HSE/PLL


}

void RCC_vEnableClock( u8 A_u8BusId,
       				   u16 A_u16PeripheralId)
{
	switch(A_u8BusId)
	{
	case RCC_AHB:
		SET_BIT(RCC_AHBENR, A_u16PeripheralId);
		break;
	case RCC_APB1:
		SET_BIT(RCC_APB1ENR,A_u16PeripheralId);
		break;


	}


}

void RCC_vDisableClock( u8 A_u8BusId,
       				   u16 A_u16PeripheralId)
{

}
