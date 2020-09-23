/**************************************
 * 文件名  ：SysTick.c
 * 描述    ：SysTick 系统滴答时钟10us中断函数库,中断时间可自由配置，
 *           常用的有 1us 10us 1ms 中断。
 * 实验平台：MINI STM32开发板 基于STM32F103C8T6
 * 硬件连接：无
 * 库版本  ：ST3.0.0

*********************************************************/

#include "SysTick.h"

static __IO u32 TimingDelay;
__IO u8 secOnes = 0;
__IO u8 stopWatchMark = 0;
__IO u8 stopWatch_secOnes = 0;

/*初始化  SysTick*/
void SysTick_Init(void)
{
  /* SystemCoreClock / 1000    1ms中断一次
	 * SystemCoreClock / 100000	 10us中断一次
	 * SystemCoreClock / 1000000 1us中断一次
	 */
  if (SysTick_Config(SystemCoreClock))
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
  secOnes++;
  switch (stopWatchMark)
  {
  case 0: /*秒表转态为0复位状态*/
    stopWatch_secOnes = 0;
    break;

  case 1: /*秒表转态1为开始计时，即开始累加*/
    stopWatch_secOnes++;
    break;

    /*秒表转态2为暂停计时，即不累加，在default体现*/

  default:
    break;
  }
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}
