/*
 * EXTI_program.c
 *
 * Created: 3/3/2024 12:57:09 PM
 *  Author: Ahmed Mohammed
 */ 

#include "common.h"

#include "EXTI_interface.h"
#include "EXTI_Register.h"


void EXTI_voidEnable(EXTI_Source_t copy_enumInterruptSource, EXTI_SenseControl_t copy_enumSenseControl)
{
	switch (copy_enumInterruptSource)
	{
		case EXTI_INT0:					 
		switch (copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC00);
			SET_BIT(MCUCR_REG, ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCR_REG, ISC00);
			SET_BIT(MCUCR_REG, ISC01);
			break;
			
			case EXTI_LOW_EDGE:
			CLEAR_BIT(MCUCR_REG, ISC00);
			CLEAR_BIT(MCUCR_REG, ISC01);
			break;
			
			case EXTI_ANY_CHANGE:
			SET_BIT(MCUCR_REG, ISC00);
			CLEAR_BIT(MCUCR_REG, ISC01);
			break;
			
			default:
			while(1) {} // for debug
		}		 
		SET_BIT(GICR_REG, INT0);			 
		break;							 
										 
		case EXTI_INT1:					 
		switch (copy_enumSenseControl)	 
		{								 
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC10);
			SET_BIT(MCUCR_REG, ISC11);
			break;
			
			case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCR_REG, ISC10);
			SET_BIT(MCUCR_REG, ISC11);
			break;
			
			case EXTI_LOW_EDGE:
			CLEAR_BIT(MCUCR_REG, ISC10);
			CLEAR_BIT(MCUCR_REG, ISC11);
			break;
			
			case EXTI_ANY_CHANGE:
			SET_BIT(MCUCR_REG, ISC10);
			CLEAR_BIT(MCUCR_REG, ISC11);
			break;
			
			default:
			while(1) {} // for debug	 
		}
		SET_BIT(GICR_REG, INT1);			 
		break;							 
										 
		case EXTI_INT2:					 
		switch (copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR_REG, ISC2);
			break;
			
			case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCSR_REG, ISC2);
			break;
			
			case EXTI_LOW_EDGE:
			case EXTI_ANY_CHANGE:
			default:
			while(1) {} // for debug
		}								 
		SET_BIT(GICR_REG, INT2);			 
		break;
		
		default:
		while(1) {} // for debug
	}
}

void EXTI_voidDisable(EXTI_Source_t copy_enumInterruptSource)
{
	switch (copy_enumInterruptSource)
	{
		case EXTI_INT0:
		CLEAR_BIT(GICR_REG, INT0);
		break;
		
		case EXTI_INT1:
		CLEAR_BIT(GICR_REG, INT1);
		break;
		
		case EXTI_INT2:
		CLEAR_BIT(GICR_REG, INT2);
		break;
		
		default:
		while(1) {} // for debug
	}
}

void EXTI_voidSetCallBack(EXTI_Source_t copy_enumInterruptSource, void (*copy_pFunVoid)(void))
{
	if (copy_pFunVoid == NULL)
	{
		while(1) {} // for debug
	}
	
	switch (copy_enumInterruptSource)
	{
		case EXTI_INT0:
		PRV_pFunCallBackINTx[0] = copy_pFunVoid; 
		break;
		
		case EXTI_INT1:
		PRV_pFunCallBackINTx[1] = copy_pFunVoid;
		break;
		
		case EXTI_INT2:
		PRV_pFunCallBackINTx[2] = copy_pFunVoid;
		break;
		
		default:
		while(1) {} // for debug
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

void __vector_1(void)
{
	if(PRV_pFunCallBackINTx[0] != NULL)
	{
		PRV_pFunCallBackINTx[0]();
	}
}

void __vector_2(void)
{
	if(PRV_pFunCallBackINTx[1] != NULL)
	{
		PRV_pFunCallBackINTx[1]();
	}
}

void __vector_3(void)
{
	if(PRV_pFunCallBackINTx[2] != NULL)
	{
		PRV_pFunCallBackINTx[2]();
	}
}