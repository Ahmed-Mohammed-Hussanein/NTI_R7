/*
 * SPI_Program.c
 *
 * Created: 3/5/2024 11:33:47 AM
 *  Author: Ahmed Mohammed
 */


/********************************************************************************/
/*                  SPI Driver													*/
/*					AVR - ATMEGA32												*/
/*					How to use this driver:										*/
/*						- Include SPI_Interface.h								*/
/*						- Configure the DIO pins for spi						*/
/*						  PB4(not SS), PB5(MOSI), PB6(MISO), PB4(SCK)			*/
/*						- If the peripheral is master call SPI_voidInitMaster	*/
/*						- If the peripheral is slave call SPI_voidInitSlave		*/
/*						- Use APIs according to its description					*/
/********************************************************************************/



#include "common.h"
#include "SPI_Register.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"


/****************************************************************************************************************************/
/*			API Name: SPI_voidInitMaster																					*/
/*			Parameters:																										*/
/*				- copy_pStructConfig	: a pointer to a configuration structure to initialize the peripheral.				*/
/*			Return: Void																									*/
/*			Description: This API is used to initialize the SPI peripheral in master mode									*/
/****************************************************************************************************************************/
void SPI_voidInitMaster(SPI_Config_t *copy_pStructConfig)
{
	/* Interrupt */
	switch (copy_pStructConfig->enumInterruptEnable)
	{
		case INTERRUPT_DISABLE:
		CLEAR_BIT(SPI_REGS->SPCR_reg, SPIE);
		break;

		case INTERRUPT_ENABLE:
		SET_BIT(SPI_REGS->SPCR_reg, SPIE);
		break;

		default:
		while(1) {}  // for debug
	}


	/* Data Order */
	switch(copy_pStructConfig->enumDataOrder)
	{
		case LSB_FIRST:
		SET_BIT(SPI_REGS->SPCR_reg, DORD);
		break;

		case MSB_FIRST:
		CLEAR_BIT(SPI_REGS->SPCR_reg, DORD);
		break;
	}


	/* SPI MODE: MASTER or SLAVE */
	switch(copy_pStructConfig->enumSpiMode)
	{
		case MASTER:
		SET_BIT(SPI_REGS->SPCR_reg, MSTR);
		break;

		case SLAVE:
		CLEAR_BIT(SPI_REGS->SPCR_reg, MSTR);
		break;
	}


	/* DATA MODE */
	switch (copy_pStructConfig->enumDataMode)
	{
		case MODE_0:
		WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, CPHA, 0x00);
		break;

		case MODE_1:
		WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, CPHA, 0x01);
		break;

		case MODE_2:
		WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, CPHA, 0x02);
		break;

		case MODE_3:
		WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, CPHA, 0x03);
		break;
	}

	/* SPEED */
	if (copy_pStructConfig->enumSpiMode == MASTER)
	{
		switch (copy_pStructConfig->enumSpeed)
		{
			case PRESCALER_2:
			WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, SPR0, 0x00);
			SET_BIT(SPI_REGS->SPSR_reg, SPI2X);
			break;

			case PRESCALER_4:
			WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, SPR0, 0x00);
			CLEAR_BIT(SPI_REGS->SPSR_reg, SPI2X);
			break;

			case PRESCALER_8:
			WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, SPR0, 0x01);
			SET_BIT(SPI_REGS->SPSR_reg, SPI2X);
			break;

			case PRESCALER_16:
			WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, SPR0, 0x01);
			CLEAR_BIT(SPI_REGS->SPSR_reg, SPI2X);
			break;

			case PRESCALER_32:
			WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, SPR0, 0x02);
			SET_BIT(SPI_REGS->SPSR_reg, SPI2X);
			break;

			case PRESCALER_64:
			WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, SPR0, 0x02);
			CLEAR_BIT(SPI_REGS->SPSR_reg, SPI2X);
			break;

			case PRESCALER_128:
			WRITE_REG_POS(SPI_REGS->SPCR_reg, 0x3, SPR0, 0x03);
			CLEAR_BIT(SPI_REGS->SPSR_reg, SPI2X);
			break;
		}
	}

	/* SPI ENABLE */
	SET_BIT(SPI_REGS->SPCR_reg, SPE);
}

