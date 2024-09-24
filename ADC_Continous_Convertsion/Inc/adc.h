/*
 * adc.h
 *
 *  Created on: Sep 22, 2024
 *      Author: dogla
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "stm32f4xx.h"

#define GPIOAEN			(1U<<0)
#define ADC1EN				(1U<<8)

#define ADC_CH1				(1U<<0)
#define ADC_SEQ_LEN_1		 0x00
#define CR2_ADON			(1U<<0)
#define CR2_SWSTART			(1U<<30)
#define SR_EOC				(1U<<1)
#define CR2_CONT			(1U<<1)

void pa1_adc_init(void);
void start_conversion(void);
uint32_t adc_read(void);

#endif /* ADC_H_ */
