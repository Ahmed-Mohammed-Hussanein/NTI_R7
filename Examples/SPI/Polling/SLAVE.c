/*
 * SLAVE.c
 *
 * Created: 3/15/2024 11:01:20 AM
 * Author : Ahmed Mohammed
 */ 

#include "common.h"

#include "DIO_interface.h"
#include "LED_Interface.h"
#include "SPI_Interface.h"



int main(void)
{	
	SPI_Config_t local_structSPIConfig = {SLAVE, INTERRUPT_DISABLE, MODE_3, LSB_FIRST, PRESCALER_128};
	u8 val = 10;
	
	LED_voidInit(LED_PORTA, LED_PIN7);
	LED_voidInit(LED_PORTC, LED_PIN7);
	
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);

	SPI_voidInitMaster(&local_structSPIConfig);
	
    /* Replace with your application code */
    while (1) 
    {
		SPI_voidReadWrite(10, &val, POLLING);
		
		if (val == 35)
		{
			LED_voidTurnOn(LED_PORTA, LED_PIN7, LED_ActiveHigh);
		}
		else
		{
			LED_voidTurnOn(LED_PORTC, LED_PIN7, LED_ActiveHigh);
		}
    }
}

