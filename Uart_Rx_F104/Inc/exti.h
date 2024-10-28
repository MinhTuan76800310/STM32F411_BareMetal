/*
 * exti.h
 *
 *  Created on: Oct 21, 2024
 *      Author: dogla
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f1xx.h"
#include <stdint.h>

#define GPIOCEN				(1<<4)
#define AFIOEN				(1<<0)
#define PIN13_UNMASK		(1<<13)
#define PIN13_FALLING		(1<<13)

void PC13_EXTI_init(void);
#endif /* EXTI_H_ */
