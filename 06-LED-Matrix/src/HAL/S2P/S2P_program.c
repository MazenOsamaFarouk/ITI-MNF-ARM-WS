

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

#include "S2P_interface.h"
#include "S2P_private.h"
#include "S2P_config.h"


extern GPIO_Config_t Data_pin ;
extern GPIO_Config_t Latch_pin;
extern GPIO_Config_t Shift_pin;

void S2P_vInit(void)
{
	/* init Shift pin , Serial data pin and Latch pin */
	GPIO_vInit(&Shift_pin);
	GPIO_vInit(&Latch_pin);
	GPIO_vInit(&Data_pin);
}

static void Shift_Data(void)
{
	GPIO_vWritePinValue(Shift_pin.Port, Shift_pin.Pin, GPIO_HIGH);
	STK_vSetBusyWait(1);
	GPIO_vWritePinValue(Shift_pin.Port, Shift_pin.Pin, GPIO_LOW);
	STK_vSetBusyWait(1);
}

static void Latch_Data(void)
{
	GPIO_vWritePinValue(Latch_pin.Port, Latch_pin.Pin, GPIO_HIGH);
	STK_vSetBusyWait(1);
	GPIO_vWritePinValue(Latch_pin.Port, Latch_pin.Pin, GPIO_LOW);
	STK_vSetBusyWait(1);
}

void S2P_vSendData(u32 A_u32Data)
{
	for(u32 i=0; i<NO_REGS*8; i++)
	{
		GPIO_vWritePinValue(Data_pin.Port,
				            Data_pin.Pin,
							GET_BIT(A_u32Data, i));

		/* shift bit value into register */
		Shift_Data();
	}
	Latch_Data();
}
