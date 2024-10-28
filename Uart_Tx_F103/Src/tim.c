/*
 * tim.c
 *
 *  Created on: Oct 21, 2024
 *      Author: dogla
 */

#include "tim.h"


void tim2_delay_ms_up(int delay_time)
{
	RCC->APB1ENR |= APB1_TIM2EN;
	TIM2->PSC = 16000-1;
	TIM2->ARR = (uint32_t)delay_time;
	// clear status
	TIM2->SR = 0;
	// clear cnt value
	TIM2->CNT = 0;
	TIM2->CR1 = CR1_CEN;
	while(!(TIM2->SR & SR_UIF)){};
}

void PWM_ms_50per(int cycle_time)
{
	RCC->APB1ENR |= APB1_TIM2EN;
	TIM2->PSC = 16000-1;
	TIM2->ARR = (uint32_t)cycle_time;
	TIM2->CCMR1 |= CCMR1_PWM_MODE2;
	TIM2->CCR1 = TIM2->ARR / 2;
	TIM2->CCMR1 |= CCMR1_OC1PE;
	TIM2->CCER |= CCER_CC1E;
	TIM2->CNT = 0;
	TIM2->CR1 = CR1_CEN;
}


