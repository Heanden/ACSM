/*************************************
 * 文件名  ：key.c
 * 描述    ：按键应用函数库
 * 实验平台：MINI STM32开发板 基于STM32F103C8T6
 * 硬件连接： PA0 - key1
 * 库版本  ：ST3.0.0

**********************************************************************************/

#include "key.h"

/*不精确的延时 */
void Delay(__IO u32 nCount)
{
	for (; nCount != 0; nCount--)
		;
}

/*	 配置按键用到的I/O口 */
void Key_GPIO_Config(u16 GPIO_Pin_x, u16 GPIOMode, u32 RCC_APB2Periph_GPIOx, GPIO_TypeDef *GPIOx)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx, ENABLE); //开启按键端口PB的时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIOMode; //端口配置为上拉输入
	GPIO_Init(GPIOx, &GPIO_InitStructure);	 //初始化端口
}

void keyConfig(void)
{
	Key_GPIO_Config(GPIO_Pin_14, GPIO_Mode_IPD, RCC_APB2Periph_GPIOC, GPIOC);	 //PC14,下拉输入
	Key_GPIO_Config(GPIO_Pin_1, GPIO_Mode_IPD, RCC_APB2Periph_GPIOA, GPIOA);	 //PA1,下拉输入
	Key_GPIO_Config(GPIO_Pin_13, GPIO_Mode_Out_PP, RCC_APB2Periph_GPIOC, GPIOC); //PC13,推挽输出
	Key_GPIO_Config(GPIO_Pin_15, GPIO_Mode_Out_PP, RCC_APB2Periph_GPIOC, GPIOC); //PC15,推挽输出
	Key_GPIO_Config(GPIO_Pin_0, GPIO_Mode_Out_PP, RCC_APB2Periph_GPIOA, GPIOA);	 //PA0,推挽输出
}
/* 检测是否有按键按下 */ //GPIO_ReadInputDataBit
u8 Key_Scan(void)
{
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	GPIO_SetBits(GPIOC, GPIO_Pin_15);
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 0)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) = 0)
		{
			return 1;
		}
	}
	else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) = 0)
		{
			return 2;
		}
	}

	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	GPIO_ResetBits(GPIOC, GPIO_Pin_15);
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 0)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) = 0)
		{
			return 3;
		}
	}
	else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) = 0)
		{
			return 4;
		}
	}

	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	GPIO_SetBits(GPIOC, GPIO_Pin_15);
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == 0)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) = 0)
		{
			return 5;
		}
	}
	else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		Delay(50000);
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) = 0)
		{
			return 6;
		}
	}

	return -1;
}
