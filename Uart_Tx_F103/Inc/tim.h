/*
 * tim.h
 *
 *  Created on: Oct 21, 2024
 *      Author: dogla
 */

#ifndef TIM_H_
#define TIM_H_

#include <stdint.h>
#include "stm32f1xx.h"
#define APB1_TIM2EN 				(1<<0)
#define APB2_GPIOAEN 				(1<<2)
#define CR1_CEN 					(1<<0)
#define SR_UIF 						(1<<0)
#define CCMR1_PWM_MODE2 			(1<<4)|(1<<5)|(1<<6)
#define CCMR1_OC1PE 				(1<<3)
#define CCER_CC1E 					(1<<0)



void tim2_delay_ms_up(int delay_time);


#endif /* TIM_H_ */
