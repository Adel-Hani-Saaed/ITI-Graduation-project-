/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: CLCD			  *******************/
/*************** Date: 12/2/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* Description: LCD Mode Configuration */
/* Range      : 1- MODE_8_BIT
 * 				2- MODE_4_BIT  */
#define CLCD_MODE  MODE_4_BIT

/************************************************************************/
/********************* PORT/PINs configurations for LCD *****************/
/************************************************************************/
/* Description: LCD DATA port configuration */
/* Range      : GPIOA ~ GPIOC */

#define CLCD_DATA_PORT				GPIOA

/*********************************************************
 * Description: LCD DATA PINS in 4 bits mode Configuration
 ********************************************************/
#define CLCD_DATA_PIN_ONE   	   	GPIO_PIN5
#define CLCD_DATA_PIN_TWO   	    GPIO_PIN8
#define CLCD_DATA_PIN_THREE         GPIO_PIN14
#define CLCD_DATA_PIN_FOUR          GPIO_PIN15

/* Description: LCD Control port configuration */
/* Range      : GPIOA ~ GPIOC */
#define CLCD_CTRL_PORT				GPIOA

/*Description: LCD RS pin */
/* Range     : DIO_PIN0 ~ DIO_PIN7 */
#define CLCD_RS_PIN					GPIO_PIN11

/*Description: LCD RW pin (Connection with GND because we always Write in LCD )*/
/* Range     : DIO_PIN0 ~ DIO_PIN7 */
#define CLCD_RW_PIN					GPIO_PIN12

/*Description: LCD E pin */
/* Range     : DIO_PIN0 ~ DIO_PIN7 */
#define CLCD_E_PIN					GPIO_PIN13

#endif /* CLCD_CONFIG_H_ */
