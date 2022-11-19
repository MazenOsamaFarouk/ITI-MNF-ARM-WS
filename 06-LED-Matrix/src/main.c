
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_interface.h"
#include "HAL/LEDMTX/LEDMTX_interface.h"

#include "HAL/S2P/S2P_interface.h"

u8  SSD_numbers[] = {
		0b0011100011,
		0b0011100011,
		0b0011100011,
		0b0011100011,
		0b0011100011,
};

int main(void)
{
	RCC_vInit();
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOA);
	RCC_vEnableClock(RCC_APB2, RCC_EN_GPIOB);

	S2P_vInit();

	for(u8 i=0; i<10 ; i++)
	{
		S2P_vSendData(SSD_numbers[i]);
		/* delay */
	}

	u8 Frame[8] = {0, 126, 4, 8, 4, 126, 0, 0};

	LEDMTX_vInit();

	while(1)
	{
		LEDMTX_vDisplayFrame(Frame, 10);
	}
}
