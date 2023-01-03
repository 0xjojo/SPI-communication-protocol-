/*
 * SPI_Slave.h
 *
 * Created: 1/3/2023 10:55:56 AM
 *  Author: gehad
 */ 


#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_

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


void SPI_SlaveInit(void);

u8 SPI_Transive(u8 data);

void SPI_InitTrans(void);

void SPI_TermTrans(void);



#endif /* SPI_SLAVE_H_ */