/*
 * S2P_config.c
 *
 *  Created on: Oct 29, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"



GPIO_Config_t Shift_pin = {

GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT, GPIO_2MHZ,GPIO_NOPULL ,GPIO_PP, GPIO_GP

};

GPIO_Config_t Latch_pin = {

GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT, GPIO_2MHZ,GPIO_NOPULL ,GPIO_PP, GPIO_GP

};

GPIO_Config_t Data_pin = {

GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT, GPIO_2MHZ,GPIO_NOPULL ,GPIO_PP, GPIO_GP

};


