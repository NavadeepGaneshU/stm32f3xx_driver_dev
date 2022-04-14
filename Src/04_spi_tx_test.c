/*
 * 04_spi_tx_test.c
 *
 *  Created on: 02-Feb-2022
 *      Author: Navadeep
 */

#include "stm32f303xx.h"
#include <string.h>

/*
SPI1 Pin Mapping
Alternate Functionality AF5
----------------------------
| MISO | MOSI | SCLK | NSS |
----------------------------
|  PA6 | PA7  |  PA5 | PA4 |
----------------------------
 */

void SPI1_GPIOInit(void)
{
	GPIO_Handle_t SPI1_Pins;		//define handle variable for defining GPIO functions

	SPI1_Pins.pGPIOx = GPIOA;
	SPI1_Pins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;	//because we're doing SPI
	SPI1_Pins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;		//AF5 from the AltFn table in datasheet
	SPI1_Pins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;
	SPI1_Pins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
	SPI1_Pins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;

	//SCLK Pin
	SPI1_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	GPIO_Init(&SPI1_Pins);	//passing address of the handle

	//MOSI Pin
	SPI1_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	GPIO_Init(&SPI1_Pins);

	/* Disable MISO, NSS Pins while using data transmit only */
//	//MISO Pin
//	SPI1_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_6;
//	GPIO_Init(&SPI1_Pins);
//
//	//NSS Pin
//	SPI1_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_4;
//  GPIO_Init(&SPI1_Pins);
}

void  SPI1_Init(void)
{
	SPI_Handle_t SPI1_Handle;

	SPI1_Handle.pSPIx = SPI1;
	SPI1_Handle.SPI_PinConfig.SPI_DeviceMode = SPI_MODE_MASTER;
	SPI1_Handle.SPI_PinConfig.SPI_BusConfig = SPI_BUS_FD;
	SPI1_Handle.SPI_PinConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;
	SPI1_Handle.SPI_PinConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI1_Handle.SPI_PinConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1_Handle.SPI_PinConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI1_Handle.SPI_PinConfig.SPI_SSM =	SPI_SSM_EN;

	SPI_Init(&SPI1_Handle);		//passing address of the handle and this executes
}

int main(void)
{	//enter the data to send
	unsigned char mydata[] = "Hi, SPI1 Works!";

	//function to initialize GPIOs for SPI1 to work
	SPI1_GPIOInit();

	//this function initializes SPI1
	SPI1_Init();

	//enable SSI
	SPI_SSIConfig(SPI1, ENABLE);

	//enable SPIx peripheral just before sending data(no configurations are allowed after this is enabled)
	SPI_PeripheralControl(SPI1, ENABLE);

	//insert data to send
	SPI_SendData(SPI1, mydata, strlen(mydata));		//send data format (pSPIx, pTxBuffer, Length)

	//confirm that SPI isn't busy
	while(SPI_GetFlagStatus(SPI1, SPI_BUSY_FLAG));

	//disable SPIx peripheral
	SPI_PeripheralControl(SPI1, DISABLE);

	while(1);

	return(0);
}
