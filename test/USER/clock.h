#ifndef __CLOCK_H
#define __CLOCK_H

#include "iopush.h"

__IO u8 secOnes = 0;
__IO u8 stopWatchMark = 0;

__IO u8 clockShow_hourTens = 0;
__IO u8 clockShow_hourOnes = 0;
__IO u8 clockShow_minTens = 0;
__IO u8 clockShow_minOnes = 0;

__IO u8 secTens = 0;
__IO u8 minTens = 0;
__IO u8 minOnes = 0;
__IO u8 hourTens = 0;
__IO u8 hourOnes = 0;

__IO u8 stopWatch_secOnes = 0;
__IO u8 stopWatch_secTens = 0;
__IO u8 stopWatch_minTens = 0;
__IO u8 stopWatch_minOnes = 0;

void clockCount(void);
void stopWatchCount(void);

#endif /* __CLOCK_H */
