#include "SysTick.h"

static __IO u32 TimingDelay;

unsigned int timeInterruptCount = 0;
unsigned int timeSecOnesCount = 0;
unsigned int timeSecTensCount = 0;
unsigned int timeHrOnesCount = 0;
unsigned int timeHrTensCount = 0;
unsigned int timeMinOnesCount = 0;
unsigned int timeMinTensCount = 0;

unsigned int stopwatchInterruptCount = 0;
unsigned int stopwatchSecOnesCount = 0;
unsigned int stopwatchSecTensCount = 0;
unsigned int stopwatchHrOnesCount = 0;
unsigned int stopwatchHrTensCount = 0;
unsigned int stopwatchMinOnesCount = 0;
unsigned int stopwatchMinTensCount = 0;

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
void TimingDelay_Decrement(void) //10us中断一次
{
  timeInterruptCount++;

  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}

void timeCount(void)
{
  if (timeInterruptCount > 1000000)
  {
    timeInterruptCount = 0;
    timeSecOnesCount++;
  }

  /******timeSecOnesCount******/
  if (timeSecOnesCount >= 10)
  {
    timeSecOnesCount = 0;
    timeSecTensCount++;
  }

  /******timeSecTensCount******/
  if (timeSecTensCount >= 6)
  {
    timeSecTensCount = 0;
    timeMinOnesCount++;
  }

  /******timeMinOnesCount******/
  if (timeMinOnesCount >= 10)
  {
    timeMinOnesCount = 0;
    timeMinTensCount++;
  }

  /******timeMinTensCount******/
  if (timeMinTensCount >= 6)
  {
    timeMinTensCount = 0;
    timeHrOnesCount++;
  }

  /******timeHrOnesCount******/
  if (timeHrOnesCount >= 10)
  {
    timeHrOnesCount = 0;
    timeHrTensCount++;
  }

  /******timeHrTensCount******/
  if (timeHrOnesCount >= 4 && timeHrTensCount >= 2)
  {
    timeHrOnesCount = 0;
    timeHrTensCount = 0;
  }
}

/*****************************秒表*****************************************/
void StopwatchCount(void)
{
  if (stopwatchInterruptCount > 1000000)
  {
    stopwatchInterruptCount = 0;
    stopwatchSecOnesCount++;
  }

  /******timeSecOnesCount******/
  if (stopwatchSecOnesCount >= 10)
  {
    stopwatchSecOnesCount = 0;
    stopwatchSecTensCount++;
  }

  /******timeSecTensCount******/
  if (stopwatchSecTensCount >= 6)
  {
    stopwatchSecTensCount = 0;
    stopwatchMinOnesCount++;
  }

  /******timeMinOnesCount******/
  if (stopwatchMinOnesCount >= 10)
  {
    stopwatchMinOnesCount = 0;
    stopwatchMinTensCount++;
  }

  /******timeMinTensCount******/
  if (stopwatchMinTensCount >= 6)
  {
    stopwatchMinTensCount = 0;
    stopwatchHrOnesCount++;
  }

  /******timeHrOnesCount******/
  if (stopwatchHrOnesCount >= 10)
  {
    stopwatchHrOnesCount = 0;
    stopwatchHrTensCount++;
  }

  /******timeHrTensCount******/
  if (stopwatchHrOnesCount >= 4 && stopwatchHrTensCount >= 2)
  {
    stopwatchHrOnesCount = 0;
    stopwatchHrTensCount = 0;
  }
}
