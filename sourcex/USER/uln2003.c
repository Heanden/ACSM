/*******************************************************
ULN2003驱动5V减速步进电机程序
Target:STC89C52RC-40C
Crystal:12MHz
Author:战神单片机工作室
Platform:51&avr单片机最小系统板+ULN2003步进电机驱动套件
http://zsmcu.taobao.com   QQ:284083167
*******************************************************
接线方式:
IN1 ---- PA3
IN2 ---- PA2
IN3 ---- PA1
IN4 ---- PA0
HDRIO ---- PC15
+   ---- +5V
-   ---- GND
*********************/
#include "uln2003.h"                          //步进电机控制接口定义
uchar phasecw[4] = {0x08, 0x04, 0x02, 0x01};  //正转 电机导通相序 D-C-B-A
uchar phaseccw[4] = {0x01, 0x02, 0x04, 0x08}; //反转 电机导通相序 A-B-C-D
//ms延时函数

void ulnhdr_config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化PC端口

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //下拉输入
  GPIO_Init(GPIOC, &GPIO_InitStructure);        //初始化端口

  PA0(0);
  PA1(0);
  PA2(0);
  PA3(0);
}
