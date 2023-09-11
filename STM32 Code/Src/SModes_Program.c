/*
 * SModes_Program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Windows 10
 */

/******************************************************************/
/************  		       INCLUDES	        		 **************/
/******************************************************************/
#include "SModes_Interface.h"
#include "SMode_Config.h"
#include <STD_TYPES.h>

#include "HCSR04_Interface.h"
#include "IR_Interface.h"
#include "MotorDriver_Interface.h"
#include "Buzzer_Interface.h"
#include "CLCD_interface.h"
#include "APP_GUI.h"
#include "UART_Interface.h"

/******************************************************************/
/****************  		Global Variables		 ******************/
/******************************************************************/
State_t Current_State  = Idle_State;
u32 Global_u8Speed = 0;

/******************************************************************/
/************  		Functions Implementation	     **************/
/******************************************************************/
/** Idle Mode **/
State_t SModes_UDIdleMode(void)
{
	Global_u8Speed = 0 ;

	Buzzer_ON();
	MotorDriver_voidControlSpeed(Global_u8Speed);

	/* Display The Mode */
	CLCD_voidSendStringPosition("Idle Mode", 0, 0);
	CLCD_voidSendStringPosition("STOP  ", 0, 10);


	/**  Check the distance **/
	u32 Local_Distance = 0;

	Local_Distance = HAL_HCSR04_f32Read(HCSR04_SENSOR1);

	if(Local_Distance > 95)
	{
		Local_Distance = 100;
	}

	/* Display The Distance */
	CLCD_voidSendStringPosition("Distance= ", 1, 0);
	CLCD_voidPrintINTNumber(Local_Distance);

	/*************************************************/
	GUI_voidSendSpeedDistance(Global_u8Speed, Local_Distance);
	/*************************************************/


	if(Local_Distance > HighDistance)
	{
		Current_State = MovingHighSpeed_State;
	}
	else if((Local_Distance <= HighDistance) && (Local_Distance >= LowDistance))
	{
		Current_State = MovingLowSpeed_State;
	}
	else
	{
		Current_State = Idle_State;
	}

	/**  Check IR Sensors **/
	u8 Local_RightValue = IR_u8Read_RightIR();
	u8 Local_LeftValue = IR_u8Read_LeftIR();
	if((Local_RightValue == Black) && (Local_LeftValue == Black))
	{
		Current_State = Idle_State;
		CLCD_voidSendStringPosition(" ", 1, 12);
	}
	else
	{
		CLCD_voidSendStringPosition(" ", 1, 11);
	}

	/* Display The Speed */
	CLCD_voidSendStringPosition(" ", 1, 15);
	CLCD_voidSendStringPosition("S", 1, 13);
	CLCD_voidPrintINTNumber(Global_u8Speed);


	return Current_State;
}
















/** High Speed Mode **/
State_t SModes_UDMovingHighSpeed_Mode(void)
{
	/* Display The Mode */
	CLCD_voidSendStringPosition("High Mode", 0, 0);

	Buzzer_Off();

	/* Check about the speed */
	if (Global_u8Speed >= HighSpeed)
	{
		Global_u8Speed = 100;
	}
	else
	{
		Global_u8Speed+=2;
	}


	/* Control on the speed (Current Speed)*/
	MotorDriver_voidControlSpeed(Global_u8Speed);

	/**  Check the distance **/
	u32 Local_Distance = 0;

	Local_Distance = HAL_HCSR04_f32Read(HCSR04_SENSOR1);

	if(Local_Distance > 95)
	{
		Local_Distance = 100;
	}

	/* Display The Distance */
	CLCD_voidSendStringPosition("Distance= ", 1, 0);
	CLCD_voidPrintINTNumber(Local_Distance);
	CLCD_voidSendStringPosition(" ", 1, 12);

	/*************************************************/
	GUI_voidSendSpeedDistance(Global_u8Speed, Local_Distance);
	/*************************************************/

	if(Local_Distance < LowDistance)
	{
		Current_State = Idle_State;
	}
	else if((Local_Distance <= HighDistance) && (Local_Distance >= LowDistance))
	{
		Current_State = MovingLowSpeed_State;
	}
	/*else
    {
        Current_State = MovingHighSpeed_State;
    }*/

	/**  Check IR Sensors **/
	u8 Local_RightValue = IR_u8Read_RightIR();
	u8 Local_LeftValue = IR_u8Read_LeftIR();

	if((Local_RightValue == White) && (Local_LeftValue == White))
	{
		/* Turn off the Warning */
		Buzzer_Off();

		/* Move Forward */
		MotorDriver_voidMoveForward();

		CLCD_voidSendStringPosition("FORWA ", 0, 10);
	}
	else if((Local_LeftValue == Black) && (Local_RightValue == White))
	{
		/*Warning*/
		Buzzer_ON();

		/* Turn Right */
		MotorDriver_voidMoveRight();

		CLCD_voidSendStringPosition("TRIGHT", 0, 10);
	}
	else if((Local_RightValue == Black) && (Local_LeftValue == White))
	{
		/*Warning*/
		Buzzer_ON();

		/* Turn Left */
		MotorDriver_voidMoveLeft();

		CLCD_voidSendStringPosition("TLEFT ", 0, 10);
	}
	else
	{
		Current_State = Idle_State;
	}

	CLCD_voidSendStringPosition("S", 1, 13);
	CLCD_voidPrintINTNumber(Global_u8Speed);



	return Current_State;
}















