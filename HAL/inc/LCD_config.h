/*
 * LCD_config.h
 *
 * Created: 3/2/2024 9:31:12 AM
 *  Author: Ahmed Mohammed
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "LCD_interface.h"

/* Control port and pins */
#define LCD_CTRL_PORT			LCD_CTRL_PORTA
#define LCD_EN_PIN				LCD_CTRL_PIN2
#define LCD_RW_PIN				LCD_CTRL_PIN1
#define LCD_RS_PIN				LCD_CTRL_PIN3

/* Data port and pins */
#define LCD_DATA_PORT			LCD_DATA_PORTB		
#define LCD_DB0_pin				LCD_DATA_DB_PIN0			
#define LCD_DB1_pin				LCD_DATA_DB_PIN1			
#define LCD_DB2_pin				LCD_DATA_DB_PIN2			
#define LCD_DB3_pin				LCD_DATA_DB_PIN3			
#define LCD_DB4_pin				LCD_DATA_DB_PIN0			
#define LCD_DB5_pin				LCD_DATA_DB_PIN1			
#define LCD_DB6_pin				LCD_DATA_DB_PIN2			
#define LCD_DB7_pin				LCD_DATA_DB_PIN3	


/** Entry mode **/
#define ENTRY_MODE_SET									CURSOR_AUTO_MOVE_RIGHT

/** Display & Blink & Cursor Mode **/
#define DISPLAY_MODE									DISPLAY_MODE_ON
#define CURSOR_MODE										CURSOR_MODE_ON
#define BLINK_MODE										BLINK_MODE_OFF

/** Display Shift & Cursor Move **/
#define DISPLAY_CURSOR_MODE								CURSOR_MOVE
#define DISPLAY_CURSOR_DIRECTION						TO_RIGHT


//#define DISPLAY_SHIFT_MODE								DISPLAY_SHIFT_TO_RIGHT
//#define CURSOR_MOVE_MODE								CURSOR_MOVE_TO_RIGHT


/** Function Set **/
#define FUNCTION_SET_MODE								FUNCTION_SET_TWO_LINE_5x7DOTS

/* 4-bit or 8-bit mode */
#define DATA_LINE_MODE									DATA_LINE_4BIT



//#define ENTRY_MODE_SET					NO_SHIFT_INC | 0x4
//#define DISPLAY_CONTROL					(DISPLAY_ON | CURSOR_ON) & BLINK_OFF
//#define CURSOR_DISPLAY_SHIRT			(MOVE_CURSOR_RIGHT << R_L_BIT) | 0x10
//#define FUNCTION_SET					_2LINE | _5x8DOTS





#endif /* LCD_CONFIG_H_ */