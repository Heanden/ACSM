#include "SysTick.h"

static __IO u32 TimingDelay;
__IO u32 secondCount = 0;

/*初始化  SysTick*/
void SysTick_Init(void)
{
  /* SystemCoreClock / 1000    1ms中断一次
	 * SystemCoreClock / 100000	 10us中断一次
	 * SystemCoreClock / 1000000 1us中断一次
	 */
  if (SysTick_Config(SystemCoreClock / 1000000))
  {
    /* Capture error */
    while (1)
      ;
  }
}

/*us延时程序,10us为一个单位 */
void Delay_us(__IO u32 nTime)
{
  TimingDelay = nTime;

  while (TimingDelay != 0)
    ;
}

/* 获取节拍程序，在 SysTick 中断函数 SysTick_Handler()调用	 */
void TimingDelay_Decrement(void)
{
	/*
  if (secondCount < 100000)
  {
    if (testCase < 7)
      testCase++;
    else
      testCase = 0;
    secondCount++;
  }
  else
    secondCount = 0;
	*/
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}