/** Low Speed Mode **/
State_t SModes_UDMovingLowSpeed_Mode(void)
{
	/* Display The Mode */
	CLCD_voidSendStringPosition(" Low Mode", 0, 0);
	Buzzer_Off();

	/* Check about the speed */
	if (Global_u8Speed == LowSpeed)
	{
		Global_u8Speed = LowSpeed;
	}
	else if(Global_u8Speed < LowSpeed)
	{
		Global_u8Speed+=2;
	}
	else if(Global_u8Speed > LowSpeed)
	{
		Global_u8Speed--;
	}

	/* Control on the speed (Current Speed)*/
	MotorDriver_voidControlSpeed(Global_u8Speed);

	/**  Check the distance **/
	u32 Local_Distance = 0;

	Local_Distance = HAL_HCSR04_f32Read(HCSR04_SENSOR1);

	if(Local_Distance > 95)
	{
		Local_Distance = 100;
	}


	/* Display The Distance */
	CLCD_voidSendStringPosition("Distance= ", 1, 0);
	CLCD_voidPrintINTNumber(Local_Distance);
	CLCD_voidSendStringPosition(" ", 1, 12);

	/*************************************************/
	GUI_voidSendSpeedDistance(Global_u8Speed, Local_Distance);
	/*************************************************/


	if(Local_Distance > HighDistance)
	{
		Current_State = MovingHighSpeed_State;
	}
	else if(Local_Distance < LowDistance)
	{
		Current_State = Idle_State;
	}
	/*else
    {
        Current_State = MovingLowSpeed_State;
    }*/

	/**  Check IR Sensors **/
	u8 Local_RightValue = IR_u8Read_RightIR();
	u8 Local_LeftValue = IR_u8Read_LeftIR();

	if((Local_RightValue == White) && (Local_LeftValue == White))
	{
		/* Turn off the Warning */
		Buzzer_Off();

		/* Move Forward */
		MotorDriver_voidMoveForward();

		CLCD_voidSendStringPosition("FORWA ", 0, 10);
	}
	else if((Local_LeftValue == Black) && (Local_RightValue == White))
	{
		/*Warning*/
		Buzzer_ON();

		/* Turn Right */
		MotorDriver_voidMoveRight();

		CLCD_voidSendStringPosition("TRIGHT", 0, 10);
	}
	else if((Local_RightValue == Black) && (Local_LeftValue == White))
	{
		/*Warning*/
		Buzzer_ON();

		/* Turn Left */
		MotorDriver_voidMoveLeft();

		CLCD_voidSendStringPosition("TLEFT ", 0, 10);
	}
	else
	{
		Current_State = Idle_State;
	}

	/* Display The Speed */
	if(Global_u8Speed < 10 )
	{
		CLCD_voidSendStringPosition(" ", 1, 15);
	}
	CLCD_voidSendStringPosition("S", 1, 13);
	CLCD_voidPrintINTNumber(Global_u8Speed);


	return Current_State;
}
