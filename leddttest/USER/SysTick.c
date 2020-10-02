#include "SysTick.h"

static __IO u32 TimingDelay;
__IO u32 secondCount = 0;

/*��ʼ��  SysTick*/
void SysTick_Init(void)
{
  /* SystemCoreClock / 1000    1ms�ж�һ��
	 * SystemCoreClock / 100000	 10us�ж�һ��
	 * SystemCoreClock / 1000000 1us�ж�һ��
	 */
  if (SysTick_Config(SystemCoreClock / 1000000))
  {
    /* Capture error */
    while (1)
      ;
  }
}

/*us��ʱ����,10usΪһ����λ */
void Delay_us(__IO u32 nTime)
{
  TimingDelay = nTime;

  while (TimingDelay != 0)
    ;
}

/* ��ȡ���ĳ����� SysTick �жϺ��� SysTick_Handler()����	 */
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
