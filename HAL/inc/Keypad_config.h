/*
 * Keypad_config.h
 *
 * Created: 3/3/2024 8:34:26 PM
 *  Author: mah
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "common.h"
#include "Keypad_interface.h"



#define COL_PORT		KEYPAD_PORTD
#define COL0			KEYPAD_PIN7
#define COL1			KEYPAD_PIN6
#define COL2			KEYPAD_PIN5
#define COL3			KEYPAD_PIN3

#define ROW_PORT		KEYPAD_PORTC
#define ROW0			KEYPAD_PIN5
#define ROW1			KEYPAD_PIN4
#define ROW2			KEYPAD_PIN3		
#define ROW3			KEYPAD_PIN2


#define COL_STATE		COL_STATE_INPUT

#endif /* KEYPAD_CONFIG_H_ */