#include "buzzer.h"

void leddtGpioConfig(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /*pb1*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PC端口

    GPIO_SetBits(GPIOB, GPIO_Pin_1);
}