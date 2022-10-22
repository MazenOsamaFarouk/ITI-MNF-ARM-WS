
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"

void exti0_cb(void)
{
//	GPIO_vTogglePin(GPIO_PORTA, GPIO_PIN1);
static volatile	u8 x = 5;
//	EXTI_vTriggerSwInterrupt(EXTI_LINE1);
	NVIC_vSetPendingFlag(NVIC_EN_EXTI1);
	x++;
	x++;
	NVIC_vClrPendingFlag(NVIC_EN_EXTI0);
}

void exti1_cb(void)
{
static volatile	u8 y = 10 ;
	y++;
	y++;
	NVIC_vClrPendingFlag(NVIC_EN_EXTI1);

}

#define RCC_EN_AFIO    0

int main(void)
{
	RCC_vInit();
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOA);
	RCC_vEnableClock(RCC_APB2, RCC_EN_AFIO);

	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN1, 0b1000);
	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN0, 0b1000); //INPUT_PULLUP
	GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH); // enable pull up
	GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);

	EXTI_vRegisterCallback(EXTI_LINE0, exti0_cb);
	EXTI_vSetTrigger(EXTI_LINE0, EXTI_RISING);
	EXTI_vEnableInterrupt(EXTI_LINE0);

	EXTI_vRegisterCallback(EXTI_LINE1, exti1_cb);
	EXTI_vSetTrigger(EXTI_LINE1, EXTI_RISING);
	EXTI_vEnableInterrupt(EXTI_LINE1);

	NVIC_vInit();
	NVIC_vSetSwPriority(NVIC_EN_EXTI0, 2);
	NVIC_vSetSwPriority(NVIC_EN_EXTI1, 1);
	NVIC_vEnableInterrupt(NVIC_EN_EXTI0);
	NVIC_vEnableInterrupt(NVIC_EN_EXTI1);


	NVIC_vSetPendingFlag(NVIC_EN_EXTI0);
//	EXTI_vTriggerSwInterrupt(EXTI_LINE0);
//	EXTI_vTriggerSwInterrupt(EXTI_LINE1);

	while(1)
	{

	}
}
