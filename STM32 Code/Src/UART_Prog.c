/*
 * UART_Prog.c
 *
 *  Created on: Jun 7, 2023
 *      Author: Dina
 */


#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"LERROR_STATES.h"
#include"stm32f401xx.h"
#include "STM32F4xx_Device_Header.h"
#include"MCAL_GPIO_Interface.h"
#include "CORE_NVIC_Interface.h"

#include"UART_Config.h"
#include"UART_Interface.h"
#include"UART_Private.h"



/*Global pointer to carry the conversion result in the Asynchronous execution*/
static u8 * UART1_pu16AsynchReading = NULL;
static void (* UART1_CallBack) (void) = NULL ;

u8  G_u8AMessage[10] = {0};

void  UART_voidInit(void)
{
	//Enable Tx
	SET_BIT(UART1->CR1,3);
	//Enable Rx
	SET_BIT(UART1->CR1,2);
	// select Word length (8-bit)
	CLEAR_BIT(UART1->CR1,12);
	//select Buad Rate (9600)->BRR - CLK ->16MHz
	UART1->BRR=0x683 ;
	//Enable UART
	SET_BIT(UART1->CR1,13);



}

void  UART_voidTransmit(u8 *Copyu8_Frame,u8 Copyu8_BlockSize)
{

	for(u8 i=0;i<Copyu8_BlockSize;i++)
	{
		while(!GET_BIT(UART1->SR,6));
		UART1->DR=Copyu8_Frame[i];
	}
}
u8  UART_voidRecieve(void)
{
	static u8 Copyu8_RChar;

	while((!GET_BIT(UART1->SR,5)));
	Copyu8_RChar=(UART1->DR & 0xFF);

	return  Copyu8_RChar;
}


void UART_voidReciveAsyn( u8 *Copy_pu8Reading   ,  void(*Copy_PvNotificationFunction)(void))
{
	if (Copy_pu8Reading != NULL || Copy_PvNotificationFunction != NULL)
	{

		UART1_pu16AsynchReading = Copy_pu8Reading;

		UART1_CallBack= Copy_PvNotificationFunction ;

		/*Enable NVIC*/
		COR_NVIC_vEnableInterrupt(USART1_IRQn);

		/*Enable Interrupt*/
		SET_BIT(UART1->CR1,5);
	}
}


void USART1_IRQHandler(void)
{
	UART1_CallBack();

	*UART1_pu16AsynchReading = (UART1->DR);

	/*Clear flag RXEN*/
	CLEAR_BIT(UART1->SR,5);
}

