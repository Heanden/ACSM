/*********************
接线方式:
IN1 ---- PB13
IN2 ---- PB14
IN3 ---- PB15
IN4 ---- PA8
+   ---- +5V
-   ---- GND
*********************/

#ifndef __ULN2003_H
#define __ULN2003_H

#include "stm32f10x.h"
#include "iopush.h"

#define uchar unsigned char
#define uint unsigned int

void Delay_xms(uint x);
void motorTurn(int x);

#endif /* __ULN2003_H */
