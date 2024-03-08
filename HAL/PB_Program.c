/*
 * PB_Program.c
 *
 * Created: 3/8/2024 5:05:50 PM
 *  Author: Ahmed Mohammed
 */ 

#include "common.h"
#include "DIO_interface.h"
#include "PB_Interface.h"

void PB_voidInit(PB_DIOPort_t copy_enumPBPort, PB_DIOPin_t copy_enumPBPin, PB_InputType_t copy_enumPBInputType)
{
	u8 local_u8PBPort = 0, local_u8PBPin = 0;
	
	switch(copy_enumPBPort)
	{
		case PB_PORTA:
		local_u8PBPort = DIO_PORTA;
		break;
		
		case PB_PORTB:
		local_u8PBPort = DIO_PORTB;
		break;
		
		case PB_PORTC:
		local_u8PBPort = DIO_PORTC;
		break;
		
		case PB_PORTD:
		local_u8PBPort = DIO_PORTD;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch (copy_enumPBPin)
	{
		case PB_PIN0:
		local_u8PBPin = DIO_PIN0;
		break;
		
		case PB_PIN1:
		local_u8PBPin = DIO_PIN1;
		break;
		
		case PB_PIN2:
		local_u8PBPin = DIO_PIN2;
		break;
		
		case PB_PIN3:
		local_u8PBPin = DIO_PIN3;
		break;
		
		case PB_PIN4:
		local_u8PBPin = DIO_PIN4;
		break;
		
		case PB_PIN5:
		local_u8PBPin = DIO_PIN5;
		break;
		
		case PB_PIN6:
		local_u8PBPin = DIO_PIN6;
		break;
		
		case PB_PIN7:
		local_u8PBPin = DIO_PIN7;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	DIO_voidSetPinValue(local_u8PBPort, local_u8PBPin, DIO_PIN_INPUT);
	if (PB_PullUpResistor == copy_enumPBInputType)
	{
		DIO_voidActivePinInPullUpResistance(local_u8PBPort, local_u8PBPin);
	}
}

bool PB_boolIsPressed(PB_DIOPort_t copy_enumPBPort, PB_DIOPin_t copy_enumPBPin, PB_Type_t copy_enumPBType)
{
	u8 local_u8PBPort = 0, local_u8PBPin = 0;
	bool local_boolPBValue;
	
	switch(copy_enumPBPort)
	{
		case PB_PORTA:
		local_u8PBPort = DIO_PORTA;
		break;
		
		case PB_PORTB:
		local_u8PBPort = DIO_PORTB;
		break;
		
		case PB_PORTC:
		local_u8PBPort = DIO_PORTC;
		break;
		
		case PB_PORTD:
		local_u8PBPort = DIO_PORTD;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch (copy_enumPBPin)
	{
		case PB_PIN0:
		local_u8PBPin = DIO_PIN0;
		break;
		
		case PB_PIN1:
		local_u8PBPin = DIO_PIN1;
		break;
		
		case PB_PIN2:
		local_u8PBPin = DIO_PIN2;
		break;
		
		case PB_PIN3:
		local_u8PBPin = DIO_PIN3;
		break;
		
		case PB_PIN4:
		local_u8PBPin = DIO_PIN4;
		break;
		
		case PB_PIN5:
		local_u8PBPin = DIO_PIN5;
		break;
		
		case PB_PIN6:
		local_u8PBPin = DIO_PIN6;
		break;
		
		case PB_PIN7:
		local_u8PBPin = DIO_PIN7;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	DIO_voidGetPinValue(local_u8PBPort, local_u8PBPin, &local_boolPBValue);
	
	return local_boolPBValue == (bool)copy_enumPBType;
}