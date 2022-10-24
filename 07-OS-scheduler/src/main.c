
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "OS/OS_interface.h"


void Task_Led1(void)
{
	GPIO_TogglePin(GPIO_PORTA, GPIO_PIN0);
}


void Task_Led2(void)
{
	GPIO_TogglePin(GPIO_PORTA, GPIO_PIN0);
}


void Task_Led3(void)
{
	GPIO_TogglePin(GPIO_PORTA, GPIO_PIN0);
}


int main(void)
{
	RCC_vInit();
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOA);

	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN0, OUTPUT_2MHZ_GPPP);
	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN1, OUTPUT_2MHZ_GPPP);
	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN2, OUTPUT_2MHZ_GPPP);

	OS_vTaskCreate(0,250,Task_Led1);
	OS_vTaskCreate(0,500,Task_Led2);
	OS_vTaskCreate(0,1000,Task_Led3);

	OS_vStartSchdeuler();

}
