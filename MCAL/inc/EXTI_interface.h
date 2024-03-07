/*
 * EXTI_interface.h
 *
 * Created: 3/3/2024 12:57:29 PM
 *  Author: mah
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_INT0 = 0,		// PD2
	EXTI_INT1,			// PD3
	EXTI_INT2,			// PB2
	
} EXTI_Source_t;

/** INT2 supports only falling and rising edge **/
typedef enum
{
	EXTI_LOW_EDGE,
	EXTI_ANY_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE
	
} EXTI_SenseControl_t;

void EXTI_voidEnable(EXTI_Source_t copy_enumInterruptSource, EXTI_SenseControl_t copy_enumSenseControl);
void EXTI_voidDisable(EXTI_Source_t copy_enumInterruptSource);
void EXTI_voidSetCallBack(EXTI_Source_t copy_enumInterruptSource, void (*copy_pVoid)(void));



#endif /* EXTI_INTERFACE_H_ */