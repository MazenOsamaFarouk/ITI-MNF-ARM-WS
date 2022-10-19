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

void GPIO_vInit(GPIO_Config_t* pxGpio)
{
	u8 L_u8Dir = 0;
	if(pxGpio->Mode == mGPIO_OUTPUT)
	{
		L_u8Dir |= pxGpio->OutputSpeed ;
	   // 0b0000[AltFun][OutputType][OutputSpeed]
		if(pxGpio->AltFn != mGPIO_GeneralPurpose)
		{
			SET_BIT(L_u8Dir, 3);
		}
		if(pxGpio->OutputType != mGPIO_PushPull)
		{
			SET_BIT(L_u8Dir, 2);
		}
	}
	else
	{
		// input settings
	}
 L_u8Dir = OUTPUT_2MHZ_GPPP ;

	GPIO_vWritePinDirection(pxGpio->Port, pxGpio->Pin, L_u8Dir);
}



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

// wrapper function-> Adaptor Pattern
void GPIO_vWritePinValue_2(GPIO_Config_t* pxGpio, u8 A_u8Val)
{
	GPIO_vWritePinValue(pxGpio->Port, pxGpio->Pin, A_u8Val);


#if 0
	u8 A_u8PinNo = pxGpio->Pin;
	u8 A_u8PortNo = pxGpio->Port;

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
#endif
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
