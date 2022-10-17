/*
 * GPIO_interface.h
 *
 *  Created on: Oct 17, 2022
 *      Author: mazen
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#define GPIO_PORTA           0
#define GPIO_PORTB			 1
#define GPIO_PORTC			 2

#define GPIO_PIN0			0
#define GPIO_PIN1			1
#define GPIO_PIN2			2
#define GPIO_PIN3			3
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0
//#define GPIO_PIN0			0




#define GPIO_HIGH			 1
#define GPIO_LOW			 0


#define OUTPUT_2MHZ_GPPP    0b0010




void GPIO_vWritePinDirection(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8Dir);
void GPIO_vWritePinValue(u8 A_u8PortNo, u8 A_u8PinNo,u8 A_u8Val);
u8   GPIO_u8GetPinValue(u8 A_u8PortNo,u8 A_u8PinNo);
void GPIO_vWritePortDirection_High(u8 A_u8PortNo,u32 A_u8Dir);
void GPIO_vWritePortDirection_Low (u8 A_u8PortNo,u32 A_u8Dir);
void GPIO_vWritePortValue_High(u8 A_u8PortNo,u8 A_u8Val);
void GPIO_vWritePortValue_Low (u8 A_u8PortNo,u8 A_u8Val);





#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
