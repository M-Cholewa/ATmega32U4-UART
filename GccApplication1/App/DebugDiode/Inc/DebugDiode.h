/*
 * DebugDiode.h
 *
 * Created: 05.11.2023 19:48:47
 *  Author: DoDeptania
 */ 


#ifndef DEBUGDIODE_H_
#define DEBUGDIODE_H_


/* Includes ------------------------------------------------------------------*/

/* Public define -------------------------------------------------------------*/
#define DIODE_HIGH					(1)
#define DIODE_LOW					(0)
/* Public macros -------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/

/* Public constants ----------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/
void DebugDiode_Init(void);
void DebugDiode_Write(unsigned char high);

#endif /* DEBUGDIODE_H_ */