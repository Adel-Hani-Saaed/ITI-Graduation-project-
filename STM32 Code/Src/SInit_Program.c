/*
 * SInit_Program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Windows 10
 */

/******************************************************************/
/************  		       INCLUDES	        		 **************/
/******************************************************************/
#include "SInit_Interface.h"

#include "CORE_NVIC_Interface.h"
#include "MCAL_RCC_Interface.h"
#include "MCAL_STK_Interface.h"
#include "MCAL_TIM_Interface.h"


#include "HCSR04_Interface.h"
#include "IR_Interface.h"
#include "MotorDriver_Interface.h"
#include "Buzzer_Interface.h"
#include "CLCD_interface.h"
#include "Timer_Delay.h"


/******************************************************************/
/************  		Functions Implementation	     **************/
/******************************************************************/
void SInit_VoidINIT(void)
{
	//MCL_RCC_vInitSysClk(&RCC_G_Config); // Initialize the system clock

	MCL_RCC_vInitSysClk(&RCC_G_Config); // Initialize the system clock

	MCL_RCC_vEnablePeriphClk(AHB1_BUS, 0 );	 //Enable POERTA

	MCL_RCC_vEnablePeriphClk(APB2_BUS, 4 );  //Enable UART

	MCL_STK_vInit(&STK_G_Config); // Initialize the SysTick timer

	TimerDelay_Init(); // Initialize the timer delay

	HAL_HCSR04_vInit(&HCSR04_CfgParam[HCSR04_SENSOR1], &US_htim2); // Initialize the HCSR04 sensor

	MotorDriver_voidInit(); // Initialize the motor driver

	IR_Init(); // Initialize the IR sensor

	CLCD_voidInit(); //Initialize the LCD

	Buzzer_Init(); //Initialize the Buzzer

	GUI_voidInit(); //UART INIT
}
