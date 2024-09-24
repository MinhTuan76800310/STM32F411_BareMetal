#include "uart.h"
#include "stm32f4xx.h"
#include "adc.h"
#include <stdint.h>
#include <stdio.h>

uint32_t Sensor_Value;

int main(void)
{
	uart2_rxtx_init();
	pa1_adc_init();

	while(1)
	{
		start_conversion();
		Sensor_Value = adc_read();
		printf("Sensor value: %d /n", (int)Sensor_Value);
	}
}
