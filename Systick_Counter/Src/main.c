#include "uart.h"
#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "systick.h"

#define GPIODEN 		(1U<<3)
#define PIN5			(1U<<5)
#define GPIOD_5			PIN5
#define LED_PIN			GPIOD_5

int Delay_Time;

int main(void)
{
	/* Turn on LED 5 (PD14) */
	// Enable clock access for GPIOD
	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER |= (1U<<10);
	GPIOD->MODER &= ~(1U<<11);

	Delay_Time = 1000; // 1s
	uart2_tx_init();

	while(1)
	{
		delayMs(Delay_Time);
		GPIOD->ODR ^= LED_PIN;
		printf("Pass 1s /n");
	}
}
