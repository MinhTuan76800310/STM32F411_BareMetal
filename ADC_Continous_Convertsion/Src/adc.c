/*
 * adc.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Tuan Dep Trai Vo Cung Tan
 *
 */
#include "adc.h"

void pa1_adc_init(void)
{
	// Enable clock access for GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	// Set the mode of PA1 to analog
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);

	// Configure ADC module
	// Enable clock access for ADC
	RCC->APB2ENR |= ADC1EN;
	// Configure ADC parameters
	// Conversion sequence start channel
	ADC1->SQR3 = ADC_CH1;
	// Conversion sequence length
	ADC1->SQR1  = ADC_SEQ_LEN_1;
	// Enable ADC module
	ADC1->CR2 |= CR2_ADON;

}

void start_conversion(void)
{
	ADC1->CR2 |= CR2_CONT;
	ADC1->CR2 |= CR2_SWSTART;
}

uint32_t adc_read(void)
{
	// Wait for conversion complete
	while(!(ADC1->SR & SR_EOC))
	{
	}
	// Read data
	return ADC1->DR;
}

