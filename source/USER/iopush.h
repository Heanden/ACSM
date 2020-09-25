/*********************
接线方式:
IN1 ---- PB13
IN2 ---- PB14
IN3 ---- PB15
IN4 ---- PA8
+   ---- +5V
-   ---- GND
*********************/

#ifndef __IOPUSH_H
#define __IOPUSH_H

#include "stm32f10x.h"
/*********************拓展端口*********************/
/*PA5*/
#define PA5(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_5); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_5)

/*PA4*/
#define PA4(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_4); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_4)

/*PA3*/
#define PA3(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_3); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_3)

/*PA2*/
#define PA2(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_2); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_2)

/*PA1*/
#define PA1(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_1); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_1)

/*********************数码管端口*********************/
/*PB11*/
#define PB11(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_11); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_11)

/*PB9*/
#define PB9(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_9); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_9)

/*********************蜂鸣器端口*********************/
/*PC15*/
#define PC15(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOC, GPIO_Pin_15); \
    else                                  \
        GPIO_ResetBits(GPIOC, GPIO_Pin_15)

/*********************按键端口*********************/
/*PA9*/
#define PA9(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_9); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_9)

/*PA15*/
#define PA15(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOA, GPIO_Pin_15); \
    else                                  \
        GPIO_ResetBits(GPIOA, GPIO_Pin_15)

/*PA12*/
#define PA12(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOA, GPIO_Pin_12); \
    else                                  \
        GPIO_ResetBits(GPIOA, GPIO_Pin_12)

/*PA11*/
#define PA11(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOA, GPIO_Pin_11); \
    else                                  \
        GPIO_ResetBits(GPIOA, GPIO_Pin_11)

/*PA10*/
#define PA10(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOA, GPIO_Pin_10); \
    else                                  \
        GPIO_ResetBits(GPIOA, GPIO_Pin_10)

/*********************LED端口*********************/
/*PB3*/
#define PB3(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_3); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_3)

/*PA8*/
#define PA8(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_8); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_8)

/*PB15*/
#define PB15(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_15); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_15)

/*PB13*/
#define PB13(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_13); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_13)

/*PB14*/
#define PB14(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_14); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_14)

/*PB12*/
#define PB12(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_12); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_12)

#endif /* __IOPUSH_H */