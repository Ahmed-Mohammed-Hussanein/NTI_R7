/*
 * ADC_Private.h
 *
 * Created: 3/4/2024 11:30:11 AM
 *  Author: Ahmed Mohamed
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "common.h"


#define ADC_DATA_REG		*((volatile u16*)0x24)

#define ADCSRA_REG			*((volatile u8*)0x26)
#define ADEN				7
#define ADSC				6
#define ADATE				5
#define ADIF				4
#define ADIE				3
#define ADPS2				2
#define ADPS1				1
#define ADPS0				0

#define ADMUX_REG			*((volatile u8*)0x27)
#define REFS1				7
#define REFS0				6
#define ADLAR				5
#define MUX4				4
#define MUX3				3
#define MUX2				2
#define MUX1				1
#define MUX0				0 

#define ACSR_REG			*((volatile u8*)0x28)
#define ACD					7
#define ACBG				6
#define ACO					5
#define ACI					4
#define ACIE				3
#define ACIC				2
#define ACIS1				1
#define ACIS0				0

#define ADC_VREF_MASK			0x03
#define ADC_ADPSn_MASK			0x07
#define ADC_MUXn_MASK			0x1F

#endif /* ADC_PRIVATE_H_ */