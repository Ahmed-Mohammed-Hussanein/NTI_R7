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

/** CallBack Functions **/
void EXTI0_CallBack(void);
void EXTI1_CallBack(void);
void EXTI2_CallBack(void);


int main(void)
{
	/** Input pins for exti **/
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN3, DIO_PIN_INPUT);
	DIO_voidActivePinInPullUpResistance(DIO_PORTB, DIO_PIN2);
	
	/** Output leds **/
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT);
	
	EXTI_voidSetCallBack(EXTI_INT0, EXTI0_CallBack);
	EXTI_voidSetCallBack(EXTI_INT1, EXTI1_CallBack);
	EXTI_voidSetCallBack(EXTI_INT2, EXTI2_CallBack);
	
	EXTI_voidEnable(EXTI_INT0, EXTI_ANY_CHANGE);
	EXTI_voidEnable(EXTI_INT1, EXTI_FALLING_EDGE);
	EXTI_voidEnable(EXTI_INT2, EXTI_RISING_EDGE);
	
	GI_voidEnable();
	
	while(1)
	{
		//TODO:: Please write your application code
		
	}
}

void EXTI0_CallBack(void)
{
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
}

void EXTI1_CallBack(void)
{
	DIO_voidTogglePinValue(DIO_PORTA, DIO_PIN1);
}

void EXTI2_CallBack(void)
{
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_LOW);
}