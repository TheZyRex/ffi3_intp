#ifndef MCPR_TIMER_H
#define MCPR_TIMER_H

#include <inttypes.h>
#include <stdbool.h>

// ResetCnt fuer delay funktion
static volatile uint8_t resetCnt = 0; 

// Timer Spezifisch
extern volatile uint32_t ms_counter;
extern volatile uint16_t display_counter;
extern volatile uint16_t button_counter;
extern volatile bool buttonTrigger;
extern volatile bool mainLoopTrigger;
extern volatile bool displayTrigger;
extern volatile bool displayRefresh;
extern volatile bool lauflichtTrigger;

void TIM6_DAC_IRQHandler(void);
void u_delay(uint16_t us);
void m_delay(uint16_t ms);

#endif
