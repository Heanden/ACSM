#ifndef __CLOCK_H
#define __CLOCK_H

#include "stm32f10x.h"
#include "iopush.h"

__IO u8 secTens = 0;
__IO u8 minTens = 0;
__IO u8 minOnes = 0;
__IO u8 hourTens = 0;
__IO u8 hourOnes = 0;

__IO u8 stopWatch_secTens = 0;
__IO u8 stopWatch_minTens = 0;
__IO u8 stopWatch_minOnes = 0;

void clockCount(void);
void stopWatchCount(void);

#endif /* __CLOCK_H */
