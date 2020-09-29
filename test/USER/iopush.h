/*********************
接线方式:
IN1 ---- PA3
IN2 ---- PA2
IN3 ---- PA1
IN4 ---- PA0
+   ---- +5V
-   ---- GND
*********************/

#ifndef __IOPUSH_H
#define __IOPUSH_H

#include "stm32f10x_conf.h"
/*********************拓展端口*********************/
/*PA3*/ //IN1
#define PA3(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_3); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_3)

/*PA2*/ //IN2
#define PA2(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_2); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_2)

/*PA1*/ //IN3
#define PA1(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_1); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_1)

/*PA0*/ //IN4
#define PA0(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_0); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_0)

/*PC15*/ //光敏电阻
#define PC15(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOC, GPIO_Pin_15); \
    else                                  \
        GPIO_ResetBits(GPIOC, GPIO_Pin_15)

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

/*********************蜂鸣器端口*********************/
/*PB9*/
#define BUZZERCTL(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_9); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_9)

/*********************按键端口*********************/
/*PB1*/
#define PB1(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_1); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_1)

/*PB0*/
#define PB0(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_0); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_0)

/*PA5*/
#define PA5(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_5); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_5)

/*PA6*/
#define PA6(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_6); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_6)

/*PA7*/
#define PA7(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_7); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_7)

/*********************LED端口*********************/
/*PA4*/
#define LED1(a)                          \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_4); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_4)

/*PB2*/
#define LED2(a)                          \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_2); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_2)

/*PB10*/
#define LED3(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_10); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_10)

/*PB7*/
#define LED5(a)                          \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_7); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_7)

/*PB11*/
#define LED4(a)                           \
    if (a)                                \
        GPIO_SetBits(GPIOB, GPIO_Pin_11); \
    else                                  \
        GPIO_ResetBits(GPIOB, GPIO_Pin_11)

/*PB8*/
#define LED6(a)                          \
    if (a)                               \
        GPIO_SetBits(GPIOB, GPIO_Pin_8); \
    else                                 \
        GPIO_ResetBits(GPIOB, GPIO_Pin_8)

#endif /* __IOPUSH_H */
