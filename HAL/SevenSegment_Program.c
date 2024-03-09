/*
 * SevenSegment_Program.c
 *
 * Created: 3/7/2024 11:40:56 AM
 *  Author: Ahmed Mohammed
 */ 


/****************************************************************************************/
/*          Seven Segment Driver														*/
/*			AVR - ATMEGA32																*/
/*			How to use this driver:														*/
/*				- Include SevenSegment_Interface.h										*/
/*				- Go to SevenSegment_Config.h file.										*/
/*				- Configure the following parameters									*/
/*					-- Seven Segment Mode( Common Cathode or Common Anode ).			*/
/*					-- Seven Segment Decoder( With decoder or without decoder ).		*/
/*					-- Data port which seven segment connected to.						*/
/*					-- Which Port and pin connected to enable pin of the seven segment	*/
/*					-- Use APIs according to its description.							*/
/*			Note: This Driver Supports up to 4 seven segments							*/
/****************************************************************************************/


#include "common.h"

#include "DIO_interface.h"

#include "SevenSegment_Private.h"
#include "SevenSegment_Config.h"
#include "SevenSegment_Interface.h"

/****************************************************************************************************************************/
/*			API Name: SevenSegment_voidDIOInit																				*/
/*			Parameters:	Void																								*/
/*			Return: Void																									*/
/*			Description: This API is used to Initialize the pins of the MCU for seven segment								*/
/****************************************************************************************************************************/
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
	
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG1_PORT, SEVEN_SEGMENT_ENABLE_SEG1_PIN);
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG2_PORT, SEVEN_SEGMENT_ENABLE_SEG2_PIN);
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG3_PORT, SEVEN_SEGMENT_ENABLE_SEG3_PIN);
	SevenSegment_voidDisableSegment(SEVEN_SEGMENT_ENABLE_SEG4_PORT, SEVEN_SEGMENT_ENABLE_SEG4_PIN);
}

/****************************************************************************************************************************/
/*			API Name: SevenSegment_voidEnableSegment																		*/
/*			Parameters:																										*/
/*				- copy_u8EnablePort	: determine the port in which the enable pin of the seven segment connected to.			*/
/*											At @ref SEVEN_SEGMENT_ENABLE_PORT_define										*/
/*				- copy_u8EnablePin	: determine the enable pin of the seven segment At @ref SEVEN_SEGMENT_PIN_define		*/
/*			Return: Void																									*/
/*			Description: This API is used to enable a certain seven segment													*/
/****************************************************************************************************************************/
void SevenSegment_voidEnableSegment(u8 copy_u8EnablePort, u8 copy_u8EnablePin)
{
	DIO_voidSetPinValue(copy_u8EnablePort, copy_u8EnablePin, ENABLE_OUTPUT_STATE);	
}

/****************************************************************************************************************************/
/*			API Name: SevenSegment_voidDisableSegment																		*/
/*			Parameters:																										*/
/*				- copy_u8EnablePort	: determine the port in which the enable pin of the seven segment connected to.			*/
/*											At @ref SEVEN_SEGMENT_ENABLE_PORT_define										*/
/*				- copy_u8EnablePin	: determine the enable pin of the seven segment At @ref SEVEN_SEGMENT_PIN_define		*/
/*			Return: Void																									*/
/*			Description: This API is used to disable a certain seven segment												*/
/****************************************************************************************************************************/
void SevenSegment_voidDisableSegment(u8 copy_u8EnablePort, u8 copy_u8EnablePin)
{
	DIO_voidSetPinValue(copy_u8EnablePort, copy_u8EnablePin, DISABLE_OUTPUT_STATE);
}

/****************************************************************************************************************************/
/*			API Name: SevenSegment_voidWriteOneDigit																		*/
/*			Parameters:																										*/
/*				- copy_u8OneDigit	: A variable to write one digit from 0 to 9 on the seven segment.						*/
/*			Return: Void																									*/
/*			Description: This API is used to write one digit from 0 to 9 on a certain seven segment							*/
/*			Note : You should call SevenSegment_voidEnableSegment API first to enable the seven segment and write the digit	*/
/****************************************************************************************************************************/
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

/****************************************************************************************************************************/
/*			API Name: SevenSegment_voidWriteFourDigits																		*/
/*			Parameters:																										*/
/*				- copy_u8OneDigit	: A variable to write four digits from 0000 to 9999 on the seven segment.				*/
/*			Return: Void																									*/
/*			Description: This API is used to write four digits from 0000 to 9999 on the four seven segment					*/
/*			Note : It is not required to call SevenSegment_voidEnableSegment API											*/
/****************************************************************************************************************************/
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