/*
 * GI_Program.c
 *
 * Created: 3/3/2024 2:06:21 PM
 *  Author: Ahmed Mohammed
 */ 


#include "common.h"

#include "GI_interface.h"
#include "GI_Register.h"

void GI_voidEnable(void)
{
	SET_BIT(GI_REG, I_bit);
}

void GI_voidDisable(void)
{
	CLEAR_BIT(GI_REG, I_bit);
}