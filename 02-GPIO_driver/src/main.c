

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

	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN0, OUTPUT_2MHZ_GPPP);


	while(1)
	{
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
		ARM_DELAY(1000);
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
		ARM_DELAY(1000);

	}
}
