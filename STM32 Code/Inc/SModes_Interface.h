/*
 * SModes_Interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Windows 10
 */

#ifndef SMODES_INTERFACE_H_
#define SMODES_INTERFACE_H_

/******************************************************************/
/****************  		Global Variables		 ******************/
/******************************************************************/
typedef enum{
    Idle_State,
    MovingHighSpeed_State,
    MovingLowSpeed_State
}State_t;



/******************************************************************/
/************  		Functions Prototypes			 **************/
/******************************************************************/
State_t SModes_UDIdleMode(void);
State_t SModes_UDMovingHighSpeed_Mode(void);
State_t SModes_UDMovingLowSpeed_Mode(void);



#endif /* SMODES_INTERFACE_H_ */
