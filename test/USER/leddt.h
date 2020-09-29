#ifndef __LEDDT_H
#define __LEDDT_H

#include "stm32f10x.h"
#include "iopush.h"

void pushDigital(int firstHigh, int secondHigh, int firstLow, int secondLow);
void leddtTest(u8 firstHigh, u8 firstLow, u8 secondHigh, u8 secondLow);

#endif /* __LEDDT_H */
