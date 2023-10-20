#include <stm32f407xx.h>
#include "_mcpr_aufgabe3.h"
#include "mcpr_timer.h"
#include <stdbool.h>

// IRQ Handler fuer TIM6, welche fuer die delay funktionen genutzt wird
void TIM6_DAC_IRQHandler(void)
{
	if (TIM6->SR & TIM_SR_UIF)
	{
		// Resetten des Status Registers ansonsten wird die Service Routine sofort neu ausgeloest
		// gilt fuer alle Interrupts
		TIM6->SR &= ~TIM_SR_UIF;
		resetCnt++;
	}
	if (resetCnt == 2)
	{
		resetCnt = 0;
		//Beende den Timer
		TIM6->CR1 &= ~TIM_CR1_CEN;
	}
}

// Delay funktionen basierend auf dem TIM6 Interrupt
void u_delay(uint16_t us)
{
	// Setup Timer 6
	// aktivieren der TIM6 Clock auf bit 4
	RCC->APB1ENR |= (1<<4);
	
	// fuer mikro-sekunden genauigkeit benoetigen wir einen Timertakt von 1MHz
	TIM6->PSC = 83;
	TIM6->ARR = us-1;
	// Enable Interrupts
	TIM6->DIER |= TIM_DIER_UIE;
	NVIC_SetPriority(TIM6_DAC_IRQn, 8);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	TIM6->CNT = 0;
	// setze resetCnt auf 1 da wir nicht das problem wie beim ms timer haben (es ist nicht schoen aber es funktioniert)
	resetCnt = 1;
	TIM6->CR1 |= TIM_CR1_CEN;
	
	while(TIM6->CR1 & TIM_CR1_CEN);
	RCC->APB1ENR &= ~(1u<<4);
	NVIC_DisableIRQ(TIM6_DAC_IRQn);
}

void m_delay(uint16_t ms)
{
	// Setup Timer 6
	// aktivieren der TIM6 Clock auf bit 4
	RCC->APB1ENR |= (1<<4);
	
	// 84000 / 2, da allerdings 16bit register passt muss getrixt werden
	// Basistakt des Timers = 84Mhz
	// Fuer millisekunden genauigkeit benoetigen wir einen Timertakt von 1kHz
	TIM6->PSC = 42000-1;
	TIM6->ARR = (ms-1);
	TIM6->DIER |= TIM_DIER_UIE;
	NVIC_SetPriority(TIM6_DAC_IRQn, 8);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	TIM6->CNT = 0;
	TIM6->CR1 |= TIM_CR1_CEN;
	
	while(TIM6->CR1 & TIM_CR1_CEN);
	RCC->APB1ENR &= ~(1u<<4);
	NVIC_DisableIRQ(TIM6_DAC_IRQn);
}
