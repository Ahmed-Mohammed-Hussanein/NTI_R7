/*
 * LCD.c
 *
 * Created: 3/2/2024 9:29:54 AM
 *  Author: Ahmed Mohammed
 */ 


#include "stdio.h"

#include "common.h"

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_voidDIOInit(void)
{
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	
	#if (DATA_LINE_MODE == DATA_LINE_8BIT)
	
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB0_pin, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB1_pin, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB2_pin, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB3_pin, DIO_PIN_OUTPUT);
	
	#endif
	
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB4_pin, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB5_pin, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB6_pin, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DB7_pin, DIO_PIN_OUTPUT);
}

void LCD_voidInit(void)
{
	_delay_ms(50);
	
	/* From Data Sheet --> Command Format */
	if (READ_REG(FunctionSet, FUNCTION_SET_MASK_CHECK)					== 0x20 
	&&  READ_REG(EntryModeSet, ENTRY_MODE_MASK_CHECK)					== 0x04
	&&  READ_REG(DisplayControl, DISPLAY_CURSOR_BLINK_MASK_CHECK)		== 0x08
	&&  READ_REG(CursorDisplayShift, DISPLAY_CURSOR_MASK_CHECK)			== 0x10)
	{
		
		#if (DATA_LINE_MODE == DATA_LINE_4BIT)
		
		LCD_voidSend(FunctionSet >> 4, COMMAND);

		#endif
		
		LCD_voidSend(FunctionSet, COMMAND);
		LCD_voidSend(EntryModeSet, COMMAND);
		LCD_voidSend(DisplayControl, COMMAND);
		LCD_voidSend(CursorDisplayShift, COMMAND);
		LCD_voidSend(clear, COMMAND);
	
	} 
	else
	{
		while(1){}  // for debug
	}
}

void LCD_voidSend(u8 copy_u8Byte, u8 copy_u8RsState)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, copy_u8RsState);
	
	#if (DATA_LINE_MODE == DATA_LINE_8BIT)
	
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB0_pin, READ_BIT(copy_u8Byte, 0));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB1_pin, READ_BIT(copy_u8Byte, 1));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB2_pin, READ_BIT(copy_u8Byte, 2));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB3_pin, READ_BIT(copy_u8Byte, 3));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB4_pin, READ_BIT(copy_u8Byte, 4));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB5_pin, READ_BIT(copy_u8Byte, 5));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB6_pin, READ_BIT(copy_u8Byte, 6));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB7_pin, READ_BIT(copy_u8Byte, 7));
	
	LCD_voidPulseEnable();
	
	#elif (DATA_LINE_MODE == DATA_LINE_4BIT)
	
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB4_pin, READ_BIT(copy_u8Byte, 4));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB5_pin, READ_BIT(copy_u8Byte, 5));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB6_pin, READ_BIT(copy_u8Byte, 6));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB7_pin, READ_BIT(copy_u8Byte, 7));
	
	LCD_voidPulseEnable();
	
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB4_pin, READ_BIT(copy_u8Byte, 0));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB5_pin, READ_BIT(copy_u8Byte, 1));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB6_pin, READ_BIT(copy_u8Byte, 2));
	DIO_voidSetPinValue(LCD_DATA_PORT, LCD_DB7_pin, READ_BIT(copy_u8Byte, 3));
	
	LCD_voidPulseEnable();
		
	#endif
	
	_delay_ms(5);
}

void LCD_voidPulseEnable(void)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(EN_DELAY_ms);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}

void LCD_voidClear(void)
{
	LCD_voidSend(clear, COMMAND);
}

void LCD_voidWriteChar(u8 copy_u8SingleChar)
{
	LCD_voidSend(copy_u8SingleChar, DATA);
}

void LCD_voidWriteString(u8 *copy_pu8String)
{
	while (*copy_pu8String != '\0')
	{
		LCD_voidSend(*copy_pu8String++, DATA);
	}
}

void LCD_voidGoRowColumn(u8 copy_u8Row, u8 copy_u8Column)
{
	u8 local_u8LineAddress;
	
	switch (copy_u8Row)
	{
		case 0:
		local_u8LineAddress = FIRST_LINE_ADDRESS;
		break;
		
		case 1:
		local_u8LineAddress = SECOND_LINE_ADDRESS;
		break;
		
		case 2:
		local_u8LineAddress = THIRD_LINE_ADDRESS;
		break;
		
		case 3:
		local_u8LineAddress = FOURTH_LINE_ADDRESS;
		break;
		
		default:
		while(1) {} // for debug
	}
	
	if (copy_u8Column >= 0 && copy_u8Column < 20)
	{
		LCD_voidSend((DDRAM_COMMAND | local_u8LineAddress ) + copy_u8Column, COMMAND);
	} 
	else
	{
		while(1) {} // for debug
	}
}

void LCD_voidWriteInteger(s32 copy_u32Val)
{
	u8 temp[16];
	
	u32 local_u32Val = copy_u32Val < 0 ? -copy_u32Val : copy_u32Val;
	
	u8 *tempSign = copy_u32Val < 0 ? (u8*)"-" : (u8*)"";
	
	sprintf((char*)temp, "%s%lu", tempSign, local_u32Val);
	
	LCD_voidWriteString(temp);
}

