/*
 * LED_Interface.h
 *
 * Created: 3/8/2024 1:11:10 PM
 *  Author: Ahmed Mohammed
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "common.h"
#include "DIO_interface.h"

typedef enum
{
	LED_PORTA = 0,
	LED_PORTB,
	LED_PORTC,
	LED_PORTD
	
} LED_DIOPort_t;

typedef enum
{
	LED_PIN0 = 0,
	LED_PIN1,
	LED_PIN2,
	LED_PIN3,
	LED_PIN4,
	LED_PIN5,
	LED_PIN6,
	LED_PIN7
	
} LED_DIOPin_t;

typedef enum
{
	LED_ActiveLow = 0,
	LED_ActiveHigh
	
} LED_Type_t;

void LED_voidInit(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin);
void LED_voidTurnOn(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin, LED_Type_t copy_enumLedType);
void LED_voidTurnOff(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin, LED_Type_t copy_enumLedType);
void LED_voidToggle(LED_DIOPort_t copy_enumLedPort, LED_DIOPin_t copy_enumLedPin);



#endif /* LED_INTERFACE_H_ */