/*
 * LED_Program.c
 *
 * Created: 3/8/2024 1:11:27 PM
 *  Author: Ahmed Mohammed
 */ 

#include "common.h"
#include "DIO_interface.h"
#include "LED_Interface.h"

void LED_voidInit(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin)
{
	u8 local_u8LedPort = 0, local_u8LedPin = 0;
	
	switch (copy_enumLedPort)
	{
		case LED_PORTA:
		local_u8LedPort = DIO_PORTA;
		break;
		
		case LED_PORTB:
		local_u8LedPort = DIO_PORTB;
		break;
		
		case LED_PORTC:
		local_u8LedPort = DIO_PORTC;
		break;
		
		case LED_PORTD:
		local_u8LedPort = DIO_PORTD;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch (copy_enumLedPin)
	{
		case LED_PIN0:
		local_u8LedPin = DIO_PIN0;
		break;
		
		case LED_PIN1:
		local_u8LedPin = DIO_PIN1;
		break;
		
		case LED_PIN2:
		local_u8LedPin = DIO_PIN2;
		break;
		
		case LED_PIN3:
		local_u8LedPin = DIO_PIN3;
		break;
		
		case LED_PIN4:
		local_u8LedPin = DIO_PIN4;
		break;
		
		case LED_PIN5:
		local_u8LedPin = DIO_PIN5;
		break;
		
		case LED_PIN6:
		local_u8LedPin = DIO_PIN6;
		break;
		
		case LED_PIN7:
		local_u8LedPin = DIO_PIN7;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	DIO_voidSetPinDirection(local_u8LedPort, local_u8LedPin, DIO_PIN_OUTPUT);
}

void LED_voidTurnOn(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin, LED_Type_t copy_enumLedType)
{
	u8 local_u8LedPort = 0, local_u8LedPin = 0, local_u8LedType = 0;
	
	switch (copy_enumLedPort)
	{
		case LED_PORTA:
		local_u8LedPort = DIO_PORTA;
		break;
		
		case LED_PORTB:
		local_u8LedPort = DIO_PORTB;
		break;
		
		case LED_PORTC:
		local_u8LedPort = DIO_PORTC;
		break;
		
		case LED_PORTD:
		local_u8LedPort = DIO_PORTD;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch (copy_enumLedPin)
	{
		case LED_PIN0:
		local_u8LedPin = DIO_PIN0;
		break;
		
		case LED_PIN1:
		local_u8LedPin = DIO_PIN1;
		break;
		
		case LED_PIN2:
		local_u8LedPin = DIO_PIN2;
		break;
		
		case LED_PIN3:
		local_u8LedPin = DIO_PIN3;
		break;
		
		case LED_PIN4:
		local_u8LedPin = DIO_PIN4;
		break;
		
		case LED_PIN5:
		local_u8LedPin = DIO_PIN5;
		break;
		
		case LED_PIN6:
		local_u8LedPin = DIO_PIN6;
		break;
		
		case LED_PIN7:
		local_u8LedPin = DIO_PIN7;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch(copy_enumLedType)
	{
		case LED_ActiveLow:
		local_u8LedType = DIO_PIN_LOW;
		break;
		
		case LED_ActiveHigh:
		local_u8LedType = DIO_PIN_HIGH;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	DIO_voidSetPinValue(local_u8LedPort, local_u8LedPin, local_u8LedType);
}

void LED_voidTurnOff(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin, LED_Type_t copy_enumLedType)
{
	u8 local_u8LedPort = 0, local_u8LedPin = 0, local_u8LedType = 0;
	
	switch (copy_enumLedPort)
	{
		case LED_PORTA:
		local_u8LedPort = DIO_PORTA;
		break;
		
		case LED_PORTB:
		local_u8LedPort = DIO_PORTB;
		break;
		
		case LED_PORTC:
		local_u8LedPort = DIO_PORTC;
		break;
		
		case LED_PORTD:
		local_u8LedPort = DIO_PORTD;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch (copy_enumLedPin)
	{
		case LED_PIN0:
		local_u8LedPin = DIO_PIN0;
		break;
		
		case LED_PIN1:
		local_u8LedPin = DIO_PIN1;
		break;
		
		case LED_PIN2:
		local_u8LedPin = DIO_PIN2;
		break;
		
		case LED_PIN3:
		local_u8LedPin = DIO_PIN3;
		break;
		
		case LED_PIN4:
		local_u8LedPin = DIO_PIN4;
		break;
		
		case LED_PIN5:
		local_u8LedPin = DIO_PIN5;
		break;
		
		case LED_PIN6:
		local_u8LedPin = DIO_PIN6;
		break;
		
		case LED_PIN7:
		local_u8LedPin = DIO_PIN7;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch(copy_enumLedType)
	{
		case LED_ActiveLow:
		local_u8LedType = DIO_PIN_HIGH;
		break;
		
		case LED_ActiveHigh:
		local_u8LedType = DIO_PIN_LOW;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	DIO_voidSetPinValue(local_u8LedPort, local_u8LedPin, local_u8LedType);
}

void LED_voidToggle(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin)
{
	u8 local_u8LedPort = 0, local_u8LedPin = 0;
	
	switch (copy_enumLedPort)
	{
		case LED_PORTA:
		local_u8LedPort = DIO_PORTA;
		break;
		
		case LED_PORTB:
		local_u8LedPort = DIO_PORTB;
		break;
		
		case LED_PORTC:
		local_u8LedPort = DIO_PORTC;
		break;
		
		case LED_PORTD:
		local_u8LedPort = DIO_PORTD;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	switch (copy_enumLedPin)
	{
		case LED_PIN0:
		local_u8LedPin = DIO_PIN0;
		break;
		
		case LED_PIN1:
		local_u8LedPin = DIO_PIN1;
		break;
		
		case LED_PIN2:
		local_u8LedPin = DIO_PIN2;
		break;
		
		case LED_PIN3:
		local_u8LedPin = DIO_PIN3;
		break;
		
		case LED_PIN4:
		local_u8LedPin = DIO_PIN4;
		break;
		
		case LED_PIN5:
		local_u8LedPin = DIO_PIN5;
		break;
		
		case LED_PIN6:
		local_u8LedPin = DIO_PIN6;
		break;
		
		case LED_PIN7:
		local_u8LedPin = DIO_PIN7;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	DIO_voidTogglePinValue(local_u8LedPort, local_u8LedPin);
}