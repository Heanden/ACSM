#ifndef __LEDDT_H
#define __LEDDT_H

#include "stm32f10x.h"

void leddtGpioConfig(void);
void pushDigital(int firstHigh, int secondHigh, int firstLow, int secondLow);

#endif /* __LEDDT_H */
