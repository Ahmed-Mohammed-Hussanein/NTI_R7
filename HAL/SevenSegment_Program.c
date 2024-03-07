/*
 * SevenSegment_Program.c
 *
 * Created: 3/7/2024 11:40:56 AM
 *  Author: Ahmed Mohammed
 */ 

#include "common.h"

#include "DIO_interface.h"

#include "SevenSegment_Private.h"
#include "SevenSegment_Config.h"
#include "SevenSegment_Interface.h"

void SevenSegment_voidDIOInit(void)
{
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ENABLE_SEG1_PORT, SEVEN_SEGMENT_ENABLE_SEG1_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ENABLE_SEG2_PORT, SEVEN_SEGMENT_ENABLE_SEG2_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ENABLE_SEG3_PORT, SEVEN_SEGMENT_ENABLE_SEG3_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ENABLE_SEG4_PORT, SEVEN_SEGMENT_ENABLE_SEG4_PIN, DIO_PIN_OUTPUT);
	
	
	#if (SEVEN_SEGMENT_BCD_MODE == SEVEN_SEGMENT_WITH_BCD)
	
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINA, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINB, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINC, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PIND, DIO_PIN_OUTPUT);
	
	#elif (SEVEN_SEGMENT_BCD_MODE == SEVEN_SEGMENT_WITHOUT_BCD)
	
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINA, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINB, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINC, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PIND, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINE, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINF, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PING, DIO_PIN_OUTPUT);
	
	#else
	
	while (1){} // for debug
	
	#endif
	
	
	#if SEVEN_SEGMENT_COMMON_MODE == SEVEN_SEGMENT_COMMON_ANODE

	#define ENABLE_OUTPUT_STATE			DIO_PIN_HIGH
	#define DISABLE_OUTPUT_STATE		DIO_PIN_LOW

	#elif SEVEN_SEGMENT_COMMON_MODE == SEVEN_SEGMENT_COMMON_CATHODE

	#define ENABLE_OUTPUT_STATE			DIO_PIN_LOW
	#define DISABLE_OUTPUT_STATE		DIO_PIN_HIGH

	#else
	
	while(1) {} // for debug
		
	#endif
}

void SevenSegment_voidEnableSegment(u8 copy_u8EnablePort, u8 copy_u8EnablePin)
{
	DIO_voidSetPinValue(copy_u8EnablePort, copy_u8EnablePin, ENABLE_OUTPUT_STATE);	
}

void SevenSegment_voidDisableSegment(u8 copy_u8EnablePort, u8 copy_u8EnablePin)
{
	DIO_voidSetPinValue(copy_u8EnablePort, copy_u8EnablePin, DISABLE_OUTPUT_STATE);
}

void SevenSegment_voidWriteOneDigit(u8 copy_u8OneDigit)
{	
	#if (SEVEN_SEGMENT_BCD_MODE == SEVEN_SEGMENT_WITH_BCD)
	
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINA, READ_BIT(copy_u8OneDigit, 0));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINB, READ_BIT(copy_u8OneDigit, 1));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINC, READ_BIT(copy_u8OneDigit, 2));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PIND, READ_BIT(copy_u8OneDigit, 3));

	#elif (SEVEN_SEGMENT_BCD_MODE == SEVEN_SEGMENT_WITHOUT_BCD)
	
	u8 local_u8DigitValue = 0;
	
	switch (copy_u8OneDigit)
	{
		case 0:
		local_u8DigitValue = BCD_OUTPUT(0);
		break;
		
		case 1:
		local_u8DigitValue = BCD_OUTPUT(1);
		break;
		
		case 2:
		local_u8DigitValue = BCD_OUTPUT(2);
		break;
		
		case 3:
		local_u8DigitValue = BCD_OUTPUT(3);
		break;
		
		case 4:
		local_u8DigitValue = BCD_OUTPUT(4);
		break;
		
		case 5:
		local_u8DigitValue = BCD_OUTPUT(5);
		break;
		
		case 6:
		local_u8DigitValue = BCD_OUTPUT(6);
		break;
		
		case 7:
		local_u8DigitValue = BCD_OUTPUT(7);
		break;
		
		case 8:
		local_u8DigitValue = BCD_OUTPUT(8);
		break;
		
		case 9:
		local_u8DigitValue = BCD_OUTPUT(9);
		break;
	}
	
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINA, READ_BIT(local_u8DigitValue, 0));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINB, READ_BIT(local_u8DigitValue, 1));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINC, READ_BIT(local_u8DigitValue, 2));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PIND, READ_BIT(local_u8DigitValue, 3));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINE, READ_BIT(local_u8DigitValue, 4));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PINF, READ_BIT(local_u8DigitValue, 5));
	DIO_voidSetPinValue(SEVEN_SEGMENT_DATA_PORT, SEVEN_SEGMENT_PING, READ_BIT(local_u8DigitValue, 6));

	#endif
}

void SevenSegment_voidWriteFourDigits(u16 copy_u16Number)
{
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG4_PORT, SEVEN_SEGMENT_ENABLE_SEG4_PIN);
	SevenSegment_voidEnableSegment(SEVEN_SEGMENT_ENABLE_SEG1_PORT, SEVEN_SEGMENT_ENABLE_SEG1_PIN);
	
	SevenSegment_voidWriteOneDigit(copy_u16Number%10);
	copy_u16Number /= 10;
	
	_delay_ms(10);
	
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG1_PORT, SEVEN_SEGMENT_ENABLE_SEG1_PIN);
	SevenSegment_voidEnableSegment(SEVEN_SEGMENT_ENABLE_SEG2_PORT, SEVEN_SEGMENT_ENABLE_SEG2_PIN);
	
	SevenSegment_voidWriteOneDigit(copy_u16Number%10);
	copy_u16Number /= 10;
	
	_delay_ms(10);
	
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG2_PORT, SEVEN_SEGMENT_ENABLE_SEG2_PIN);
	SevenSegment_voidEnableSegment(SEVEN_SEGMENT_ENABLE_SEG3_PORT, SEVEN_SEGMENT_ENABLE_SEG3_PIN);
	
	SevenSegment_voidWriteOneDigit(copy_u16Number%10);
	copy_u16Number /= 10;
	
	_delay_ms(10);
	
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG3_PORT, SEVEN_SEGMENT_ENABLE_SEG3_PIN);
	SevenSegment_voidEnableSegment(SEVEN_SEGMENT_ENABLE_SEG4_PORT, SEVEN_SEGMENT_ENABLE_SEG4_PIN);
	
	SevenSegment_voidWriteOneDigit(copy_u16Number%10);
	
	_delay_ms(10);
}