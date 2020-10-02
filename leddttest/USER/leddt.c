#include "leddt.h"

void leddtGpioConfig(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化PC端口

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PC端口

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure); //初始化PC端口
}

void leddtFirst(u8 leddtHigh, u8 leddtLow)
{
    int i;
    u16 leddtData;

    leddtData = (leddtHigh << 8) | (leddtLow);

    for (i = 0; i < 16; i++)
    {
        if (leddtData & 0x8000)
        {
            /*
            DAT = 1;
            CLK = 0;
            CLK = 1;
            */
            PA12(1);
            PB12(0);
            PB12(1);
        }
        else
        {
            /*
            DAT = 0;
            CLK = 0;
            CLK = 1;
            */
            PA12(0);
            PB12(0);
            PB12(1);
        }
        leddtData = leddtData << 1;
    }
}
void leddtSecond(u8 leddtHigh, u8 leddtLow)
{
    int i;
    u16 leddtData;

    leddtData = (leddtHigh << 8) | (leddtLow);

    for (i = 0; i < 16; i++)
    {
        if (leddtData & 0x8000)
        {
            /*
            DAT = 1;
            CLK = 0;
            CLK = 1;
            */
            PC14(1);
            PC13(0);
            PC13(1);
        }
        else
        {
            /*
            DAT = 0;
            CLK = 0;
            CLK = 1;
            */
            PC14(0);
            PC13(0);
            PC13(1);
        }
        leddtData = leddtData << 1;
    }
}