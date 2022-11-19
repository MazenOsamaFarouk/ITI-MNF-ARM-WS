
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"

#include "FreeRTOS.h"
#include "task.h"

void Task_Led1(void* pv)
{
	(void)pv; // to silence the unused variable warning in compiler
	while(1)
	{
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
		/* OS delay  */
		vTaskDelay(500);
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
		/* OS delay  */
		vTaskDelay(500);
	}
}

void Task_Led2(void* pv)
{
	(void)pv; // to silence the unused variable warning in compiler
	while(1)
	{
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
		/* OS delay  */
		vTaskDelay(250);
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
		/* OS delay  */
		vTaskDelay(250);
	}
}

void Task_Led3(void* pv)
{
	(void)pv; // to silence the unused variable warning in compiler
	while(1)
	{
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
		/* OS delay  */
		vTaskDelay(1000);
		GPIO_vWritePinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
		/* OS delay  */
		vTaskDelay(1000);
	}
}



int main(void)
{
	RCC_vInit();
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOA);

	GPIO_Config_t ledpins[3] = {
			{GPIO_PORTA, GPIO_PIN0, OUTPUT_2MHZ_GPPP},
			{GPIO_PORTA, GPIO_PIN1, OUTPUT_2MHZ_GPPP},
			{GPIO_PORTA, GPIO_PIN2, OUTPUT_2MHZ_GPPP},
	};

	for(u8 i=0; i<3; i++)
	{
		GPIO_vInit(&ledpins[i]);
	}

	xTaskCreate(Task_Led1,NULL,200,NULL,1,NULL);
	xTaskCreate(Task_Led2,NULL,200,NULL,2,NULL);
	xTaskCreate(Task_Led3,NULL,200,NULL,3,NULL);


	vTaskStartScheduler();





	while(1)
	{

	}
}
