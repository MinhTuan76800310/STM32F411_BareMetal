/*
 * uart.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Tuan Dep Trai Vo Cung
 */
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

#ifndef UART_H_
#define UART_H_

#define SYSFRE 			16000000 // 16Mhz
#define APB1_CLK 		SYSFRE

#define GPIOAEN 		(1U<<0)
#define GPIODEN 		(1U<<3)
#define PIN5			(1U<<5)
#define GPIOD_5			PIN5
#define LED_PIN			GPIOD_5
#define USART2EN		(1U<<17)

#define CR1_TE 			(1U<<3)
#define CR1_UE 			(1U<<13)

#define SR_TXE			(1U<<7)


void uart2_tx_init(void);
void uart_write(int ch);
int __io_putchar(int ch);


#endif /* UART_H_ */
