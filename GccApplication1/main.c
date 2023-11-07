/*
* GccApplication1.c
*
* Created: 04.11.2023 20:32:16
* Author : DoDeptania
*/
#define F_CPU 16000000UL

#include "App/USART_Driver/Inc/USART_Driver.h"
#include "App/DebugDiode/Inc/DebugDiode.h"
#include "util/delay.h"

int main(void)
{
	USART_Init(9600);
	DebugDiode_Init(); // pro micro D3 pin ( ATmega pin 0 of port D)
	
	unsigned char data = 'A';
	
	while(1){
		DebugDiode_Write(DIODE_HIGH);
		_delay_ms(1000);
		
		// transmit next character
		USART_TransmitByte(data);
		
		if(data == 'Z'){
			data = 'A';
		}
		
		data ++;
		
		DebugDiode_Write(DIODE_LOW);
		_delay_ms(1000);
	}

}

