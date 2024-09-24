/*
 * systick.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Tuan Dep Trai Vo Cung Tan
 */


/* typedef struct
{
  __IOM uint32_t CTRL;                   !< Offset: 0x000 (R/W)  SysTick Control and Status Register
  __IOM uint32_t LOAD;                   !< Offset: 0x004 (R/W)  SysTick Reload Value Register
  __IOM uint32_t VAL;                    !< Offset: 0x008 (R/W)  SysTick Current Value Register
  __IM  uint32_t CALIB;                  !< Offset: 0x00C (R/ )  SysTick Calibration Register
} SysTick_Type;*/

#include "systick.h"

/*1.
Program reload value.
2.
3.
Clear current value.
Program Control and Status register.*/

void delayMs(int time)
{
	// Set the reload value
	SysTick->LOAD = LOAD_VALUE;
	// Clear current value
	SysTick->VAL = 0;
	// Configure Control and Status Register
	SysTick->CTRL |= CTRL_CLKSOURCE;
	SysTick->CTRL |= CTRL_ENABLE;
	for (int i =0; i < time; i++)
	{
		while(!(SysTick->CTRL & CTRL_COUNTFLAG))
		{
		}
	}
	// Turn of Systick
	SysTick->CTRL = 0;
}

