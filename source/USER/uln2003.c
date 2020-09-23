/*********************
接线方式:
IN1 ---- PB13
IN2 ---- PB14
IN3 ---- PB15
IN4 ---- PA8
+   ---- +5V
-   ---- GND
*********************/
#include "uln2003.h"

uchar phasecw[4] = {0x08, 0x04, 0x02, 0x01};  //正转 电机导通相序 D-C-B-A
uchar phaseccw[4] = {0x01, 0x02, 0x04, 0x08}; //反转 电机导通相序 A-B-C-D

//io初始化
void steppingMotorConfig()
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /*IN1 ---- PB13*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PC端口

    /*IN2 ---- PB14*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PC端口

    /*IN1 ---- PB15*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PC端口

    /*IN2 ---- PA8*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 使能PC端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化PC端口
}

//ms延时函数
void Delay_xms(uint x)
{
    uint i, j;
    for (i = 0; i < x; i++)
        for (j = 0; j < 112; j++)
            ;
}
//顺时针转动
void motorTurn(int x)
{
    uchar phase[4];
    uchar i;

    if (x < 0)
        for (i = 0; i < 4; i++)
            phase[i] = phaseccw[i]; //代入参数为负值，电机反转
    else if (x > 0)
        for (i = 0; i < 4; i++)
            phase[i] = phasecw[i]; //代入参数为正数，电机正转
    else
        for (i = 0; i < 4; i++) //代入参数为0，电机不转
            phase[i] = 0;

    for (i = 0; i < 4; i++)
    {
        PB13(phase[i] & 0X08);
        PB14(phase[i] & 0X04);
        PB15(phase[i] & 0X02);
        PA8(phase[i] & 0X01);
        Delay_xms(4); //转速调节
    }
}