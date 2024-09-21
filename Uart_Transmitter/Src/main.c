/* Turn on LED 5 (PD14) */
#include <stdint.h>
#include "stm32f4xx.h"

#define SYSFRE 			16000000 // 16Mhz
#define APB1_CLK 		SYSFRE

#define GPIOAEN 		(1U<<0)
#define USART2EN		(1U<<17)

#define CR1_TE 			(1U<<3)
#define CR1_UE 			(1U<<13)

#define SR_TXE			(1U<<7)

static uint16_t calculate_baudrate(uint32_t SysClk, uint32_t UartBd);
static void uart_set_baudrate(USART_TypeDef *UARTx, uint32_t SysClk, uint32_t UartBd);
static void uart2_tx_init(void);
static void uart_write(int ch);

int main(void)
{
	uart2_tx_init();
	while(1)
	{
		uart_write('Y');
	}
}
void uart2_tx_init(void)
{
	// Enable clock access for GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	// Set pin PA2 is alternate function mode
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);
	// Set alternate type of PA2 is USART2 (AF07)
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	// Enable clock access for USART2
	RCC->APB1ENR |= USART2EN;
	// Configure baudrate for USART2
	uart_set_baudrate(USART2, APB1_CLK, 115200);
	// Configure transfer direction
	USART2->CR1 = CR1_TE;
	// Enable UART
	USART2->CR1 |= CR1_UE;
}

static uint16_t calculate_baudrate(uint32_t PeriClk, uint32_t UartBd)
{
	return (PeriClk + UartBd/(2U))/UartBd;
}

static void uart_set_baudrate(USART_TypeDef *UARTx, uint32_t PeriClk, uint32_t UartBd)
{
	UARTx->BRR = (int)calculate_baudrate(PeriClk, UartBd);
}

static void uart_write(int ch)
{
	// Make sure the transmit data register is empty
	while(!(USART2->SR & SR_TXE)){}
	// Write to data register
	USART2->DR = (ch & 0xFF);
}