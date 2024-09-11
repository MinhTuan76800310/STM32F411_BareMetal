/* Turn on LED 5 (PD14) */
#include <stdint.h>

// PERIPHERAL BASE ADDRESS
#define PERIPH_BASE (uint32_t)0x40000000
#define AHB1_OFFSET (uint32_t)0x20000
#define AHB1_BASE (PERIPH_BASE + AHB1_OFFSET)

// RCC
#define RCC_OFFSET (uint32_t)0x3800
#define RCC_BASE (AHB1_BASE + RCC_OFFSET)

#define RCC_AHB1_ENR_OFFSET (uint32_t)0x30
#define RCC_AHB1_ENR_BASE (RCC_BASE + RCC_AHB1_ENR_OFFSET)

// GPIOD
#define GPIOD_OFFSET (uint32_t)0xC00
#define GPIOD_BASE (AHB1_BASE + GPIOD_OFFSET)

#define GPIOD_MODER_OFFSET (uint32_t)(0x00)
#define GPIOD_MODER_BASE (GPIOD_BASE + GPIOD_MODER_OFFSET)

#define GPIOD_ODR_OFFSET (uint32_t)0x14
#define GPIOD_ODR_BASE (GPIOD_BASE + GPIOD_ODR_OFFSET)

// ACTIVE VALUE
#define RCC_GPIOD_EN (uint32_t)(1 << 3)
#define PIN5 (uint32_t)(1 << 14) // ODR (Note: PIN5 refers to PD14, the 14th bit)

int main()
{
    // Enable RCC for GPIOD
    (*(volatile uint32_t*)RCC_AHB1_ENR_BASE) |= RCC_GPIOD_EN;

    // Set PD14 as output (bits 28-29 in MODER)
    (*(volatile uint32_t*)GPIOD_MODER_BASE) |= (uint32_t)(1 << 28);

    while(1)
    {
        // Set PD14 to high (turn on LED)
        (*(volatile uint32_t*)GPIOD_ODR_BASE) |= PIN5;
    }
    return 0;
}
