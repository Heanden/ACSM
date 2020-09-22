/* description: LED digital tube*/

#include "leddt.h"

void leddtGpioConfig(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /*pb9->data*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PC端口

    /*pb8->clk*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PC端口
}

void pushDigital(int firstHigh, int secondHigh, int firstLow, int secondLow)
{
    u8 CCCode[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
    u32 leddtData;
    if ((firstHigh >= 0) & (secondHigh >= 0) & (firstLow >= 0) & (secondLow >= 0))
        leddtData = (CCCode[firstHigh] << 24) | (CCCode[firstLow] << 16) | (CCCode[secondHigh] << 8) | (CCCode[secondLow]);
    else
    {
        if (firstHigh < 0)
            leddtData = (0x0 << 24) | (CCCode[firstLow] << 16) | (CCCode[secondHigh] << 8) | (CCCode[secondLow]);
        else if (firstLow < 0)
            leddtData = (CCCode[firstHigh] << 24) | (0x0 << 16) | (CCCode[secondHigh] << 8) | (CCCode[secondLow]);
        else if (secondHigh < 0)
            leddtData = (CCCode[firstHigh] << 24) | (CCCode[firstLow] << 16) | (0x0 << 8) | (CCCode[secondLow]);
        else if (secondLow < 0)
            leddtData = (CCCode[firstHigh] << 24) | (CCCode[firstLow] << 16) | (CCCode[secondHigh] << 8) | (0x0);
    }

    int i;
    for (i = 0; i < 32; i++)
    {
        if (leddtData & 0x80000000)
        {
            /*
            DAT = 1;
            CLK = 0;
            CLK = 1;
            */
            GPIO_SetBits(GPIOB, GPIO_Pin_9);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_SetBits(GPIOB, GPIO_Pin_8);
        }
        else
        {
            /*
            DAT = 0;
            CLK = 0;
            CLK = 1;
            */
            GPIO_ResetBits(GPIOB, GPIO_Pin_9);
            GPIO_ResetBits(GPIOB, GPIO_Pin_8);
            GPIO_SetBits(GPIOB, GPIO_Pin_8);
        }
    }
}