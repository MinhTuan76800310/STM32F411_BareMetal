/*
 * systick.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Tuan Dep Trai Vo Cung Tan
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f4xx.h"

#define CTRL_ENABLE				(1U<<0)
#define CTRL_CLKSOURCE			(1U<<2)
#define CTRL_COUNTFLAG			(1U<<16)
#define LOAD_VALUE				16000


void delayMs(int time);

#endif /* SYSTICK_H_ */
