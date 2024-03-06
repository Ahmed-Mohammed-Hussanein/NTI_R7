/*
 * LCD_private.h
 *
 * Created: 3/2/2024 9:47:49 AM
 *  Author: Ahmed Mohammed
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include "DIO_interface.h"
#include "LCD_config.h"

#define EN_DELAY_ms							(5)

#define clear								(0x1)
#define home								(0x2)

/** Entry mode **/
#define ENTRY_MODE_MASK_CHECK				(0xFC)
#define ENTRY_MODE_MASK						(0x03)

#define S_BIT								(0)
#define I_D_BIT								(1)


#define CURSOR_MOVE_LEFT					(0x00)
#define CURSOR_MOVE_RIGHT					(0x02)
#define DISPLAY_SHIFT_LEFT					(0x03)
#define DISPLAY_SHIFT_RIGHT					(0x01)

/** Display & Blink & Cursor Mode **/
#define DISPLAY_CURSOR_BLINK_MASK_CHECK		(0xF8)
#define DISPLAY_CURSOR_BLINK_MASK			(0x07)

#define D_BIT								(2)
#define DISPLAY_ON							(0x04)
#define DISPLAY_OFF							(0x00)

#define C_BIT								(1)
#define CURSOR_ON							(0x02)
#define CURSOR_OFF							(0x00)

#define B_BIT								(0)
#define BLINK_ON							(0x01)
#define BLINK_OFF							(0x00)

/** Display Shift & Cursor Move **/
#define DISPLAY_CURSOR_MASK_CHECK			(0xF0)
#define DISPLAY_CURSOR_MASK					(0x0C)

#define R_L_BIT								(2)
#define S_C_BIT								(3)

#define MOVE_CURSOR_LEFT					(0x00)
#define MOVE_CURSOR_RIGHT					(0x04)

#define MOVE_DISPLAY_LEFT					(0x08)
#define MOVE_DISPLAY_RIGHT					(0x0C)


/** Function Set **/
#define FUNCTION_SET_MASK_CHECK				(0xE0)
#define _4BIT		0x20
#define _8BIT		0x30

#define _2LINE		0x28
#define _1LINE		0x20

#define _5x10DOTS	0x24
#define _5x8DOTS	0x20

/** DDRAM address **/
#define DDRAM_COMMAND					0x80

#define FIRST_LINE_ADDRESS				0x00
#define SECOND_LINE_ADDRESS				0x40
#define THIRD_LINE_ADDRESS				0x14
#define FOURTH_LINE_ADDRESS				0x54

#define CGRAM_COMMAND					0x40


#define COMMAND							DIO_PIN_LOW
#define DATA							DIO_PIN_HIGH

static u8 EntryModeSet			= ENTRY_MODE_SET;
static u8 DisplayControl		= (DISPLAY_MODE | CURSOR_MODE | BLINK_MODE);
static u8 CursorDisplayShift	= (DISPLAY_CURSOR_MODE | DISPLAY_CURSOR_DIRECTION);
static u8 FunctionSet			= (FUNCTION_SET_MODE | DATA_LINE_MODE);

static void LCD_voidSend(u8 copy_u8Byte, u8 copy_u8RsState);
static void LCD_voidPulseEnable(void);


#endif /* LCD_PRIVATE_H_ */