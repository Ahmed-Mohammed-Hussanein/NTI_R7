/*
 * ADC_Program.c
 *
 * Created: 3/4/2024 11:30:26 AM
 *  Author: Ahmed Mohamed
 */ 


/****************************************************************************************/
/*                  Analog to Digital Converter Driver									*/
/*					AVR - ATMEGA32														*/
/*					How to use this driver:												*/
/*						- Configure the desired channel as input using DIO driver.		*/
/*						- Include ADC_Interface.h in your file.							*/
/*						- Use APIs according to its description.						*/
/****************************************************************************************/


#include "common.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"


/****************************************************************************************************************************/
/*			API Name: ADC_voidInit																							*/
/*			Parameters:																										*/
/*				- copy_enumMaxVoltage : determine the input reference voltage At @ref ADC_VoltageReference_t				*/
/*				- copy_enumPrescaler  : determine the division factor of the pre-scaler At @ref ADC_PRESCALER_FACTOR_t		*/
/*			Return: Void																									*/
/*			Description: This API is used to Initialize the ADC peripheral and start it to work								*/
/****************************************************************************************************************************/
void ADC_voidInit(ADC_VoltageReference_t copy_enumMaxVoltage, ADC_PRESCALER_FACTOR_t copy_enumPrescaler)
{
	/* Reference Voltage */
	switch(copy_enumMaxVoltage)
	{
		case VREF_AREF:
		WRITE_REG_POS(ADMUX_REG, ADC_VREF_MASK, REFS0, 0x00);
		break;
		
		case VREF_AVCC:
		WRITE_REG_POS(ADMUX_REG, ADC_VREF_MASK, REFS0, 0x01);
		break;
		
		case VREF_256V:
		WRITE_REG_POS(ADMUX_REG, ADC_VREF_MASK, REFS0, 0x03);
		break;
	}
	
	/* Right Adjustment */
	CLEAR_BIT(ADMUX_REG, ADLAR);
	
	/* Pre-scaler */
	switch(copy_enumPrescaler)
	{
		case ADC_PRESCALER_2:
		WRITE_REG_POS(ADCSRA_REG, ADC_ADPSn_MASK, ADPS0, 0x01);
		break;
		
		case ADC_PRESCALER_4:
		WRITE_REG_POS(ADCSRA_REG, ADC_ADPSn_MASK, ADPS0, 0x02);
		break;
		
		case ADC_PRESCALER_8:
		WRITE_REG_POS(ADCSRA_REG, ADC_ADPSn_MASK, ADPS0, 0x03);
		break;
		
		case ADC_PRESCALER_16:
		WRITE_REG_POS(ADCSRA_REG, ADC_ADPSn_MASK, ADPS0, 0x04);
		break;
		
		case ADC_PRESCALER_32:
		WRITE_REG_POS(ADCSRA_REG, ADC_ADPSn_MASK, ADPS0, 0x05);
		break;
		
		case ADC_PRESCALER_64:
		WRITE_REG_POS(ADCSRA_REG, ADC_ADPSn_MASK, ADPS0, 0x06);
		break;
		
		case ADC_PRESCALER_128:
		WRITE_REG_POS(ADCSRA_REG, ADC_ADPSn_MASK, ADPS0, 0x07);
		break;
	}
	
	/* ADC Enable */
	SET_BIT(ADCSRA_REG, ADEN);
}

/****************************************************************************************************************************/
/*			API Name: ADC_voidReadDigitalVal																				*/
/*			Parameters:																										*/
/*				- copy_enumChannel		: determine the input channel to ADC At @ref ADC_ChannelSelection_t					*/
/*				- copy_pu16DigitalValue	: pointer to u16 variable to receive the digital value from ADC.					*/
/*			Return: Void																									*/
/*			Description: This API is used to read the input analog signal at a certain channel as a digital value			*/
/*						using blocking mode																					*/
/****************************************************************************************************************************/
void ADC_voidReadDigitalVal(ADC_ChannelSelection_t copy_enumChannel, u16 *copy_pu16DigitalValue)
{
	if ((NULL != copy_pu16DigitalValue) && copy_enumChannel < 32)
	{
		/* Channel Selection */
		WRITE_REG_POS(ADMUX_REG, ADC_MUXn_MASK, MUX0, copy_enumChannel);
		
		/* Start Of Conversion */
		SET_BIT(ADCSRA_REG, ADSC);
		
		/* wait until end of conversion */
		while (READ_BIT(ADCSRA_REG, ADIF) == 0){}
		
		/* Clear Flag */
		SET_BIT(ADCSRA_REG, ADIF);
		
		*copy_pu16DigitalValue = ADC_DATA_REG;
	} 
	else
	{
	}
}