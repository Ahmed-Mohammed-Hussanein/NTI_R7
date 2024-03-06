/*
 * LCD.h
 *
 * Created: 3/2/2024 9:29:40 AM
 *  Author: Ahmed Mohammed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO_interface.h"

// @ref LCD_CTRL_PORT_define.
#define LCD_CTRL_PORTA									DIO_PORTA
#define LCD_CTRL_PORTB									DIO_PORTB
#define LCD_CTRL_PORTC									DIO_PORTC
#define LCD_CTRL_PORTD									DIO_PORTD

// @ref LCD_CTRL_PIN_define.
#define LCD_CTRL_PIN0									DIO_PIN0
#define LCD_CTRL_PIN1									DIO_PIN1
#define LCD_CTRL_PIN2									DIO_PIN2
#define LCD_CTRL_PIN3									DIO_PIN3
#define LCD_CTRL_PIN4									DIO_PIN4
#define LCD_CTRL_PIN5									DIO_PIN5
#define LCD_CTRL_PIN6									DIO_PIN6
#define LCD_CTRL_PIN7									DIO_PIN7

// @ref LCD_DATA_PORT_define.
#define LCD_DATA_PORTA									DIO_PORTA
#define LCD_DATA_PORTB									DIO_PORTB
#define LCD_DATA_PORTC									DIO_PORTC
#define LCD_DATA_PORTD									DIO_PORTD

// @ref LCD_DATA_DB_PIN_define.
#define LCD_DATA_DB_PIN0								DIO_PIN0
#define LCD_DATA_DB_PIN1								DIO_PIN1
#define LCD_DATA_DB_PIN2								DIO_PIN2
#define LCD_DATA_DB_PIN3								DIO_PIN3
#define LCD_DATA_DB_PIN4								DIO_PIN4
#define LCD_DATA_DB_PIN5								DIO_PIN5
#define LCD_DATA_DB_PIN6								DIO_PIN6
#define LCD_DATA_DB_PIN7								DIO_PIN7


/** Entry mode **/
#define DISPLAY_AUTO_SHIFT_RIGHT						(0x05)
#define DISPLAY_AUTO_SHIFT_LEFT							(0x07)

#define CURSOR_AUTO_MOVE_RIGHT							(0x06)
#define CURSOR_AUTO_MOVE_LEFT							(0x04)

/** Display & Blink & Cursor Mode **/
#define DISPLAY_MODE_ON									(0x0C)
#define DISPLAY_MODE_OFF								(0x08)

#define CURSOR_MODE_ON									(0x0A)
#define CURSOR_MODE_OFF									(0x08)

#define BLINK_MODE_ON									(0x09)
#define BLINK_MODE_OFF									(0x08)

/** Display Shift & Cursor Move **/
#define DISPLAY_SHIFT									(0x18)
#define CURSOR_MOVE										(0x10)

#define TO_RIGHT										(0x14)
#define TO_LEFT											(0x10)

//#define	DISPLAY_SHIFT_TO_RIGHT							(0x1C)
//#define	DISPLAY_SHIFT_TO_LEFT							(0x18)
//
//#define	CURSOR_MOVE_TO_RIGHT							(0x14)
//#define	CURSOR_MOVE_TO_LEFT								(0x10)

/* Function Set */
#define FUNCTION_SET_TWO_LINE_5x7DOTS					(0x28)
#define FUNCTION_SET_ONE_LINE_5x7DOTS					(0x20)
#define FUNCTION_SET_ONE_LINE_5x10DOTS					(0x24)

/* Data Line Mode */
#define DATA_LINE_4BIT									(0x20)
#define DATA_LINE_8BIT									(0x30)


/* Apis */
void LCD_voidDIOInit(void);
void LCD_voidInit(void);
void LCD_voidClear(void);
void LCD_voidWriteChar(u8 copy_u8SingleChar);
void LCD_voidWriteString(u8 *copy_pu8String);
void LCD_voidGoRowColumn(u8 copy_u8Row, u8 copy_u8Column);
void LCD_voidWriteInteger(u32 copy_u32Val);
void LCD_voidWriteFloat(f32 floatNumber);
void LCD_voidCreateCustomChar(u8 copy_u8Address, u8 *copy_pu8CustomChar);

void LCD_voidAutoDisplayShiftLeft(void);
void LCD_voidNoAutoDisplayShiftLeft(void);

void LCD_voidAutoDisplayShiftRight(void);
void LCD_voidNoAutoDisplayShiftRight(void);

void LCD_voidAutoCursorMoveLeft(void);
void LCD_voidAutoCursorMoveRight(void);

void LCD_voidDisplayOn(void);
void LCD_voidDisplayOff(void);

void LCD_voidCursorOn(void);
void LCD_voidCursorOff(void);

void LCD_voidCursorBlinkOn(void);
void LCD_voidCursorBlinkOff(void);

void LCD_voidMoveCursorLeft(void);
void LCD_voidMoveCursorRight(void);

void LCD_voidMoveDisplayLeft(void);
void LCD_voidMoveDisplayRight(void);



#endif /* LCD_H_ */