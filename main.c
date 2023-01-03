/*
 * SPI.c
 *
 * Created: 1/2/2023 9:34:25 PM
 * Author : gehad
 */ 
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "SPI.h"
#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
    u8 received_data = 0;
	u8 trans_data = 2;
	DIO_voidInit();
	SPI_MasterInit();
	SPI_InitTrans();
	_delay_ms(1000);
    while (1) 
    {
		received_data = SPI_Transive(trans_data);
		if (received_data == 1)
		{
			DIO_voidSetPinValue(DIO_U8_PIN24 ,1);
			_delay_ms(500);
			DIO_voidSetPinValue(DIO_U8_PIN24 ,0);
			received_data = 0;
		}
		_delay_ms(1000);
	
    }
}

