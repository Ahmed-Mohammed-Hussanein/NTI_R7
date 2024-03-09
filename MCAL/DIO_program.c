/*
 * DIO_Program.c
 *
 * Created: 3/6/2024 4:21:04 PM
 *  Author: Ahmed Mohammed
 */


/************************************************************************/
/*                  Digital Input Output Driver                         */
/*					AVR - ATMEGA32										*/
/*					How to use this driver:								*/
/*						- Include DIO_interface.h						*/
/*						- Use APIs according to its description			*/
/************************************************************************/





#include "common.h"
#include "DIO_Register.h"
#include "DIO_interface.h"


/****************************************************************************************************************************/
/*			API Name: DIO_voidSetPinDirection																				*/
/*			Parameters:																										*/
/*				- copy_u8PortId			: determine a port in which a pin to be configured At @ref DIO_PORT_define			*/
/*				- copy_u8PinId			: determine which pin to be configured At @ref DIO_PIN_define						*/
/*				- copy_u8PinDirection	: determine the pin direction either input or output At @ref DIO_PIN_mode_define	*/
/*			Return: Void																									*/
/*			Description: This API is used to set a direction of a pin in a certain port of MCU								*/
/****************************************************************************************************************************/
void DIO_voidSetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	volatile u8 *local_pu8DDR = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8DDR = DDRA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8DDR = DDRB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8DDR = DDRC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8DDR = DDRD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{	
		if(copy_u8PinDirection == DIO_PIN_INPUT)
		{
			CLEAR_BIT(*local_pu8DDR, copy_u8PinId);
		}
		else if(copy_u8PinDirection == DIO_PIN_OUTPUT)
		{
			SET_BIT(*local_pu8DDR, copy_u8PinId);
		}
		else
		{
			while (1){}		// For debugging
		}
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidSetPinValue																					*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*				- copy_u8PinId		: determine which pin to be configured At @ref DIO_PIN_define							*/
/*				- copy_u8PinValue	: determine the pin direction either input or output At @ref DIO_PIN_level_define		*/
/*			Return: Void																									*/
/*			Description: This API is used to set a level value in a pin in a certain port of MCU							*/
/****************************************************************************************************************************/
void DIO_voidSetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = PORTA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8Port = PORTB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8Port = PORTC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8Port = PORTD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{	
		if(copy_u8PinValue == DIO_PIN_LOW)
		{
			CLEAR_BIT(*local_pu8Port, copy_u8PinId);
		}
		else if(copy_u8PinValue == DIO_PIN_HIGH)
		{
			SET_BIT(*local_pu8Port, copy_u8PinId);
		}
		else
		{
			while (1){}		// For debugging
		}
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidGetPinValue																					*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*				- copy_u8PinId		: determine which pin to be configured At @ref DIO_PIN_define							*/
/*				- copy_pu8PinValue	: a pointer to variable of unsigned char												*/
/*			Return: Void																									*/
/*			Description: This API is used to get the input level value of a pin and set it to *copy_pu8PinValue				*/
/****************************************************************************************************************************/
void DIO_voidGetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	volatile u8 *local_pu8PIN = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8PIN = PINA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8PIN = PINB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8PIN = PINC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8PIN = PIND_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		if (copy_pu8PinValue != NULL)
		{
			*copy_pu8PinValue = READ_BIT(*local_pu8PIN, copy_u8PinId);
		} 
		else
		{
			while (1){}		// For debugging
		}
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidTogglePinValue																				*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*				- copy_u8PinId		: determine which pin to be configured At @ref DIO_PIN_define							*/
/*			Return: Void																									*/
/*			Description: This API is used to toggle the level value of a pin (0 -> 1, 1 -> 0)								*/
/****************************************************************************************************************************/
void DIO_voidTogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = PORTA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8Port = PORTB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8Port = PORTC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8Port = PORTD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		TOGGLE_BIT(*local_pu8Port, copy_u8PinId);
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidActivePinInPullUpResistance																	*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*				- copy_u8PinId		: determine which pin to be configured At @ref DIO_PIN_define							*/
/*			Return: Void																									*/
/*			Description: This API is used to activate the internal pull up resistor if the pin is configured as input		*/
/****************************************************************************************************************************/
void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = PORTA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8Port = PORTB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8Port = PORTC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8Port = PORTD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		SET_BIT(*local_pu8Port, copy_u8PinId);
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidSetPortDirection																				*/
/*			Parameters:																										*/
/*				- copy_u8PortId			: determine a port in which a pin to be configured At @ref DIO_PORT_define			*/
/*				- copy_u8PortDirection	: determine the pin direction either input or output At @ref DIO_PORT_mode_define	*/
/*			Return: Void																									*/
/*			Description: This API is used to set a direction of all pins of a certain port of MCU							*/
/****************************************************************************************************************************/
void DIO_voidSetPortDirection            (u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	volatile u8 *local_pu8DDR = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8DDR = DDRA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8DDR = DDRB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8DDR = DDRC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8DDR = DDRD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if(copy_u8PortDirection == DIO_PORT_INPUT)
	{
		CLEAR_REG(*local_pu8DDR, DIO_PORT_MASK);
	}
	else if(copy_u8PortDirection == DIO_PORT_OUTPUT)
	{
		SET_REG(*local_pu8DDR, DIO_PORT_MASK);
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidSetPortValue																					*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*				- copy_u8PortValue	: determine the pin direction either input or output At @ref DIO_PORT_level_define		*/
/*			Return: Void																									*/
/*			Description: This API is used to set a level value in all pins of a certain port of MCU							*/
/****************************************************************************************************************************/
void DIO_voidSetPortValue                (u8 copy_u8PortId, u8 copy_u8PortValue)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = PORTA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8Port = PORTB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8Port = PORTC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8Port = PORTD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if(copy_u8PortValue == DIO_PORT_LOW)
	{
		CLEAR_REG(*local_pu8Port, DIO_PORT_MASK);
	}
	else if(copy_u8PortValue == DIO_PORT_HIGH)
	{
		SET_REG(*local_pu8Port, DIO_PORT_MASK);
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidGetPortValue																					*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*				- copy_pu8PortValue	: a pointer to variable of unsigned char												*/
/*			Return: Void																									*/
/*			Description: This API is used to get the input level value of all pins and set it to *copy_pu8PortValue			*/
/****************************************************************************************************************************/
void DIO_voidGetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	volatile u8 *local_pu8PIN = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8PIN = PINA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8PIN = PINB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8PIN = PINC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8PIN = PIND_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	if (copy_pu8PortValue != NULL)
	{
		*copy_pu8PortValue = READ_REG(*local_pu8PIN, DIO_PORT_MASK);
	}
	else
	{
		while (1){}		// For debugging
	}
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidTogglePortValue																				*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*			Return: Void																									*/
/*			Description: This API is used to toggle the level value of all pins (0 -> 1, 1 -> 0)							*/
/****************************************************************************************************************************/
void DIO_voidTogglePortValue             (u8 copy_u8PortId)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = PORTA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8Port = PORTB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8Port = PORTC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8Port = PORTD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	TOGGLE_REG(*local_pu8Port, DIO_PORT_MASK);
}

/****************************************************************************************************************************/
/*			API Name: DIO_voidActivePortInPullUpResistance																	*/
/*			Parameters:																										*/
/*				- copy_u8PortId		: determine a port in which a pin to be configured At @ref DIO_PORT_define				*/
/*			Return: Void																									*/
/*			Description: This API is used to activate the internal pull up resistor											*/
/*						 all pins of a port is configured as input															*/
/****************************************************************************************************************************/
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = PORTA_REG;
		break;
		
		case DIO_PORTB:
		local_pu8Port = PORTB_REG;
		break;
		
		case DIO_PORTC:
		local_pu8Port = PORTC_REG;
		break;
		
		case DIO_PORTD:
		local_pu8Port = PORTD_REG;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	SET_REG(*local_pu8Port, DIO_PORT_MASK);
}
