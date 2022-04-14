/*
 * stm32f303xx_spi_driver.h
 *
 *  Created on: 01-Feb-2022
 *      Author: Navadeep
 */

#ifndef INC_STM32F303XX_SPI_DRIVER_H_
#define INC_STM32F303XX_SPI_DRIVER_H_

#include "stm32f303xx.h"

/* Configuration registers for SPI */
typedef struct
{
	uint8_t SPI_DeviceMode;		/*< possible values from @SPI_DeviceMode >*/
	uint8_t SPI_BusConfig;		/*< possible values from @SPI_BusConfig >*/
	uint8_t SPI_SclkSpeed;		/*< possible values from @SPI_SclkSpeed >*/
	uint8_t SPI_DFF;			/*< possible values from @SPI_DFF >*/
	uint8_t SPI_CPOL;			/*< possible values from @SPI_CPOL >*/
	uint8_t SPI_CPHA;			/*< possible values from @SPI_CPHA >*/
	uint8_t SPI_SSM;			/*< possible values from @SPI_SSM >*/
}SPI_PinConfig_t;

/* Configure SPI handler */
typedef struct
{
	SPI_RegDef_t	*pSPIx;			//hold the base address of SPIx
	SPI_PinConfig_t	SPI_PinConfig;
}SPI_Handle_t;


/************* SPI Feature Configuration Definitions *************/
/*
 * @SPI device modes
 */
#define SPI_MODE_MASTER		1
#define SPI_MODE_SLAVE		0

/*
 * @Bus config
 */
#define SPI_BUS_FD			1
#define SPI_BUS_HD			2
#define SPI_BUS_SIM_Rx		3

/*
 * @Sclk Speeds
 * Consult SPIx_CR1 register BR[2:0]
 */
#define SPI_SCLK_SPEED_DIV2		0
#define SPI_SCLK_SPEED_DIV4		1
#define SPI_SCLK_SPEED_DIV8		2
#define SPI_SCLK_SPEED_DIV16	3
#define SPI_SCLK_SPEED_DIV32	4
#define SPI_SCLK_SPEED_DIV64	5
#define SPI_SCLK_SPEED_DIV128	6
#define SPI_SCLK_SPEED_DIV256	7

/*
 * @SPI data frame format (DFF or CRCL)
 */
#define SPI_DFF_8BITS		0
#define SPI_DFF_16BITS		1

/*
 * @SPI clock polarity (CPOL)
 */
#define SPI_CPOL_HIGH		1
#define SPI_CPOL_LOW		0

/*
 * @SPI clock phase (CPHA)
 */
#define SPI_CPHA_HIGH		1
#define SPI_CPHA_LOW		0

/*
 * @SPI Software Slave Management (SSM)
 */
#define SPI_SSM_EN  		1		//software SSM
#define SPI_SSM_DIS			0		//hardware SSM

/* Flags of SPI status register(SR) */
#define SPI_TXE_FLAG		(1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG		(1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG		(1 << SPI_SR_BSY)

/******************** Driver APIs for SPI ***********************/
/*
 * Peripheral clock setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Initialization & Deinitialization
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Flag status from status register if SPIx is busy
 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName);

/*
 * SPIx peripheral enable
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * SPIx SSI
 */
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * SPIx SSOE
 */
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 *  Data send and receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 *  IRQ configuration and ISR handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);

/*
 * Other peripheral control APIs
 */

#endif /* INC_STM32F303XX_SPI_DRIVER_H_ */
