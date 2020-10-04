#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define KEY_MODE 4
#define KEY_SET 5
#define KEY_RIGHT 6
#define KEY_ADD 3
#define KEY_SUB 2
#define KEY_ENTER 1

u8 Key_Scan(void);
void LED_GPIO_Config(void);
void Key_GPIO_Config(void);

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

#endif /* __KEY_H */
