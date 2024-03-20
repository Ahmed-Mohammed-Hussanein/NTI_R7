/*
 * SPI_Interface.h
 *
 * Created: 3/5/2024 11:33:29 AM
 *  Author: Ahmed Mohammed
 */


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "common.h"

typedef enum
{
	POLLING = 0,
	INTERRUPT

} SPI_Transfer_Mode_t;

typedef enum
{
	MASTER = 0,
	SLAVE

} SPI_Mode_t;

typedef enum
{
	INTERRUPT_DISABLE = 0,
	INTERRUPT_ENABLE

} SPI_InterruptEnable_t;

typedef enum
{
	MODE_0 = 0,
	MODE_1,
	MODE_2,
	MODE_3,

} SPI_DataMode_t;

typedef enum
{
	MSB_FIRST = 0,
	LSB_FIRST

} SPI_DataOrder_t;

typedef enum
{
	PRESCALER_2 = 0,
	PRESCALER_4,
	PRESCALER_8,
	PRESCALER_16,
	PRESCALER_32,
	PRESCALER_64,
	PRESCALER_128,

} SPI_Speed_t;

typedef struct
{
	SPI_Mode_t				enumSpiMode;					/* MASTER or SLAVE mode at @ref SPI_Mode_t */
	SPI_InterruptEnable_t	enumInterruptEnable;			/* INTERRUPT_DISABLE or INTERRUPT_DISABLE at @ref SPI_InterruptEnable_t */
	SPI_DataMode_t			enumDataMode;					/* MODE_0, MODE_1, MODE_2 or MODE_3 at @ref SPI_DataMode_t*/
	SPI_DataOrder_t			enumDataOrder;					/* MSB_FIRST or LSB_FIRST at @ref SPI_DataOrder_t */
	SPI_Speed_t				enumSpeed;						/* Prescaler division factor at @ref SPI_Speed_t */

} SPI_Config_t;



void SPI_voidInitMaster(SPI_Config_t *copy_pStructConfig);
void SPI_voidRead(u8 *copy_pu8RxValue, SPI_Transfer_Mode_t copy_enumTransferMode);
void SPI_voidWrite(u8 copy_u8TxValue, SPI_Transfer_Mode_t copy_enumTransferMode);
void SPI_voidReadWrite(u8 copy_u8TxData, u8 *copy_pu8RxData, SPI_Transfer_Mode_t copy_enumTransferMode);
void SPI_voidSetCallBack(void (*copy_pFunVoid)(void));



#endif /* SPI_INTERFACE_H_ */
