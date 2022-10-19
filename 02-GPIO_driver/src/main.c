

#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"


// delay (d) in milli seconds
#define ARM_DELAY(d)    \
	do{ \
	u32 i=500*d; \
	while(i--){asm("nop");} \
}while(0)

#define ARRSZ(arr)   (sizeof(arr)/sizeof(arr[0]))



int main(void)
{
	RCC_vInit(); // HSE, NO PLL, NO PRESCALERS
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOA);

	GPIO_Config_t ledpin = {
			.Port = mGPIO_PORTA,
			.Pin  = mGPIO_PIN0,
			.Mode = mGPIO_OUTPUT,
			.OutputSpeed = mGPIO_2MHZ,
			.OutputType = mGPIO_PushPull,
			.AltFn      = mGPIO_GeneralPurpose
	};

	GPIO_vInit(&ledpin);

	while(1)
	{
		GPIO_vWritePinValue_2(&ledpin, GPIO_HIGH);
		ARM_DELAY(1000);
		GPIO_vWritePinValue_2(&ledpin, GPIO_LOW);
		ARM_DELAY(1000);

	}
}
