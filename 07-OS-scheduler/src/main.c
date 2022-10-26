
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "OS/OS_interface.h"


void Task_Led1(void)
{
//	GPIO_TogglePin(GPIO_PORTA, GPIO_PIN0);
}


void Task_Led2(void)
{
//	GPIO_TogglePin(GPIO_PORTA, GPIO_PIN0);
}


void Task_Led3(void)
{
//	GPIO_TogglePin(GPIO_PORTA, GPIO_PIN0);
}


volatile u8 SSD_number = 0 ;

void Task_SSD_MUX(void) // 10ms
{
	/* extract units/tens digit */
	/* send it to corresponding SSD */
	static u8 units = 0 ;

	if(units)
	{
		SSD_DisplayNumber(SSD_number%10 , SSD_1);
		units = 0;
	}
	else
	{
		SSD_DisplayNumber(SSD_number/10 , SSD_2);
		units = 1;
	}


}


void Task_SSD_Update(void) // 1 sec
{
	SSD_number++ ;
}




int main(void)
{
	RCC_vInit();
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOA);

	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN0, OUTPUT_2MHZ_GPPP);
	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN1, OUTPUT_2MHZ_GPPP);
	GPIO_vWritePinDirection(GPIO_PORTA, GPIO_PIN2, OUTPUT_2MHZ_GPPP);

//	OS_vTaskCreate(0,250,1,Task_Led1);
//	OS_vTaskCreate(1,500,2,Task_Led2);
//	OS_vTaskCreate(2,1000,3,Task_Led3);

	/**
	 * Seven segment code
	 */
	OS_vTaskCreate(0,10,1,Task_SSD_MUX);
	OS_vTaskCreate(1,1000,2,Task_SSD_Update);



	OS_vStartSchdeuler();

}
