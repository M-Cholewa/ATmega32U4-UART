/*
* DebugDiode.c
*
* Created: 05.11.2023 19:48:37
*  Author: DoDeptania
*/

/********************** NOTES *************************************************
...
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "Inc/DebugDiode.h"
#include <avr/io.h>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#ifdef USERLIB_USE_ENABLED // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/* Private define ------------------------------------------------------------*/
#define DIODE_PIN					(0) // pin 0 of port D
/* Private macros ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function declaration ----------------------------------------------*/

/* Public functions definition -----------------------------------------------*/
void DebugDiode_Init(void)
{
	DDRD |= (1 << DDD0); // set pin 0 as Output (Arduino D3)
}

void DebugDiode_Write(unsigned char high)
{
	if(high>0){
		// drive HIGH
		PORTD |= (1<<PORTD0);
	}else{
		// drive LOW
		PORTD &= ~(1<<PORTD0);
	}
}
/* Private functions definition ----------------------------------------------*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif /* USERLIB_USE_ENABLED */ // plik.c
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>