/****************************************************************************************************************************/
/*			API Name: SPI_voidRead																							*/
/*			Parameters:																										*/
/*				- copy_pu8RxValue		: a pointer to a variable to return the read data.									*/
/*				- copy_enumTransferMode	: This determines the Transfer mode (Blocking, Non-Blocking).						*/
/*			Return: Void																									*/
/*			Description: This API is used to read the data received in SPI for blocking and non-blocking mode				*/
/****************************************************************************************************************************/
void SPI_voidRead(u8 *copy_pu8RxValue, SPI_Transfer_Mode_t copy_enumTransferMode)
{
	if (copy_enumTransferMode == POLLING)
	{
		while (!READ_BIT(SPI_REGS->SPSR_reg, SPIF))
		{
		}
	}

	if (copy_pu8RxValue != NULL)
	{
		*copy_pu8RxValue = SPI_REGS->SPDR_reg;
	}
	else
	{
	}
}

/****************************************************************************************************************************/
/*			API Name: SPI_voidWrite																							*/
/*			Parameters:																										*/
/*				- copy_u8TxValue		: a variable to write the data in SPI buffer.										*/
/*				- copy_enumTransferMode	: This determines the Transfer mode (Blocking, Non-Blocking).						*/
/*			Return: Void																									*/
/*			Description: This API is used to transmit the data in SPI for blocking and non-blocking mode					*/
/****************************************************************************************************************************/
void SPI_voidWrite(u8 copy_u8TxValue, SPI_Transfer_Mode_t copy_enumTransferMode)
{
	if (copy_enumTransferMode == POLLING)
	{
		while (!READ_BIT(SPI_REGS->SPSR_reg, SPIF))
		{
		}
	}

	SPI_REGS->SPDR_reg = copy_u8TxValue;
}

/****************************************************************************************************************************/
/*			API Name: SPI_voidReadWrite																						*/
/*			Parameters:																										*/
/*				- copy_u8TxData			: a variable to write the data in SPI buffer.										*/
/*				- copy_pu8RxValue		: a pointer to a variable to return the read data.									*/
/*				- copy_enumTransferMode	: This determines the Transfer mode (Blocking, Non-Blocking).						*/
/*			Return: Void																									*/
/*			Description: This API is used to transmit and receive the data in SPI for blocking and non-blocking mode		*/
/*						At the same time																					*/
/****************************************************************************************************************************/
void SPI_voidReadWrite(u8 copy_u8TxData, u8 *copy_pu8RxData, SPI_Transfer_Mode_t copy_enumTransferMode)
{
	if (copy_pu8RxData != NULL)
	{
		SPI_REGS->SPDR_reg = copy_u8TxData;

		if (copy_enumTransferMode == POLLING)
		{
			while (!READ_BIT(SPI_REGS->SPSR_reg, SPIF))
			{
			}
		}

		*copy_pu8RxData = SPI_REGS->SPDR_reg;
	}
	else
	{
	}
}

/****************************************************************************************************************************/
/*			API Name: SPI_voidSetCallBack																					*/
/*			Parameters:																										*/
/*				- copy_pFunVoid			: a pointer to call back function.													*/
/*			Return: Void																									*/
/*			Description: This API is used to set call back function to be called at ISR.										*/
/****************************************************************************************************************************/
void SPI_voidSetCallBack(void (*copy_pFunVoid)(void))
{
	if (copy_pFunVoid == NULL)
	{
		while(1) {} // for debug
	}
	else
	{
		PRV_pFunCallBackINTx = copy_pFunVoid;
	}
}

/************************************/
/*			PRIVATE					*/
/************************************/
void __vector_12(void) __attribute__((signal));

void __vector_12(void)
{
	if(PRV_pFunCallBackINTx != NULL)
	{
		PRV_pFunCallBackINTx();
	}
}
