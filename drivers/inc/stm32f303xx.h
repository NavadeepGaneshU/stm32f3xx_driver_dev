/*
 * stm32f303xx.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Navadeep
 */

#ifndef INC_STM32F303XX_H_
#define INC_STM32F303XX_H_

#include <stdint.h>		//standard header file for to define integers (uint32_t etc,..)
#define __vo volatile	//macro for volatile keyword

/************ Processor specific details *****************/
/*
 * ARM Cortex M4 processor NVIC ISERx register addresses
 */
#define NVIC_ISER0				((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1				((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2				((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3				((__vo uint32_t*)0xE000E10C)

/*
 * ARM Cortex M4 processor NVIC ICERx register addresses
 */
#define NVIC_ICER0				((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1				((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2				((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3				((__vo uint32_t*)0xE000E18C)

/*
 * ARM Cortex M4 processor priority register address calculation
 */
#define NVIC_PR_BASE_ADDR ((__vo uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx processor number of priority bits implemented in priority register
 */
#define NO_PR_BITS_IMPLEMENTED 	4	//interrupt priority bits fixed for all Cortex M4

/*base addresses of flash and SRAM*/
#define FLASH_BASEADDR			0x08000000UL	//flash memory base address, extends till  0x0807FFFF
#define SRAM_BASEADDR			0x20000000UL	//SRAM base address, 40K size
#define ROM_BASEADDR			0x1FFFD800UL	//system memory base address, 8K size

/*APBx and AHBx bus domain peripheral base addresses*/
#define PERIPH_BASEADDR			0x40000000UL	//all the external peripheral starts after this address
#define APB1PERIPH_BASEADDR		0x40000000UL
#define APB2PERIPH_BASEADDR		0x40010000UL

#define AHB1PERIPH_BASEADDR		0x40020000UL
#define AHB2PERIPH_BASEADDR		0x48000000UL
#define AHB3PERIPH_BASEADDR		0x50000000UL

/*base addresses of peripherals on AHB1*/
//defining only important ones which are to be used
#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1000)	//RCC starts at 0x1000 offset from AHB1 base address

/*base addresses of peripherals on AHB2*/
#define GPIOA_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0000)	//GPIOA starts at base address of AHB2
#define GPIOB_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR			(AHB2PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR			(AHB2PERIPH_BASEADDR + 0x1C00)

/*base addresses of peripherals on AHB3*/
#define ADC1_2_BASEADDR			(AHB3PERIPH_BASEADDR + 0x0000)
#define ADC3_4_BASEADDE			(AHB3PERIPH_BASEADDR + 0x0400)

/*base addresses of peripherals on APB1*/
#define RTC_BASEADDR			(APB1PERIPH_BASEADDR + 0x2800)
#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000)
#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x7800)

/*base addresses of peripherals on APB2*/
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x0400)
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)
#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)
#define SPI4_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x0000)



/********peripheral register definition structures********/

/* This includes each register name and address for peripherals defined above in each buses
 * Written referring to the device Reference Manual register map
 * The offset of 0x04 is auto taken from the starting address as 0x00 inside structure definitions
 * Make sure that each register names are in consecutive order of offset
 */
typedef struct
{
	__vo uint32_t MODER;		//address offset 0x00
	__vo uint32_t OTYPER;		//address offset 0x04
	__vo uint32_t OSPEEDR;		//address offset 0x08
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];		//AFR[0] is AFRH register and AFR[1] is AFRL register
	__vo uint32_t BRR;
}GPIO_RegDef_t;	//_t is the type definition

typedef struct
{
	__vo uint32_t CR;		//address offset 0x00
	__vo uint32_t CFGR;		//address offset 0x04
	__vo uint32_t CIR;		//address offset 0x08
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t AHBRSTR;
	__vo uint32_t CFGR2;
	__vo uint32_t CFGR3;
}RCC_RegDef_t;

/* peripheral definition structure for EXTI */
typedef struct
{
	__vo uint32_t IMR1;		//address offset 0x00
	__vo uint32_t EMR1;		//address offset 0x04
	__vo uint32_t RTSR1;
	__vo uint32_t FTSR1;
	__vo uint32_t SWIER1;
	__vo uint32_t PR1;
	__vo uint32_t IMR2;
	__vo uint32_t EMR2;
	__vo uint32_t RTSR2;
	__vo uint32_t FTSR2;
	__vo uint32_t SWIER2;
	__vo uint32_t PR2;
}EXTI_RegDef_t;

/* peripheral definition structure for SYSCFG */
typedef struct
{
	__vo uint32_t CFGR1;		//address offset 0x00
	__vo uint32_t RCR;			//address offset 0x04
	__vo uint32_t EXTICR[4];	//address offset 0x08 to 0x14
	__vo uint32_t CFGR2;		//address offset 0x18 = 24
	uint32_t RESERVED1[12];		//dummy offsets of 12 x 0x04
	__vo uint32_t CFGR4;		//address offset 0x48  = 72
	uint32_t RESERVED2[2];		//dummy offsets of 2 x 0x04
	__vo uint32_t CFGR3;		//address offset 0x50
}SYSCFG_RegDef_t;

