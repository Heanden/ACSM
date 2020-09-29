/*********************
接线方式:
IN1 ---- PA3
IN2 ---- PA2
IN3 ---- PA1
IN4 ---- PA0
+   ---- +5V
-   ---- GND
*********************/

#include "uln2003.h"

uchar phasecw[4] = {0x08, 0x04, 0x02, 0x01};  //正转 电机导通相序 D-C-B-A
uchar phaseccw[4] = {0x01, 0x02, 0x04, 0x08}; //反转 电机导通相序 A-B-C-D

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
        PA3(phase[i] & 0X08);
        PA2(phase[i] & 0X04);
        PA1(phase[i] & 0X02);
        PA0(phase[i] & 0X01);
        Delay_xms(4); //转速调节
    }
}