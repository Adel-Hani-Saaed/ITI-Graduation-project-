/**
 * @file main.c
 * @brief Main file for the application.
 */
#include <STD_TYPES.h>
#include "SInit_Interface.h"
#include "SModes_Interface.h"
#include "Buzzer_Interface.h"

/**
 * @brief Main function of the application.
 * @return Returns 0 upon successful execution.
 */
int main(void)
{
	/** Local Variables **/
	State_t Local_Current_State = Idle_State ;

	/** Initialization **/
	SInit_VoidINIT();

	/** Infinity Loop **/
	while(1)
	{
        switch(Local_Current_State)
        {
            case Idle_State           : Local_Current_State = SModes_UDIdleMode();              break;

            case MovingHighSpeed_State: Local_Current_State = SModes_UDMovingHighSpeed_Mode();  break;

            case MovingLowSpeed_State : Local_Current_State = SModes_UDMovingLowSpeed_Mode();   break;

        }
	}

	return 0;
}


/**
 * @brief Delay in milliseconds.
 * @param Copy_32Delay Delay value in milliseconds.
 */
void APP_vDelay_ms(u32 Copy_32Delay) {
	for (u32 i = 0; i < Copy_32Delay * 300; i++) {
		asm("NOP");
	}
}

/**
 * @brief Delay in microseconds.
 * @param Copy_32Delay Delay value in microseconds.
 */
void APP_vDelay_us(u32 Copy_32Delay) {
	for (u32 i = 0; i < Copy_32Delay * 30; i++) {
		asm("NOP");
	}
}
