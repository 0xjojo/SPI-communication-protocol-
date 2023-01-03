/*
 * SPI.c
 *
 * Created: 1/2/2023 9:55:55 PM
 *  Author: gehad
 */ 
#include "BIT_math.h"
#include "STD_types.h"
#include "DIO_int.h"
#include "SPI.h"

void SPI_MasterInit(void)
{
	 SPI->SPCR.SPR0 = 1;
	 SPI->SPCR.SPR1 = 1;
	 SPI->SPCR.MSTR = 1;
	 SPI->SPCR.SPE  = 1;
	 
}

void SPI_SlaveInit(void)
{
	
}

u8 SPI_Transive(u8 tx_data)
{
	u8 rec_data = 0;
	SPI->SPDR = tx_data ;
	while (GET_BIT(SPI->SPSR , 7) == 0);
	
	rec_data = SPI->SPDR;
	return rec_data ;
		
	
}

void SPI_InitTrans(void)
{
	DIO_voidSetPinValue(DIO_U8_PIN12 , DIO_U8_LOW);
}

void SPI_TermTrans(void)
{
	DIO_voidSetPinValue(DIO_U8_PIN12 , DIO_U8_HIGH);
}