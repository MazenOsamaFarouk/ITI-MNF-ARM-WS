/*
 * GPIO_program.c
 *
 *  Created on: Oct 17, 2022
 *      Author: mazen
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"



#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"





void GPIO_vWritePinDirection(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8Dir)
{
	switch(A_u8PortNo)
	{
	case GPIO_PORTA:
		if(A_u8PinNo<8)
		{
			GPIOA->CRL &=~ ((0b1111)<< (A_u8PinNo*4));
			GPIOA->CRL |= (A_u8Dir << (A_u8PinNo*4));
		}
		else if(A_u8PinNo <16)
		{
			GPIOA->CRH &=~ ((0b1111)<< ((A_u8PinNo-8)*4));
			GPIOA->CRH |= (A_u8Dir << ((A_u8PinNo-8)*4));
		}
		break;
	}
}

void GPIO_vWritePinValue(u8 A_u8PortNo, u8 A_u8PinNo,u8 A_u8Val)
{
	if(A_u8PinNo < 16)
	{
		if(A_u8Val == GPIO_HIGH)
		{
			switch(A_u8PortNo)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->ODR,A_u8PinNo );
				break;
			}
		}
		else if(A_u8Val == GPIO_LOW)
		{
			switch(A_u8PortNo)
			{
			case GPIO_PORTA:
				CLR_BIT(GPIOA->ODR,A_u8PinNo );
				break;
			}
		}
	}
}

u8   GPIO_u8GetPinValue(u8 A_u8PortNo,u8 A_u8PinNo)
{
	u8 L_u8Return = 0;

	if(A_u8PinNo< 16)
	{
		switch(A_u8PortNo)
		{
		case GPIO_PORTA:
			L_u8Return = GET_BIT(GPIOA->IDR,A_u8PinNo );
			break;

		case GPIO_PORTB:
			L_u8Return = GET_BIT(GPIOB->IDR,A_u8PinNo );
			break;
		}
	}



	return L_u8Return;

}


//------------------------------------------------------------
void GPIO_vWritePortDirection_High(u8 A_u8PortNo,u32 A_u8Dir)
{

}

void GPIO_vWritePortDirection_Low (u8 A_u8PortNo,u32 A_u8Dir)
{

}

void GPIO_vWritePortValue_High(u8 A_u8PortNo,u8 A_u8Val)
{

}

void GPIO_vWritePortValue_Low (u8 A_u8PortNo,u8 A_u8Val)
{

}
