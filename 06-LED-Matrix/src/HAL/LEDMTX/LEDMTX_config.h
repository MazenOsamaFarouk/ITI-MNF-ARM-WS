/*
 * LEDMTX_config.h
 *
 *  Created on: Oct 22, 2022
 *      Author: mazen
 */

#ifndef HAL_LEDMTX_LEDMTX_CONFIG_H_
#define HAL_LEDMTX_LEDMTX_CONFIG_H_

#define NO_ROWS     8
#define NO_COLS		8

#define HORIZONTAL_SCAN_TIME  2500

/*
 * Alternative definition for pins:
#define LEDMTX_ROW1_PIN   GPIO_PORTA,GPIO_PIN0

for example :
	GPIO_vWritePinDirection(LEDMTX_ROW1_PIN, OUTPUT_2MHZ_GPPP);
*/

#endif /* HAL_LEDMTX_LEDMTX_CONFIG_H_ */
