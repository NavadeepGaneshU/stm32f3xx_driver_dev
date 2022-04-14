/*
 * 01_led_toggle.c
 *
 *  Created on: 18-Jan-2022
 *      Author: Navadeep
 */

#include "stm32f303xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);		//killing some time
}

int main(void)
{
	GPIO_Handle_t GpioLed;	//creating a new variable for the structure to access and give definitions

	//ctrl+ space to get recommendations of definitions and define them all
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;	//PA5
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;		//using push-pull
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;	//no pupd needed for push-pull

	GPIO_PeriClockControl(GPIOA, ENABLE);	//enable peripheral clock
	GPIO_Init(&GpioLed);					//call API and send address to run them

	//GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_5, ENABLE);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
		delay();

	}
	return 0;
}
