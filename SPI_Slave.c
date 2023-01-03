/*
 * SPI_Slave.c
 *
 * Created: 1/3/2023 10:55:38 AM
 *  Author: gehad
 */ 
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "SPI_Slave.h"




void SPI_SlaveInit(void)
{
	SPI->SPCR.SPE = 1;
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