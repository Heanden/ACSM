#ifndef __ULN2003_H
#define __ULN2003_H

#include "stm32f10x.h"

#define uchar unsigned char
#define uint unsigned int

void ulnhdr_config(void);

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
/*PA0*/
#define PA0(a)                           \
    if (a)                               \
        GPIO_SetBits(GPIOA, GPIO_Pin_0); \
    else                                 \
        GPIO_ResetBits(GPIOA, GPIO_Pin_0)

#endif /* __ULN2003_H */
