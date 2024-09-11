#include "stm32f4xx.h"
#include <stdint.h>

#define AHB1_GPIOD (uint32_t)(1<<3)
#define PIN14 (uint32_t)(1<<14)

int main(void)
{
	// Enable clock for GPIOD
	RCC->AHB1ENR |= AHB1_GPIOD;

	// Set PD14 as output
	GPIOD->MODER &= ~(1<<29);  // Clear MODER29 bit
	GPIOD->MODER |= (1<<28);   // Set MODER28 bit

	while(1)
	{
		// Toggle PD14
		GPIOD->ODR ^= PIN14;

		// Simple delay
		for (uint32_t i = 0; i < 10000; i++)
		{
		}
	}
}
