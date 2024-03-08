/*
 * PB_Interface.h
 *
 * Created: 3/8/2024 5:05:32 PM
 *  Author: Ahmed Mohammed
 */ 


#ifndef PB_INTERFACE_H_
#define PB_INTERFACE_H_

#include "common.h"

#include "DIO_interface.h"

typedef enum
{
	PB_PORTA = 0,
	PB_PORTB,
	PB_PORTC,
	PB_PORTD
	
} PB_DIOPort_t;

typedef enum
{
	PB_PIN0 = 0,
	PB_PIN1,
	PB_PIN2,
	PB_PIN3,
	PB_PIN4,
	PB_PIN5,
	PB_PIN6,
	PB_PIN7
	
} PB_DIOPin_t;

typedef enum
{
	PB_Floating = 0,
	PB_PullUpResistor
	
} PB_InputType_t;

typedef enum
{
	PB_ActiveLow = false,
	PB_ActiveHigh = true
	
} PB_Type_t;


void PB_voidInit(PB_DIOPort_t copy_enumPBPort, PB_DIOPin_t copy_enumPBPin, PB_InputType_t copy_enumPBInputType);
bool PB_boolIsPressed(PB_DIOPort_t copy_enumPBPort, PB_DIOPin_t copy_enumPBPin, PB_Type_t copy_enumPBType);



#endif /* PB_INTERFACE_H_ */