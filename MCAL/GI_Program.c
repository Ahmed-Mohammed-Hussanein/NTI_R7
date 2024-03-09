/*
 * GI_Program.c
 *
 * Created: 3/3/2024 2:06:21 PM
 *  Author: Ahmed Mohammed
 */ 



/************************************************************************/
/*                  Global Interrupt Enable Driver                      */
/*					AVR - ATMEGA32										*/
/*					How to use this driver:								*/
/*						- Include GI_interface.h						*/
/*						- Use APIs according to its description			*/
/************************************************************************/

#include "common.h"

#include "GI_interface.h"
#include "GI_Register.h"


/****************************************************************************************/
/*			API Name: GI_voidEnable														*/
/*			Parameters:	Void															*/
/*			Return: Void																*/
/*			Description: This API is used to Enable the Global Interrupt Controller		*/
/****************************************************************************************/
void GI_voidEnable(void)
{
	SET_BIT(GI_REG, I_bit);
}

/****************************************************************************************/
/*			API Name: GI_voidDisable													*/
/*			Parameters:	Void															*/
/*			Return: Void																*/
/*			Description: This API is used to Disable the Global Interrupt Controller	*/
/****************************************************************************************/
void GI_voidDisable(void)
{
	CLEAR_BIT(GI_REG, I_bit);
}