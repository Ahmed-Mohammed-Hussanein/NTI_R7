/*
 * NTI_R7.c
 *
 * Created: 3/5/2024 2:10:04 PM
 * Author : Ahmed Mohamed
 */ 

#include "common.h"
#include "ADC_Interface.h"
#include "LCD_interface.h"


int main(void)
{
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	ADC_voidInit(VREF_AVCC, ADC_PRESCALER_128);
	LCD_voidDIOInit();
	LCD_voidInit();
	
	
	u16 digitalValue;
	u16 volt;
	u8 temp;
	
    while(1)
    {
		ADC_voidReadDigitalVal(ADC_CH0, &digitalValue);
		volt = digitalValue * 5 * 1000UL / 1024;
		temp = volt / 10;
		LCD_voidClear();
		LCD_voidWriteInteger(temp);
		_delay_ms(1000);
    }
}





