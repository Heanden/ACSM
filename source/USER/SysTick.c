/**************************************
 * �ļ���  ��SysTick.c
 * ����    ��SysTick ϵͳ�δ�ʱ��10us�жϺ�����,�ж�ʱ����������ã�
 *           ���õ��� 1us 10us 1ms �жϡ�
 * ʵ��ƽ̨��MINI STM32������ ����STM32F103C8T6
 * Ӳ�����ӣ���
 * ��汾  ��ST3.0.0

*********************************************************/

#include "SysTick.h"

static __IO u32 TimingDelay;
__IO u8 secOnes = 0;
__IO u8 stopWatchMark = 0;
__IO u8 stopWatch_secOnes = 0;

/*��ʼ��  SysTick*/
void SysTick_Init(void)
{
  /* SystemCoreClock / 1000    1ms�ж�һ��
	 * SystemCoreClock / 100000	 10us�ж�һ��
	 * SystemCoreClock / 1000000 1us�ж�һ��
	 */
  if (SysTick_Config(SystemCoreClock))
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
  secOnes++;
  switch (stopWatchMark)
  {
  case 0: /*���ת̬Ϊ0��λ״̬*/
    stopWatch_secOnes = 0;
    break;

  case 1: /*���ת̬1Ϊ��ʼ��ʱ������ʼ�ۼ�*/
    stopWatch_secOnes++;
    break;

    /*���ת̬2Ϊ��ͣ��ʱ�������ۼӣ���default����*/

  default:
    break;
  }
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}
