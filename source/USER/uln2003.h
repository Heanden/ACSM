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

#define uchar unsigned char
#define uint unsigned int

#define PB13(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_13); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_13)

#define PB14(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_14); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_14)

#define PB15(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_15); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_15)

#define PA8(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_8); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_8)

void steppingMotorConfig();
void Delay_xms(uint x);
void motorTurn(int x);

#endif /* __ULN2003_H */