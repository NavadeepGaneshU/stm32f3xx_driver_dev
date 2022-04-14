/*
 * 02_led_button.c
 *
 *  Created on: 23-Jan-2022
 *      Author: Navadeep
 */

#include"stm32f303xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 25000; i++);
}
int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;

	/*
	 * GPIO LED configuration
	 * PA5 has user LED
	 */
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;


	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);	//call API and run them

	/*
	 * GPIO button configuration
	 * PC13 for user B1 of ACTIVE LOW type
	 */
	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;

	GPIO_PeriClockControl(GPIOC, ENABLE);

	GPIO_Init(&GpioBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_13) == 0)
		{
			delay();	//de-bouncing delay
			//GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_5, ENABLE);
		}else
		{
			delay();	//de-bouncing delay
			GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_5, DISABLE);
		}
	}
	return 0;
}
