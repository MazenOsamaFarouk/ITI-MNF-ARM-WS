

#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/STK/STK_interface.h"

void toggle(void)
{
	static u8 flag = 0;
	if(flag)
	{
		flag = 0;

	}
	else
	{
		flag = 1;
	}

}

int main(void)
{
	RCC_vInit();
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOA);

	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN0, OUTPUT_2MHZ_GPPP);
	STK_vInit();
	STK_vSetInterval_periodic(1000000, toggle);

	while(1)
	{
//		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
//		STK_vSetBusyWait(1000000);
//		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
//		STK_vSetBusyWait(1000000);
	}
}
