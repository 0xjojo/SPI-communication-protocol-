/*
 * SPI.h
 *
 * Created: 1/2/2023 9:56:15 PM
 *  Author: gehad
 */ 


#ifndef SPI_H_
#define SPI_H_


//#define PINC  (*(volatile u8*)(0x33))

typedef struct 
{
	u8 SPR0 : 1;
	u8 SPR1 : 1;
	u8 CPHA : 1;
	u8 CPOL : 1;
	u8 MSTR : 1;
	u8 DORD : 1;
	u8 SPE  : 1;
	u8 SPIE : 1;
	}SPCR_REG;

typedef struct
{
	SPCR_REG SPCR;
	u8 SPSR;
	u8 SPDR;	
	}SPI_REG;
	
#define SPI ((volatile SPI_REG*)(0x2D))

void SPI_MasterInit(void);

void SPI_SlaveInit(void);

u8 SPI_Transive(u8 data);

void SPI_InitTrans(void);

void SPI_TermTrans(void);
#endif /* SPI_H_ */