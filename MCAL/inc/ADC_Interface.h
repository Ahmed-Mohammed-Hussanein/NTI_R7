/*
 * ADC_Interface.h
 *
 * Created: 3/4/2024 11:29:25 AM
 *  Author: Ahmed Mohamed
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "common.h"
#include "ADC_Private.h"


typedef enum
{
	VREF_AREF = 0,
	VREF_AVCC,
	VREF_256V = 3
	
} ADC_VoltageReference_t;

typedef enum
{
	ADC_PRESCALER_2 = 1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
	
} ADC_PRESCALER_FACTOR_t;

typedef enum
{
	ADC_CH0 = 0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7
	
} ADC_ChannelSelection_t;




void ADC_voidInit(ADC_VoltageReference_t copy_enumMaxVoltage, ADC_PRESCALER_FACTOR_t copy_enumPrescaler);
void ADC_voidReadDigitalVal(ADC_ChannelSelection_t copy_enumChannel, u16 *copy_pu16DigitalValue);




#endif /* ADC_INTERFACE_H_ */