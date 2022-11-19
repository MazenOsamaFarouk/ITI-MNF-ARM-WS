/*
 * LEDMTX_program.c
 *
 *  Created on: Oct 22, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

#include "../../HAL/S2P/S2P_interface.h"


#include "LEDMTX_interface.h"
#include "LEDMTX_private.h"
#include "LEDMTX_config.h"

extern GPIO_Config_t Col_pins[NO_COLS];
extern GPIO_Config_t Row_pins[NO_ROWS];

void LEDMTX_vInit(void)
{
	/* 1- Init STK:  HSE , AHB/8 -> 1MHZ
	 * 2- Init GPIO */
	STK_vInit();
#if 0
	for(u8 i=0; i<NO_COLS; i++)
	{
		GPIO_vInit(&Col_pins[i]);
	}

	for(u8 i=0; i<NO_ROWS; i++)
	{
		GPIO_vInit(&Row_pins[i]);
	}
#endif

	S2P_vInit();






}

static void disable_all_columns(void)
{
	for(u8 i=0; i<NO_COLS ; i++)
	{
		GPIO_vWritePinValue(Col_pins[i].Port, Col_pins[i].Pin, GPIO_LOW);
	}
}

static void display_row_values(u8 row_value)
{
	for(u8 i=0; i<NO_ROWS; i++)
	{
		GPIO_WritePinValue(Row_pins[i].Port, Row_pins[i].Pin,
					 GET_BIT(row_value, i) );
	}
}

static void activate_column(u8 column_number)
{
	GPIO_vWritePinValue(Col_pins[column_number].Port,
			            Col_pins[column_number].Pin ,
						GPIO_HIGH);
}



void LEDMTX_vDisplayFrame(u8 A_u8RowsArray[], u32 A_u32DisplayTime)
{
	u32 DisplayCount = 0;

	DisplayCount = A_u32DisplayTime ;

	for(u32 j=0; j<DisplayCount ; j++)
	{
		for(u8 i=0; i<NO_COLS; i++)
		{
#if 0
			// disable all columns
			disable_all_columns();
			// display row values
			display_row_values(A_u8RowsArray[i]);
			// activate the current column
			activate_column(i);
			// delay for Horizontal scan time
#endif
			/* HIGH BYTE -> Columns
			 * LOW BYTE  -> ROWS
			 *
			 * [COLUMNS][ROWS]
			 *  */

			S2P_vSendData(0xff00);
			u16 S2P_data = A_u8RowsArray[i] | ((u16)(~(1<<i))<<8) ;
			S2P_vSendData(S2P_data);

			STK_vSetBusyWait(HORIZONTAL_SCAN_TIME);
		}
	}

}








