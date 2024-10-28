/*
 * uart.h
 *
 *  Created on: Oct 25, 2024
 *      Author: dogla
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f1xx.h"
#include "stdint.h"
#define GPIOAEN					(1<<1)
#define SYSFREQ					16000000
#define APB1_CLK				SYSFREQ
#define UART_BAUDRATE			115200
/*
#define GPIO_CRL_MODE2_0		(1<<8)
#define GPIO_CRL_MODE2_1		(1<<9)
#define GPIO_CRL_MODE2			(GPIO_CRL_MODE2_0)|(GPIO_CRL_MODE2_1)
#define GPIO_CRL_CNF2_0			(1<<10)
#define GPIO_CRL_CNF2_1			(1<<11)
#define GPIO_CRL_CNF2			(GPIO_CRL_CNF2_0)|(GPIO_CRL_CNF2_1)
#define RCC_APB1ENR_USART2EN	(1<<17)
#define USART_CR1_UE			(1<<13)
#define USART_CR1_TE			(1<<3)
*/
void PA2_uart_tx_init(void);
void uart2_write(int ch);
int __io_putchar(int ch);
#endif /* UART_H_ */
