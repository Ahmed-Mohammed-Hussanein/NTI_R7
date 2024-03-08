/*
 * NTI_R7.c
 *
 * Created: 3/5/2024 2:10:04 PM
 * Author : Ahmed Mohammed
 */ 

#include "common.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"
#include "PB_Interface.h"
#include "LED_Interface.h"


int main(void)
{
	PB_voidInit(PB_PORTB, PB_PIN0, PB_PullUpResistor);
	PB_voidInit(PB_PORTB, PB_PIN1, PB_Floating);
	PB_voidInit(PB_PORTB, PB_PIN2, PB_Floating);
	
	LED_voidInit(LED_PORTA, LED_PIN0);
	LED_voidInit(LED_PORTA, LED_PIN1);
	LED_voidInit(LED_PORTA, LED_PIN2);
	
	
	while(1)
	{
		//TODO:: Please write your application code
		
		if (PB_boolIsPressed(PB_PORTB, PB_PIN0, PB_ActiveLow))
		{
			LED_voidToggle(LED_PORTA, LED_PIN0);
		}
		
		if (PB_boolIsPressed(PB_PORTB, PB_PIN1, PB_ActiveLow))
		{
			LED_voidTurnOn(LED_PORTA, LED_PIN1, LED_ActiveLow);
		}
		
		if (PB_boolIsPressed(PB_PORTB, PB_PIN2, PB_ActiveHigh))
		{
			LED_voidTurnOff(LED_PORTA, LED_PIN1, LED_ActiveLow);
		}
		
		_delay_ms(200);
	}
}