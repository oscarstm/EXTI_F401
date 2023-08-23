#include "stm32f4xx.h"

#include "clk_user.h"
#include "gpio_user.h"
#include "exti_user.h"

int main(void) {
	clk_user();
	GPIO_Init();
	EXTI_init();

	while (1) {
		// For test lamp
		GPIOC->ODR |= (GPIO_BSRR_BR13);
	}

}

void EXTI2_IRQHandler(void) {
	if ((EXTI->PR & EXTI_PR_PR2) == EXTI_PR_PR2) {
		GPIOC->ODR |= (GPIO_ODR_ODR_13);
		EXTI->PR |= (EXTI_PR_PR2);
	}
}
