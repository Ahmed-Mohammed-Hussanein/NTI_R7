/*
 * Keypad_program.c
 *
 * Created: 3/3/2024 8:34:56 PM
 *  Author: mah
 */ 

#include "common.h"
#include "DIO_interface.h"
#include "Keypad_config.h"
#include "Keypad_interface.h"



#define CHECK_STATE			DIO_PIN_LOW
#define NO_CHECK_STATE		DIO_PIN_HIGH

#if COL_STATE == COL_STATE_OUTPUT

#define KEYPAD_OUTPUT_PORT				COL_PORT
#define KEYPAD_OUTPUT_PIN0				COL0
#define KEYPAD_OUTPUT_PIN1				COL1
#define KEYPAD_OUTPUT_PIN2				COL2
#define KEYPAD_OUTPUT_PIN3				COL3

#define KEYPAD_INPUT_PORT				ROW_PORT
#define KEYPAD_INPUT_PIN0				ROW0
#define KEYPAD_INPUT_PIN1				ROW1
#define KEYPAD_INPUT_PIN2				ROW2
#define KEYPAD_INPUT_PIN3				ROW3

#elif COL_STATE == COL_STATE_INPUT

#define KEYPAD_OUTPUT_PORT				ROW_PORT
#define KEYPAD_OUTPUT_PIN0				ROW0
#define KEYPAD_OUTPUT_PIN1				ROW1
#define KEYPAD_OUTPUT_PIN2				ROW2
#define KEYPAD_OUTPUT_PIN3				ROW3

#define KEYPAD_INPUT_PORT				COL_PORT
#define KEYPAD_INPUT_PIN0				COL0
#define KEYPAD_INPUT_PIN1				COL1
#define KEYPAD_INPUT_PIN2				COL2
#define KEYPAD_INPUT_PIN3				COL3

#endif

void Keypad_voidInit(void)
{	
	DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN3, DIO_PIN_OUTPUT);
	
	DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN0, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN1, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN2, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN3, DIO_PIN_INPUT);
	
	//DIO_voidActivePinInPullUpResistance(KEYPAD_INPUT_PORT, KEYPAD_PIN0);
	//DIO_voidActivePinInPullUpResistance(KEYPAD_INPUT_PORT, KEYPAD_PIN1);
	//DIO_voidActivePinInPullUpResistance(KEYPAD_INPUT_PORT, KEYPAD_PIN2);
	//DIO_voidActivePinInPullUpResistance(KEYPAD_INPUT_PORT, KEYPAD_PIN3);
}

u8 Keypad_u8GetKey(u8 (*keys) [])
{
	u8 i, pressed_key;
	
	for(i = 0; i < 4; i++)
	{
		switch (i)
		{
			case 0:
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN0, CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN1, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN2, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN3, NO_CHECK_STATE);
			break;
			
			case 1:
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN0, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN1, CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN2, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN3, NO_CHECK_STATE);
			break;
			
			case 2:
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN0, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN1, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN2, CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN3, NO_CHECK_STATE);
			break;
			
			case 3:
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN0, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN1, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN2, NO_CHECK_STATE);
			DIO_voidSetPinValue(KEYPAD_OUTPUT_PORT, KEYPAD_OUTPUT_PIN3, CHECK_STATE);
			break;
		}
		
		DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN0, &pressed_key);
		if (pressed_key == CHECK_STATE)
		{
			DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN0, &pressed_key);
			while(pressed_key == CHECK_STATE)
			{
				DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN0, &pressed_key);
			}
			
			#if COL_STATE == COL_STATE_OUTPUT
			
			return *(*keys + 4 * 0 + i);
			
			#else
			
			return *(*keys + 4 * i + 0);
			
			#endif
		}
		
		DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN1, &pressed_key);
		if (pressed_key == CHECK_STATE)
		{
			DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN1, &pressed_key);
			while(pressed_key == CHECK_STATE)
			{
				DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN1, &pressed_key);
			}
			
			#if COL_STATE == COL_STATE_OUTPUT
			
			return *(*keys + 4 * 1 + i);
			
			#else
			
			return *(*keys + 4 * i + 1);
			
			#endif
		}
		
		DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN2, &pressed_key);
		if (pressed_key == CHECK_STATE)
		{
			DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN2, &pressed_key);
			while(pressed_key == CHECK_STATE)
			{
				DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN2, &pressed_key);
			}
			
			#if COL_STATE == COL_STATE_OUTPUT
			
			return *(*keys + 4 * 2 + i);
			
			#else
			
			return *(*keys + 4 * i + 2);
			
			#endif
		}
		
		DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN3, &pressed_key);
		if (pressed_key == CHECK_STATE)
		{
			DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN3, &pressed_key);
			while(pressed_key == CHECK_STATE)
			{
				DIO_voidGetPinValue(KEYPAD_INPUT_PORT, KEYPAD_INPUT_PIN3, &pressed_key);
			}
			
			#if COL_STATE == COL_STATE_OUTPUT
						
			return *(*keys + 4 * 3 + i);
			
			#else
			
			return *(*keys + 4 * i + 3);
			
			#endif
		}
	}
	
	return '\0';
}