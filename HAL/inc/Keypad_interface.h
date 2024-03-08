/*
 * Keypad_interface.h
 *
 * Created: 3/3/2024 8:34:08 PM
 *  Author: mah
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "common.h"

// @ref KEYPAD_PORT_define.
#define KEYPAD_PORTA					DIO_PORTA
#define KEYPAD_PORTB					DIO_PORTB
#define KEYPAD_PORTC					DIO_PORTC
#define KEYPAD_PORTD					DIO_PORTD


// @ref KEYPAD_PIN_define.
#define KEYPAD_PIN0					DIO_PIN0
#define KEYPAD_PIN1					DIO_PIN1
#define KEYPAD_PIN2					DIO_PIN2
#define KEYPAD_PIN3					DIO_PIN3
#define KEYPAD_PIN4					DIO_PIN4
#define KEYPAD_PIN5					DIO_PIN5
#define KEYPAD_PIN6					DIO_PIN6
#define KEYPAD_PIN7					DIO_PIN7

#define COL_STATE_INPUT				DIO_PIN_INPUT
#define COL_STATE_OUTPUT			DIO_PIN_OUTPUT

// ===================================================
// ================== APIs Functions =================
// ===================================================
void Keypad_voidInit(void);

u8 Keypad_u8GetKey(u8 (*keys) []);



#endif /* KEYPAD_INTERFACE_H_ */