/*
 * APP_GUI.c
 *
 *  Created on: Aug 12, 2023
 *      Author: A-plus store
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include <stdlib.h> // for itoa

#include "MCAL_RCC_Interface.h"
#include "MCAL_GPIO_Interface.h"
#include "UART_Interface.h"
#include "APP_GUI.h"


u8 D[10];

u8 S[10];

u8 array[22];

void GUI_voidInit(void)
{


	//TX->PA9  RX->PA10
	GPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_MODE_AF_PP);
	GPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_MODE_AF_PP);
	GPIO_voidSetPinALTF(GPIO_PORTA, GPIO_PIN9, GPIO_AF7_USART1_USART2_SPI1);
	GPIO_voidSetPinALTF(GPIO_PORTA, GPIO_PIN10,GPIO_AF7_USART1_USART2_SPI1);

	UART_voidInit();
}


void GUI_voidSendSpeedDistance(u32 Copy_u8Speed , u32 Copy_u8_Distance )
{

	//Sending motor speed and distance to raspberry pi

	u8 loop, index, S_len, D_len;

	S_len = D_len = 10;

	index = 0;

	/*Convert Speed int to Speed Str*/
	itoa (Copy_u8Speed, S, 10);
	for(loop = 0; loop < S_len; loop++)
	{
		array[index] = S[loop];
		index++;
	}

	array[index]=' ';
	index++;

	/*Convert Distance int to Distance Str*/
	itoa (Copy_u8_Distance, D, 10);
	for(loop = 0; loop < D_len; loop++)
	{
		array[index] = D[loop];
		index++;
	}
	array[index]='\r';
	index++;

	UART_voidTransmit( array , 22);

	array[0]='\0';
	S[0]='\0';
	D[0]='\0';
}
