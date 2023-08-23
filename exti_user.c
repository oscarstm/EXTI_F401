/*
 * exti_user.c
 *
 *  Created on: Aug 11, 2023
 *      Author: oscar
 */

#include "exti_user.h"

void EXTI_init(void) {
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOBEN);
	RCC->APB2ENR |= (RCC_APB2ENR_SYSCFGEN);

	GPIOB->MODER &= ~(GPIO_MODER_MODER2);
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR2);

	SYSCFG->EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI2);
	SYSCFG->EXTICR[0] |= (SYSCFG_EXTICR1_EXTI2_PB);

	EXTI->RTSR |= (EXTI_RTSR_TR2);
	EXTI->FTSR &= ~(EXTI_FTSR_TR2);
	//EXTI->PR |= EXTI_PR_PR2;
	EXTI->IMR |= (EXTI_IMR_MR2);

	NVIC_SetPriority(EXTI2_IRQn, 15);
	NVIC_EnableIRQ(EXTI2_IRQn);
}
