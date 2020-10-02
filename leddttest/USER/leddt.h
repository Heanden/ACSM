#ifndef __LEDDT_H
#define __LEDDT_H

#include "stm32f10x.h"

/*********************数码管端口*********************/
/*****u2-u3*****/
/*PC13*/ //clk
#define PC13(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOC, GPIO_Pin_13); \
    else                                  \
        GPIO_ResetBits(GPIOC, GPIO_Pin_13)

/*PC14*/ //data
#define PC14(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOC, GPIO_Pin_14); \
    else                                  \
        GPIO_ResetBits(GPIOC, GPIO_Pin_14)

/*****u4-u5*****/
/*PB12*/ //clk
#define PB12(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_12); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_12)

/*PA12*/ //data
#define PA12(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOA, GPIO_Pin_12); \
    else                                  \
        GPIO_ResetBits(GPIOA, GPIO_Pin_12)

void leddtTest(u8 firstHigh, u8 firstLow, u8 secondHigh, u8 secondLow);
void leddtGpioConfig(void);

#endif /* __LEDDT_H */