/* peripheral definition structure for SPI */
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;
}SPI_RegDef_t;

/*
 * peripheral definitions (peripheral base address typecasted to xxx_RegDef_t)
 * GPIO_RegDef_t *pGPIOA = (GPIO_RegDef_t*) GPIOA_BASEADDR
 * Instead of GPIO_RegDef_t *pGPIOA, macros are defined as GPIOx.
 */
#define GPIOA			((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB			((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC			((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD			((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE			((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF			((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG			((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH			((GPIO_RegDef_t*) GPIOH_BASEADDR)

#define RCC 			((RCC_RegDef_t*) RCC_BASEADDR)
#define EXTI			((EXTI_RegDef_t*) EXTI_BASEADDR)
#define SYSCFG			((SYSCFG_RegDef_t*) SYSCFG_BASEADDR)

#define SPI1			((SPI_RegDef_t*) SPI1_BASEADDR)
#define SPI2			((SPI_RegDef_t*) SPI2_BASEADDR)
#define SPI3			((SPI_RegDef_t*) SPI3_BASEADDR)
#define SPI4			((SPI_RegDef_t*) SPI4_BASEADDR)

/********Peripheral clock enable referring to RCC_AHBENR/RCC_APBxENR register map********/
/*
 * Macros for the GPIOx peripheral clock enable
 * GPIOx_PCLK_EN() will be higher level macro to enable peripheral clock as API
 * Example: dereferencing RCC as RCC->AHBENR = 25; (compiler will take it as *(RCC_BASEADDR + 0x14) = 25;
 */
#define GPIOA_PCLK_EN()	(RCC->AHBENR |= (1 << 17))	//setting 17th bit of AHBENR register for GPIOA
#define GPIOB_PCLK_EN()	(RCC->AHBENR |= (1 << 18))	//setting 18th bit of AHBENR register for GPIOB
#define GPIOC_PCLK_EN()	(RCC->AHBENR |= (1 << 19))
#define GPIOD_PCLK_EN()	(RCC->AHBENR |= (1 << 20))
#define GPIOE_PCLK_EN()	(RCC->AHBENR |= (1 << 21))
#define GPIOF_PCLK_EN()	(RCC->AHBENR |= (1 << 22))
#define GPIOG_PCLK_EN()	(RCC->AHBENR |= (1 << 23))
#define GPIOH_PCLK_EN()	(RCC->AHBENR |= (1 << 16))

/*
 * Macros for I2Cx peripheral clock enable
 */
#define I2C1_PCLK_EN()	(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()	(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()	(RCC->APB1ENR |= (1 << 30))

/*
 * Macros for SPIx peripheral clock enable
 */
#define SPI1_PCLK_EN()	(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()	(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()	(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()	(RCC->APB2ENR |= (1 << 15))

/*
 * Macros for USARTx/UARTx peripheral clock enable
 */
#define USART1_PCLK_EN()	(RCC->APB2ENR |= (1 << 14))
#define USART2_PCLK_EN()	(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()	(RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()		(RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()		(RCC->APB1ENR |= (1 << 20))

/*
 * Macros for SYSCFG peripheral clock enable
 */
#define SYSCFG_PCLK_EN()	(RCC->APB2ENR |= (1 << 0))


/********Peripheral clock disable referring to RCC_AHBENR/RCC_APBxENR register map********/

/*
 * Macros for GPIOx peripheral clock disable
 */
#define GPIOA_PCLK_DI()	(RCC->AHBENR &= ~(1 << 17))	//clearing 17th bit of AHBENR register for GPIOA
#define GPIOB_PCLK_DI()	(RCC->AHBENR &= ~(1 << 18))	//clearing 18th bit of AHBENR register for GPIOB
#define GPIOC_PCLK_DI()	(RCC->AHBENR &= ~(1 << 19))
#define GPIOD_PCLK_DI()	(RCC->AHBENR &= ~(1 << 20))
#define GPIOE_PCLK_DI()	(RCC->AHBENR &= ~(1 << 21))
#define GPIOF_PCLK_DI()	(RCC->AHBENR &= ~(1 << 22))
#define GPIOG_PCLK_DI()	(RCC->AHBENR &= ~(1 << 23))
#define GPIOH_PCLK_DI()	(RCC->AHBENR &= ~(1 << 16))

/*
 * Macros for I2Cx peripheral clock disable
 */
#define I2C1_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 30))

/*
 * Macros for SPIx peripheral clock disable
 */
#define SPI1_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 15))

/*
 * Macros for USARTx/UARTx peripheral clock disable
 */
#define USART1_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 14))
#define USART2_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()	(RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 20))

/*
 * Macros for SYSCFG peripheral clock disable
 */
#define SYSCFG_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 0))

/*
 * Macros to reset GPIO peripherals using AHB bus reset register (AHBRSTR)
 * The bit has to be set to perform reset operation and then we should release the bit(make it 1 and then 0)
 * Using do-while loop to execute multiple instruction in single macro
 */
