#include "key.h"

/*	 ���ð����õ���I/O�� */
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //���������˿�PB��ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_Init(GPIOA, &GPIO_InitStructure);			 //��ʼ���˿�

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //���������˿�PB��ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //��������
	GPIO_Init(GPIOB, &GPIO_InitStructure);		  //��ʼ���˿�
}
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // ʹ��PC�˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ��PC�˿�

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // ʹ��PC�˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_10 | GPIO_Pin_7 | GPIO_Pin_11 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure); //��ʼ��PC�˿�
}

/*����ȷ����ʱ */
void Delay(__IO u32 nCount)
{
	for (; nCount != 0; nCount--)
		;
}
/* ����Ƿ��а������� */ //GPIO_ReadInputDataBit
u8 Key_Scan(void)
{
	PA5(1);
	PA6(0);
	PA7(0);
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
		{
			return 1;
		}
	}
	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
		{
			return 6;
		}
	}

	PA5(0);
	PA6(1);
	PA7(0);
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
		{
			return 2;
		}
	}
	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
		{
			return 5;
		}
	}

	PA5(0);
	PA6(0);
	PA7(1);
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
		{
			return 3;
		}
	}
	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
		{
			return 4;
		}
	}

	PA5(1);
	PA6(1);
	PA7(1);
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
		{
			return 0;
		}
	}
	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 1)
		{
			return 0;
		}
	}

	return 0;
}
