#include "key.h"

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

	return 0;
}
