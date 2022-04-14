/*
 * 02_led_button.c
 *
 *  Created on: 23-Jan-2022
 *      Author: Navadeep
 */

#include<string.h>
#include"stm32f303xx.h"

void delay(void)
{
	//~200ms delay when sysclk is 16MHz(internal RC osc)
	for(uint32_t i = 0; i < 25000; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;

	//set the member elements of structures to 0 initially(include string.h)
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GpioBtn,0,sizeof(GpioLed));

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
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;

	GPIO_PeriClockControl(GPIOC, ENABLE);

	GPIO_Init(&GpioBtn);

	GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);	//reset the LED pin

	//IRQ Configuration for the button pin
	GPIO_IRQPriorityConfig(EXTI15_10, NVIC_IRQ_PRI_15);		//NVIC priority
	GPIO_IRQInterruptConfig(EXTI15_10, ENABLE);		//PC13 used EXTI13

 	while(1);

}

void EXTI15_10_IRQHandler(void)	//from .s file
{
	delay();
	GPIO_IRQHandling(GPIO_PIN_5);
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
}
