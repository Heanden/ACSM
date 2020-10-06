/*******************************************************
ULN2003����5V���ٲ����������
Target:STC89C52RC-40C
Crystal:12MHz
Author:ս��Ƭ��������
Platform:51&avr��Ƭ����Сϵͳ��+ULN2003������������׼�
http://zsmcu.taobao.com   QQ:284083167
*******************************************************
���߷�ʽ:
IN1 ---- PA3
IN2 ---- PA2
IN3 ---- PA1
IN4 ---- PA0
HDRIO ---- PC15
+   ---- +5V
-   ---- GND
*********************/
#include "uln2003.h"                          //����������ƽӿڶ���
uchar phasecw[4] = {0x08, 0x04, 0x02, 0x01};  //��ת �����ͨ���� D-C-B-A
uchar phaseccw[4] = {0x01, 0x02, 0x04, 0x08}; //��ת �����ͨ���� A-B-C-D
//ms��ʱ����

void ulnhdr_config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ��PC�˿�

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //��������
  GPIO_Init(GPIOC, &GPIO_InitStructure);        //��ʼ���˿�

  PA0(0);
  PA1(0);
  PA2(0);
  PA3(0);
}
