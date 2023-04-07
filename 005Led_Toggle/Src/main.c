/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	uint32_t *pClkCtrlReg   =   (uint32_t*)0x40023830;
	uint32_t *pPortAModeReg =   (uint32_t*)0x40020000;
	uint32_t *pPortAOutReg  =   (uint32_t*)0x40020014;

	//1. Enable the clock for GPIOA peripheral in the AHB1ENR
	*pClkCtrlReg |= (1 << 0);

	 //2. Configure the mode of the IO pin as output
	//a. Clearing the 10th and 11th bits position
	*pPortAModeReg &= ~(3 << 10);

	//b. Setting 10th bit position
	*pPortAModeReg |= (1 << 10);

	for(;;){

		//2. Set 5th bit of the output data register to make I/O pin-5 as HIGH
		*pPortAOutReg |= (1 << 5);

		//Introduce small human observable delay
		for(uint32_t i = 0; i < 300000; i++);

		//Turn OFF the LED
		*pPortAOutReg &= ~(1 << 5);

		//Introduce small human observable delay
		for(uint32_t i = 0; i < 300000; i++);

	}
}