#define GPIOA_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 17)); (RCC -> AHBRSTR &= ~(1 << 17)); } while(0)
#define GPIOB_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 18)); (RCC -> AHBRSTR &= ~(1 << 18)); } while(0)
#define GPIOC_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 19)); (RCC -> AHBRSTR &= ~(1 << 19)); } while(0)
#define GPIOD_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 20)); (RCC -> AHBRSTR &= ~(1 << 20)); } while(0)
#define GPIOE_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 21)); (RCC -> AHBRSTR &= ~(1 << 21)); } while(0)
#define GPIOF_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 22)); (RCC -> AHBRSTR &= ~(1 << 22)); } while(0)
#define GPIOG_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 23)); (RCC -> AHBRSTR &= ~(1 << 23)); } while(0)
#define GPIOH_REG_RESET()	do{ (RCC ->AHBRSTR |= (1 << 16)); (RCC -> AHBRSTR &= ~(1 << 16)); } while(0)

#define SPI1_REG_RESET()	do{ (RCC -> APB2RSTR |= (1 << 12)); (RCC -> APB2RSTR &= ~(1 << 12)); } while(0)
#define SPI2_REG_RESET()	do{ (RCC -> APB1RSTR |= (1 << 14)); (RCC -> APB1RSTR &= ~(1 << 14)); } while(0)
#define SPI3_REG_RESET()	do{ (RCC -> APB1RSTR |= (1 << 15)); (RCC -> APB1RSTR &= ~(1 << 15)); } while(0)
#define SPI4_REG_RESET()	do{ (RCC -> APB2RSTR |= (1 << 15)); (RCC -> APB2RSTR &= ~(1 << 15)); } while(0)

/* ternary conditonal operator function */
#define GPIO_BASEADDR_TO_CODE(x)   ((x == GPIOA)?0:\
									(x == GPIOB)?1:\
									(x == GPIOC)?2:\
									(x == GPIOD)?3:\
									(x == GPIOE)?4:\
									(x == GPIOF)?5:\
									(x == GPIOG)?6:\
									(x == GPIOH)?7:0)

/*
 * Interrupt request position numbers for STM32F303xx
 * Taken from Vector Table in reference manual
 */
#define EXTI0				6
#define EXTI1				7
#define EXTI2				8
#define EXTI3				9
#define EXTI4				10
#define EXTI9_5				23
#define	EXTI15_10			40

/*
 * Interrupt priority for STM32F303xx
 */
#define NVIC_IRQ_PRI_0		0
#define NVIC_IRQ_PRI_1		1
#define NVIC_IRQ_PRI_2		2
#define NVIC_IRQ_PRI_3		3
#define NVIC_IRQ_PRI_4		4
#define NVIC_IRQ_PRI_5		5
#define NVIC_IRQ_PRI_6		6
#define NVIC_IRQ_PRI_7		7
#define NVIC_IRQ_PRI_8		8
#define NVIC_IRQ_PRI_9		9
#define NVIC_IRQ_PRI_10		10
#define NVIC_IRQ_PRI_11		11
#define NVIC_IRQ_PRI_12		12
#define NVIC_IRQ_PRI_13		13
#define NVIC_IRQ_PRI_14		14
#define NVIC_IRQ_PRI_15		15


/*************************************************************
 * SPI Register BIT position definitions
 *************************************************************/
/* SPI CR1 Register */
#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			6
#define SPI_CR1_LSBF		7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9
#define SPI_CR1_RXONLY		10
#define SPI_CR1_CRCL		11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		12
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15

/* SPI CR2 Register */
#define SPI_CR2_RXDMAEN			0
#define SPI_CR2_TXDMAEN			1
#define SPI_CR2_SSOE			2
#define SPI_CR2_NSSP			3
#define SPI_CR2_FRF				4
#define SPI_CR2_ERRIE			5
#define SPI_CR2_RXNEIE			6
#define SPI_CR2_TXEIE			7
#define SPI_CR2_DS				8
#define SPI_CR2_FRXTH			12
#define SPI_CR2_LDMARX			13
#define SPI_CR2_LDMATX			14

/* SPI SR Register */
#define SPI_SR_RXNE				0
#define SPI_SR_TXE				1
#define SPI_SR_CHSIDE			2
#define SPI_SR_UDR				3
#define SPI_SR_CRCERR			4
#define SPI_SR_MODF				5
#define SPI_SR_OVR				6
#define SPI_SR_BSY				7
#define SPI_SR_FRE				8
#define SPI_SR_FRLVL			9
#define SPI_SR_FTLVL			11

/*
 * Generic macros
 */
#define SET					1
#define RESET				0
#define ENABLE				SET
#define DISABLE 			RESET
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET
#define FLAG_RESET			RESET
#define FLAG_SET			SET

//including GPIO driver header to have dependency with stm32f303xx.h and pull both to main.c in one header definition.
#include "stm32f303xx_gpio_driver.h"
#include "stm32f303xx_spi_driver.h"

#endif /* INC_STM32F303XX_H_ */
