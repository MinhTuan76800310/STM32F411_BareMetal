/*
 * exti.c
 *
 *  Created on: Oct 21, 2024
 *      Author: dogma
 */
#include "exti.h"

void PC13_EXTI_init(void)
{
	// disable global interrupt
	__disable_irq();
	// Enable clock access for GPIOC
	RCC->APB2ENR |= GPIOCEN;
	// Set pin 13 is input mode
	GPIOC->CRH &= ~(1 << 20);
	GPIOC->CRH &= ~(1 << 21);
	// set input with pull-up/pull-down
	GPIOC->CRH |= (1 << 23);
	// Enable clock access for interrupt
	RCC->APB2ENR |= AFIOEN;
	// Select port C for interrupt
	AFIO->EXTICR[3] |= (1<<5);
	// Unmask EXTI13
	EXTI->IMR |= PIN13_UNMASK;
	// Select falling edge for interrupt
	EXTI->FTSR |= PIN13_FALLING;
	// Enable global interrupt
	__enable_irq();
}

void EXTI15_10_IRQHandler(void)
{

}