void LCD_voidWriteFloat(f32 floatNumber)
{
	u8 temp[16];
	
	u32 tempInt;
	u32 tempFraction;
	
	u8 *tempSign = floatNumber < 0 ? (u8*)"-" : (u8*)"";
	
	floatNumber		= floatNumber < 0 ? -floatNumber : floatNumber;
	tempInt			= (u32)floatNumber;
	tempFraction	= (floatNumber - tempInt) * 1000;
	
	sprintf((char*)temp, "%s%lu.%lu", (char*)tempSign, tempInt, tempFraction);
	
	LCD_voidWriteString(temp);
}

void LCD_voidCreateCustomChar(u8 copy_u8Address, u8 *copy_pu8CustomChar)
{
	copy_u8Address &= 0x7;
	LCD_voidSend(CGRAM_COMMAND | (copy_u8Address<<3), COMMAND);
	for (int i=0; i<8; i++)
	{
		LCD_voidSend(copy_pu8CustomChar[i], DATA);
	}
	LCD_voidSend(DDRAM_COMMAND, COMMAND);
}

void LCD_voidAutoDisplayShiftLeft(void)
{
	WRITE_REG(EntryModeSet, ENTRY_MODE_MASK, DISPLAY_SHIFT_LEFT);
	LCD_voidSend(EntryModeSet, COMMAND);
}

void LCD_voidNoAutoDisplayShiftLeft(void)
{
	CLEAR_BIT(EntryModeSet, S_BIT);
	//WRITE_REG(EntryModeSet, ENTRY_MODE_MASK, CURSOR_MOVE_RIGHT);
	LCD_voidSend(EntryModeSet, COMMAND);
}

void LCD_voidAutoDisplayShiftRight(void)
{
	WRITE_REG(EntryModeSet, ENTRY_MODE_MASK, DISPLAY_SHIFT_RIGHT);
	LCD_voidSend(EntryModeSet, COMMAND);
}

void LCD_voidNoAutoDisplayShiftRight(void)
{
	CLEAR_BIT(EntryModeSet, S_BIT);
	//WRITE_REG(EntryModeSet, ENTRY_MODE_MASK, CURSOR_MOVE_RIGHT);
	LCD_voidSend(EntryModeSet, COMMAND);
}

void LCD_voidAutoCursorMoveLeft(void)
{
	WRITE_REG(EntryModeSet, ENTRY_MODE_MASK, CURSOR_MOVE_LEFT);
	LCD_voidSend(EntryModeSet, COMMAND);
}

void LCD_voidAutoCursorMoveRight(void)
{
	WRITE_REG(EntryModeSet, ENTRY_MODE_MASK, CURSOR_MOVE_RIGHT);
	LCD_voidSend(EntryModeSet, COMMAND);
}

void LCD_voidDisplayOn(void)
{
	SET_BIT(DisplayControl, D_BIT);
	LCD_voidSend(DisplayControl, COMMAND);
}

void LCD_voidDisplayOff(void)
{
	CLEAR_BIT(DisplayControl, D_BIT);
	LCD_voidSend(DisplayControl, COMMAND);
}

void LCD_voidCursorOn(void)
{
	SET_BIT(DisplayControl, C_BIT);
	LCD_voidSend(DisplayControl, COMMAND);
}

void LCD_voidCursorOff(void)
{
	CLEAR_BIT(DisplayControl, C_BIT);
	LCD_voidSend(DisplayControl, COMMAND);
}

void LCD_voidCursorBlinkOn(void)
{
	SET_BIT(DisplayControl, B_BIT);
	LCD_voidSend(DisplayControl, COMMAND);
}

void LCD_voidCursorBlinkOff(void)
{
	CLEAR_BIT(DisplayControl, B_BIT);
	LCD_voidSend(DisplayControl, COMMAND);
}

void LCD_voidMoveCursorLeft(void)
{
	WRITE_REG(CursorDisplayShift, DISPLAY_CURSOR_MASK, MOVE_CURSOR_LEFT);
	LCD_voidSend(CursorDisplayShift, COMMAND);
}

void LCD_voidMoveCursorRight(void)
{
	WRITE_REG(CursorDisplayShift, DISPLAY_CURSOR_MASK, MOVE_CURSOR_RIGHT);
	LCD_voidSend(CursorDisplayShift, COMMAND);
}

void LCD_voidMoveDisplayLeft(void)
{
	WRITE_REG(CursorDisplayShift, DISPLAY_CURSOR_MASK, MOVE_DISPLAY_LEFT);
	LCD_voidSend(CursorDisplayShift, COMMAND);
}

void LCD_voidMoveDisplayRight(void)
{
	WRITE_REG(CursorDisplayShift, DISPLAY_CURSOR_MASK, MOVE_DISPLAY_RIGHT);
	LCD_voidSend(CursorDisplayShift, COMMAND);
}