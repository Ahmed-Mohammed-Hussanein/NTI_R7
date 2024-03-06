/*
 * DIO_Program.h
 *
 * Created: 3/6/2024 4:21:04 PM
 *  Author: Ahmed Mohammed
 */

#include "common.h"
#include "DIO_Register.h"
#include "DIO_interface.h"

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
