#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Init(void);
void Delay_us(__IO u32 nTime);
void TimingDelay_Decrement(void);
void timeCount(void);
void StopwatchCount(void);

extern unsigned int timeInterruptCount;
extern unsigned int timeSecOnesCount;
extern unsigned int timeSecTensCount;
extern unsigned int timeHrOnesCount;
extern unsigned int timeHrTensCount;
extern unsigned int timeMinOnesCount;
extern unsigned int timeMinTensCount;

extern unsigned int stopwatchInterruptCount;
extern unsigned int stopwatchSecOnesCount;
extern unsigned int stopwatchSecTensCount;
extern unsigned int stopwatchHrOnesCount;
extern unsigned int stopwatchHrTensCount;
extern unsigned int stopwatchMinOnesCount;
extern unsigned int stopwatchMinTensCount;

extern int keyValue, modeValue, setValue, rightValue, addValue, subValue, enterValue;

#endif /* __SYSTICK_H */
