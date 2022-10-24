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


typedef enum
{
	mGPIO_PORTA,
	mGPIO_PORTB,
	mGPIO_PORTC
}GPIO_Port_t;

typedef enum
{
	mGPIO_PIN0,
	mGPIO_PIN1,

}GPIO_Pin_t;

typedef enum
{
	mGPIO_NOSPEED=0b00,
	mGPIO_2MHZ=0b10,
	mGPIO_10MHZ=0b01,
	mGPIO_50MHZ=0b11
}GPIO_OutputSpeed_t;

typedef enum
{
	mGPIO_INPUT,
	mGPIO_OUTPUT
}GPIO_Mode_t;

#define mGPIO_PushPull     0
#define mGPIO_GeneralPurpose 0


typedef struct
{
	GPIO_Port_t Port;
	GPIO_Pin_t Pin;
	GPIO_Mode_t Mode;
	GPIO_OutputSpeed_t OutputSpeed;
	u8 OutputType; // PushPull=0 , OpenDrain=1
	u8 InputType;  // PULL_UP=0b11, PULL_DOWN=0b10, FLOATING=0b01 , ANALOG=0b00
	u8 AltFn; // GPIO=0, ALTFUNC=1
}GPIO_Config_t;


void GPIO_vInit(GPIO_Config_t* pxGpio);
void GPIO_vWritePinValue_2(GPIO_Config_t* pxGpio, u8 A_u8Val);


void GPIO_vWritePinDirection(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8Dir);
void GPIO_vWritePinValue(u8 A_u8PortNo, u8 A_u8PinNo,u8 A_u8Val);
u8   GPIO_u8GetPinValue(u8 A_u8PortNo,u8 A_u8PinNo);
void GPIO_vWritePortDirection_High(u8 A_u8PortNo,u32 A_u8Dir);
void GPIO_vWritePortDirection_Low (u8 A_u8PortNo,u32 A_u8Dir);
void GPIO_vWritePortValue_High(u8 A_u8PortNo,u8 A_u8Val);
void GPIO_vWritePortValue_Low (u8 A_u8PortNo,u8 A_u8Val);





#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
