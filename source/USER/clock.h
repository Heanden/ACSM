#ifndef __CLOCK_H
#define __CLOCK_H

#include "stm32f10x.h"

__IO u8 secTens = 0;
__IO u8 minTens = 0;
__IO u8 minOnes = 0;
__IO u8 hourTens = 0;
__IO u8 hourOnes = 0;

__IO u8 secTens = 0;
__IO u8 minTens = 0;
__IO u8 minOnes = 0;

void clockCount(void);

#endif /* __CLOCK_H */
