/*
 * USART_Driver.h
 *
 * Created: 04.11.2023 23:03:48
 *  Author: DoDeptania
 */ 


#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_


/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
/* Public define -------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/

/* Public constants ----------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/
void USART_Init( uint32_t baud );
unsigned char USART_ReceiveByte( void );
void USART_TransmitByte( unsigned char data );


#endif /* USART_DRIVER_H_ */