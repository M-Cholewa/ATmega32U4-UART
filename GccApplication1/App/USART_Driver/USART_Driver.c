/*
* USART_Driver.c
*
* Created: 04.11.2023 23:03:32
*  Author: DoDeptania
*/

/********************** NOTES *************************************************
...
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "Inc/USART_Driver.h"
#include <avr/io.h>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/* Private define ------------------------------------------------------------*/
#define F_CPU 16000000UL // TODO: Move it somewhere else

/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function declaration ----------------------------------------------*/

/* Public functions definition -----------------------------------------------*/

void USART_Init( uint32_t baud )
{
	baud = (F_CPU/(16*baud)) - 1;
	
	/* Set baud rate */
	UBRR1H = (unsigned char)(baud>>8);
	UBRR1L = (unsigned char)baud;

	/* Enable receiver and transmitter */
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	/* Set frame format: 8data, 1stop bit */
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10);
}

unsigned char USART_ReceiveByte( void )
{
	/* Wait for data to be received */
	while ( !(UCSR1A & (1<<RXC1)) )
	;
	/* Get and return received data from buffer */
	return UDR1;
}

void USART_TransmitByte( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE1)) );
	/* Put data into buffer, sends the data */
	UDR1 = data;

}

/* Private functions definition ----------------------------------------------*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>