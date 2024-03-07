/*
 * SevenSegment_Interface.h
 *
 * Created: 3/7/2024 11:40:42 AM
 *  Author: Ahmed Mohammed
 */ 


#ifndef SEVENSEGMENT_INTERFACE_H_
#define SEVENSEGMENT_INTERFACE_H_

#include "common.h"
#include "DIO_interface.h"

#define SEVEN_SEGMENT_COMMON_ANODE							(0x00)
#define SEVEN_SEGMENT_COMMON_CATHODE						(0x01)

#define SEVEN_SEGMENT_WITH_BCD								(0x00)
#define SEVEN_SEGMENT_WITHOUT_BCD							(0x01)

#define SEVEN_SEGMENT_DATA_PORTA							DIO_PORTA
#define SEVEN_SEGMENT_DATA_PORTB							DIO_PORTB
#define SEVEN_SEGMENT_DATA_PORTC							DIO_PORTC
#define SEVEN_SEGMENT_DATA_PORTD							DIO_PORTD

#define SEVEN_SEGMENT_ENABLE_PORTA							DIO_PORTA
#define SEVEN_SEGMENT_ENABLE_PORTB							DIO_PORTB
#define SEVEN_SEGMENT_ENABLE_PORTC							DIO_PORTC
#define SEVEN_SEGMENT_ENABLE_PORTD							DIO_PORTD

#define SEVEN_SEGMENT_PIN0									DIO_PIN0
#define SEVEN_SEGMENT_PIN1									DIO_PIN1
#define SEVEN_SEGMENT_PIN2									DIO_PIN2
#define SEVEN_SEGMENT_PIN3									DIO_PIN3
#define SEVEN_SEGMENT_PIN4									DIO_PIN4
#define SEVEN_SEGMENT_PIN5									DIO_PIN5
#define SEVEN_SEGMENT_PIN6									DIO_PIN6
#define SEVEN_SEGMENT_PIN7									DIO_PIN7


/* APIS */
void SevenSegment_voidDIOInit(void);
void SevenSegment_voidEnableSegment(u8 copy_u8EnablePort, u8 copy_u8EnablePin);
void SevenSegment_voidDisableSegment(u8 copy_u8EnablePort, u8 copy_u8EnablePin);
void SevenSegment_voidWriteOneDigit(u8 copy_u8OneDigit);
void SevenSegment_voidWriteFourDigits(u16 copy_u16Number);


#endif /* SEVENSEGMENT_INTERFACE_H_ */