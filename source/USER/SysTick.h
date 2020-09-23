#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

__IO u8 secOnes = 0;
__IO u8 stopWatchMark = 0;
__IO u8 stopWatch_secOnes = 0;

void SysTick_Init(void);
void Delay_us(__IO u32 nTime);

#endif /* __SYSTICK_H */
