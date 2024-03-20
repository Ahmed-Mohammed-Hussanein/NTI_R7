/*
 * NTI_R7.c
 *
 * Created: 3/5/2024 2:10:04 PM
 * Author : Ahmed Mohammed
 */ 

#include "common.h"

#include "DIO_interface.h"
#include "LED_Interface.h"
#include "SPI_Interface.h"

int main(void)
{
	SPI_Config_t local_structSPIConfig = {MASTER, INTERRUPT_DISABLE, MODE_3, LSB_FIRST, PRESCALER_128};
	u8 val = 35;
	
	LED_voidInit(LED_PORTA, LED_PIN7);
	LED_voidInit(LED_PORTC, LED_PIN7);
	
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	
	DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);

	SPI_voidInitMaster(&local_structSPIConfig);
	
    while(1)
    {
        //TODO:: Please write your application code
	
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
		SPI_voidReadWrite(35, &val, POLLING);
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
		
		if (val == 10)
		{
			LED_voidTurnOn(LED_PORTA, LED_PIN7, LED_ActiveHigh);
		}
		else
		{
			LED_voidTurnOn(LED_PORTC, LED_PIN7, LED_ActiveHigh);
		}
    }
	
	
}





