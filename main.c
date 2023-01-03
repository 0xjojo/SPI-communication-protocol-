/*
 * SPI_Slave.c
 *
 * Created: 1/3/2023 10:54:49 AM
 * Author : gehad
 */ 

#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "SPI_Slave.h"
#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
   u8 received_data = 0;
   u8 trans_data = 1;
   DIO_voidInit();
   SPI_SlaveInit();
   
  // _delay_ms(1000); 
    while (1) 
    {
		received_data = SPI_Transive(trans_data);
		if (received_data == 2)
		{
			DIO_voidSetPinValue(DIO_U8_PIN24 ,0);
			_delay_ms(500);
			DIO_voidSetPinValue(DIO_U8_PIN24 ,1);
			received_data = 0;
		}
		_delay_ms(1000);
    }
}

