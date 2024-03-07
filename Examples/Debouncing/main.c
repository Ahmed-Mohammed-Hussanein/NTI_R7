/*
 * NTI_R7.c
 *
 * Created: 3/5/2024 2:10:04 PM
 * Author : Ahmed Mohammed
 */

#include "common.h"

#include "DIO_interface.h"

int main(void)
{
	u8 isPressed = 0;

	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_PIN_INPUT);
	DIO_voidSetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);

    while(1)
    {
        //TODO:: Please write your application code
		DIO_voidGetPinValue(DIO_PORTB, DIO_PIN0, &isPressed);
		if (isPressed == 1)
		{
			_delay_ms(50);
			DIO_voidGetPinValue(DIO_PORTB, DIO_PIN0, &isPressed);
			if (isPressed == 1)
			{
				DIO_voidTogglePortValue(DIO_PORTA);
			}
		}
    }
}
