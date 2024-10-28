/*
 * uart.c
 *
 *  Created on: Oct 25, 2024
 *      Author: dogla
 */

#include "uart.h"



static void uart_set_baudrate(USART_TypeDef *UARTx, uint32_t Peri_clk, uint32_t baudrate);

static uint16_t compute_uart_baudrate(uint32_t Peri_clk, uint32_t baudrate);
void PA2_uart_tx_init(void)
{
	// Enable clock access for GPIOA
	RCC->APB2ENR |= GPIOAEN;

	// Set PA2 to alternate function push-pull
	GPIOA->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);  // Clear mode and CNF for PA2
	GPIOA->CRL |= GPIO_CRL_MODE2_1 | GPIO_CRL_CNF2_1; // Set mode and CNF for alternate function push-pull, Output mode 2 MHz

	// Enable clock access for UART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	// Set baudrate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	// Configure the transfer direction
	USART2->CR1 |= USART_CR1_TE;  // Enable transmission

	// Enable uart
	USART2->CR1 |= USART_CR1_UE;  // Enable UART2
}

static void uart_set_baudrate(USART_TypeDef *UARTx, uint32_t Peri_clk, uint32_t baudrate)
{
    UARTx->BRR = compute_uart_baudrate(Peri_clk, baudrate);
}

static uint16_t compute_uart_baudrate(uint32_t Peri_clk, uint32_t baudrate)
{
    return ((Peri_clk + (baudrate / 2U)) / baudrate);
}
void uart2_write(int ch)
{
  /*Make sure the transmit data register is empty*/
	while(!(USART2->SR & USART_SR_TXE)){}

  /*Write to transmit data register*/
	USART2->DR	=  (ch & 0xFF);
}
int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void PA3_uart_rx_init(void)
{
	// Enable clock access for GPIOA
	RCC->APB2ENR |= GPIOAEN;

	// Set PA3 to alternate function push-pull
	GPIOA->CRL &= ~(GPIO_CRL_MODE3 | GPIO_CRL_CNF3);  // Clear mode and CNF for PA2
	GPIOA->CRL |= GPIO_CRL_CNF3_0;

	// Enable clock access for UART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	// Set baudrate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	// Configure the transfer direction
	USART2->CR1 |=  USART_CR1_RE;  // Enable receive

	// Enable uart
	USART2->CR1 |= USART_CR1_UE;  // Enable UART2
}

char uart2_read(void)
{
	  /*Make sure the receive data register is not empty*/
	while(!(USART2->SR & USART_SR_RXNE)){}

	/*Read data*/
	return USART2->DR;

}

