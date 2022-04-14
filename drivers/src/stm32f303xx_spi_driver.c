/*
 * stm32f303xx_spi_driver.c
 *
 *  Created on: 01-Feb-2022
 *      Author: Navadeep
 */

#include "stm32f303xx_spi_driver.h"

/* Driver API expansion for SPI */
/*********************************************************
 * @fn			- SPI_PeriClockControl
 * @brief		-
 *
 * @param[in]	- SPIx
 * @param[in]	- ENABLE or DISABLE
 *
 * @return		- none
 *
 * @notes		- none
 *
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}else if(pSPIx == SPI4)
		{
			SPI4_PCLK_EN();
		}
	}
	else
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}else if(pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}else if(pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}else if(pSPIx == SPI4)
		{
			SPI4_PCLK_DI();
		}
	}
}

/*********************************************************
 * @fn			- SPI_Init
 * @brief		-
 *
 * @param[in]	-
 * @param[in]	-
 *
 * @return		- none
 *
 * @notes		- none
 *
 */
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
/* configuring registers (SPI_CR1) */
	uint32_t tempreg = 0;		//defining a temporary 32-bit register to put in all user configurations

	//enable peripheral clock
	SPI_PeriClockControl(pSPIHandle ->pSPIx, ENABLE);

	//1) device mode configuration for MSTR bit
	tempreg |= pSPIHandle ->SPI_PinConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	//2) bus configuration
	if(pSPIHandle ->SPI_PinConfig.SPI_BusConfig == SPI_BUS_FD)	//for full-duplex
	{
		//BIDIMODE should be 0
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);

	}else if(pSPIHandle ->SPI_PinConfig.SPI_BusConfig == SPI_BUS_HD)	//for half-duplex
	{
		//BIDIMODE should be 1
		tempreg |= (1 << SPI_CR1_BIDIMODE);

	}else if(pSPIHandle ->SPI_PinConfig.SPI_BusConfig == SPI_BUS_SIM_Rx)
	{
		//BIDIMODE should be 0
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);

		//RXONLY should be 1
		tempreg |= (1 << SPI_CR1_RXONLY);
	}

	//3) sclk speed configuration
	tempreg |= pSPIHandle ->SPI_PinConfig.SPI_SclkSpeed << SPI_CR1_BR;

	//4) DFF or CRCL configuration
	tempreg |= pSPIHandle ->SPI_PinConfig.SPI_DFF << SPI_CR1_CRCL;

	//5) CPOL configuration
	tempreg |= pSPIHandle ->SPI_PinConfig.SPI_CPOL << SPI_CR1_CPOL;

	//6) CPHA configuration
	tempreg |= pSPIHandle ->SPI_PinConfig.SPI_CPHA << SPI_CR1_CPHA;

	//7) SSM configuration
	tempreg |= pSPIHandle ->SPI_PinConfig.SPI_SSM << SPI_CR1_SSM;

	//write the obtained register sequence to CR1
	pSPIHandle ->pSPIx->CR1 = tempreg;
}

/*********************************************************
 * @fn			- SPI_DeInit
 * @brief		-
 *
 * @param[in]	-
 * @param[in]	-
 *
 * @return		- none
 *
 * @notes		- none
 *
 */
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	if(pSPIx == SPI1)
	{
		SPI1_REG_RESET();
	}else if(pSPIx == SPI2)
	{
		SPI2_REG_RESET();
	}else if(pSPIx == SPI3)
	{
		SPI3_REG_RESET();
	}else if(pSPIx == SPI4)
	{
		SPI4_REG_RESET();
	}
}

/*********************************************************
 * @fn			- SPI_PeripheralControl
 * @brief		-
 *
 * @param[in]	- SPIx
 * @param[in]	- ENABLE or DISABLE
 *
 * @return		- none
 *
 * @notes		- This is used to (en)disable the SPIx after all configurations just before sending the data.
 * 				- Once enabled, no configuration modification can be done unless disabled.
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		pSPIx ->CR1 |= (1 << SPI_CR1_SPE);
	}else
	{
		pSPIx ->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}

/*********************************************************
 * @fn			- SPI_SSIConfig
 * @brief		-
 *
 * @param[in]	- SPIx
 * @param[in]	- ENABLE or DISABLE
 *
 * @return		- none
 *
 * @notes		- SSI has to be set to prevent SPIx from jumping out of master mode when NSS its left idle.
 *
 */
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		pSPIx ->CR1 |= (1 << SPI_CR1_SSI);
	}else
	{
		pSPIx ->CR1 &= ~(1 << SPI_CR1_SSI);
	}
}

/*********************************************************
 * @fn			- SPI_SSOEConfig
 * @brief		-
 *
 * @param[in]	- SPIx
 * @param[in]	- ENABLE or DISABLE
 *
 * @return		- none
 *
 * @notes		- Software Slave Output Enable register configuration
 *
 */
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		pSPIx ->CR2 |= (1 << SPI_CR2_SSOE);
	}else
	{
		pSPIx ->CR2 &= ~(1 << SPI_CR2_SSOE);
	}
}


/*
 * Function which returns SR flag status (for ease inside SPI_SendData)
 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if(pSPIx ->SR & FlagName)	//if it is set
	{
		return FLAG_SET;
	}
	return FLAG_RESET;		//otherwise FLAG_RESET
}

/*********************************************************
 * @fn			- SPI_SendData
 * @brief		-
 *
 * @param[in]	-
 * @param[in]	-
 *
 * @return		- none
 *
 * @notes		- It is a blocking API because function call will wait till all bytes are transmitted.
 * 				- The data register serves as an interface between the Rx and Tx FIFO Buffers.
 * 				- When the data register is read, RxFIFO is accessed, and the write to data register accesses TxFIFO.
 * 				- Status register (SPIx_SR) gives indication if Rx and Tx FIFO buffers are filled/empty from RXNE and TXE registers.
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
	while(Len > 0)
	{
		//1) wait until TXE is set
		while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);	//program flow stays here until until TXE flag is set

		//2) check the DFF bit in CR1
		if(pSPIx ->CR1 & (1 << SPI_CR1_CRCL))
		{
			//16 bit DFF
			//load the data into DR
			pSPIx ->DR = *((uint16_t*)pTxBuffer);	//typecast to 16 bit type
			Len--;
			Len--;	//doing 2 times as 2 bytes of data is sent from the buffer
			(uint16_t*)pTxBuffer++;		//this will be incremented by 2
		}else
		{
			//8 bit DFF
			pSPIx ->DR = *((uint8_t*)pTxBuffer);	//typecast to 8 bit type
			Len--;
			pTxBuffer++;
		}
	}
}

/*********************************************************
 * @fn			- SPI_ReceiveData
 * @brief		-
 *
 * @param[in]	-
 * @param[in]	-
 *
 * @return		- none
 *
 * @notes		- none
 *
 */
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 *  IRQ configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);
