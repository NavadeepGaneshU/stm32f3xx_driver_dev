# stm32f3xx_driver_dev

### FastDrive 
Peripheral and Protocol Drivers for STM32Fxx Cortex-M4 Microcontrollers. This project is tested on STM32F303 Nucleo Board and all development is done using STM32 Cube IDE. 

- [x] GPIO
- [x] SPI
- [ ] I2C
- [ ] LCD
- [ ] ADC


<details>
	<summary>GPIO API</summary>
	
	void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
	
	void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
	
	void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
	
	uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
	
	uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
	
	void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
	
	void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
	
	void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
	
	void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
	
	void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
	
	void GPIO_IRQHandling(uint8_t PinNumber);
	
</details>  

<details>
	<summary>SPI API</summary>
	
	void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

	void SPI_Init(SPI_Handle_t *pSPIHandle);

	void SPI_DeInit(SPI_RegDef_t *pSPIx);

	uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName);

	void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

	void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

	void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);

	void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

	void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);

	void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

	void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);

</details>  

## Detailed Documentation

### GPIO Peripheral API Functions

#### 1. GPIO Peripheral Clock Control
This function enables or disables peripheral clock for the given GPIO port by configuring RCC(Register Clock Control) register.

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
void GPIO_PeriClockControl(GPIOA, DISABLE);	//disabled by default
void GPIO_PeriClockControl(GPIOA, ENABLE);
```

#### 2. GPIO Initialization

__Example:__
```c
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
```
	
#### 3. GPIO De-Initialization
	
__Example:__
```c
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
```
	
#### 4. Write to GPIO Output Pin

__Example:__
```c
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
```
	
#### 5. Write to GPIO Output Port

__Example:__
```c
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
```
	
#### 6. Toggle GPIO Output Pin

__Example:__
```c
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
```
	
#### 7. Read GPIO Input Pin

__Example:__
```c
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
```
	
#### 8. Read GPIO Input Port

__Example:__
```c
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
```

#### 9. Configure Interrupts

__Example:__
```c
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
```
	
#### 10. Configure Interrupt Priority

__Example:__
```c
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
```
	
#### 11. Configure Interrupt Handling

__Example:__
```c
void GPIO_IRQHandling(uint8_t PinNumber);
```
	
### SPI Peripheral API Functions

#### 1. SPI Peripheral Clock Control

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);
```

#### 2. SPI Initialization

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
void SPI_Init(SPI_Handle_t *pSPIHandle);
```

#### 3. SPI De-Initialization

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
void SPI_DeInit(SPI_RegDef_t *pSPIx);
```

#### 4. SPI Get the Status Flag

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName);
```

#### 5. SPI Peripheral Clock Control

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);
```

#### 6. SPI Internal Slave Select(SSI) Configuration

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi);
```

#### 7. SPI Send Data

Parameters - __uint8_t__ STATUS
Returns - __void__

__Example:__
```c
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
```

#### 8. SPI Receive Data

Parameters - __uint8_t__ STAT]
Returns - __void__

__Example:__
```c
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);
```

#### 9. SPI Interrupt Configuration

Parameters - __uint8_t__ 
Returns - __void__

__Example:__
```c
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
```

#### 10. SPI Interrupt Priority Configuration

Parameters - __uint8_t__ 
Returns - __void__

__Example:__
```c
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
```

#### 11. SPI Interrupt Handling

Parameters - __uint8_t__ 
Returns - __void__

__Example:__
```c
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);
```

### References
* [Udemy Course on Embedded Driver Development](https://www.udemy.com/course/mastering-microcontroller-with-peripheral-driver-development/)  
* [STM32F303 Documentation](https://www.st.com/en/microcontrollers-microprocessors/stm32f303.html#documentation)  
* [STM32F303 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00043574-stm32f303xb-c-d-e-stm32f303x6-8-stm32f328x8-stm32f358xc-stm32f398xe-advanced-arm-based-mcus-stmicroelectronics.pdf)  
* [Embedded Artistry Blogs](https://embeddedartistry.com/blog/2020/11/23/real-world-portable-driver-examples/)  