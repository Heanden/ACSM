
#include "leddt.h"
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "SysTick.h"
#include "key.h"

u8 CCCode[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

extern void leddtFirst(u8 leddtHigh, u8 leddtLow);
extern void leddtSecond(u8 leddtHigh, u8 leddtLow);
extern void timeCount(void);
extern void StopwatchCount(void);

int main(void)
{
  int secOnesTemp, secTensTemp, minOnesTemp, minTensTemp, keyTemp = 0;
  int keyValue = 1, modeValue = 1, setValue, rightValue, addValue, subValue, enterValue;
  int clocksShowFirstHigh, clocksShowFirstLow, clocksShowSecondHigh, clocksShowSecondLow;
  int infoShowFirstHigh = 0, infoShowFirstLow = 3, infoShowSecondHigh = 7, infoShowSecondLow = 2;
  SystemInit();
  SysTick_Init();
  leddtGpioConfig();
  Key_GPIO_Config();
  LED_GPIO_Config();
  keyValue = Key_Scan();

  while (1)
  {
    secOnesTemp = timeSecOnesCount;
    secTensTemp = timeSecTensCount;
    minOnesTemp = timeMinOnesCount;
    minTensTemp = timeMinTensCount;
    timeCount();
    StopwatchCount();
    clocksShowFirstHigh = timeMinTensCount;
    clocksShowFirstLow = timeMinOnesCount;
    clocksShowSecondHigh = timeSecTensCount;
    clocksShowSecondLow = timeSecOnesCount;

    if (secOnesTemp != timeSecOnesCount || secTensTemp != timeSecTensCount || minOnesTemp != timeMinOnesCount || minTensTemp != timeMinTensCount)
    {
      if (modeValue == 1)
      {
        switch (setValue)
        {
        case 2:
          stopwatchSecOnesCount++;
          break;
        case 3:
          break;
        default:
          stopwatchSecOnesCount = 0;
          stopwatchSecTensCount = 0;
          stopwatchMinOnesCount = 0;
          stopwatchMinTensCount = 0;
          break;
        }
      }
      switch (modeValue)
      {
      case 1:
        leddtFirst(CCCode[stopwatchMinTensCount], CCCode[stopwatchMinOnesCount]);
        leddtSecond(CCCode[stopwatchSecTensCount], CCCode[stopwatchSecOnesCount]);
        break;
      case 2:
        leddtFirst(CCCode[clocksShowFirstHigh], CCCode[clocksShowFirstLow]);
        leddtSecond(CCCode[clocksShowSecondHigh], CCCode[clocksShowSecondLow]);
        break;
      case 3:
        leddtSecond(CCCode[infoShowSecondHigh], CCCode[infoShowSecondLow]);
        leddtFirst(CCCode[infoShowFirstHigh], CCCode[infoShowFirstLow]);
        break;
      default:
        leddtSecond(CCCode[0], CCCode[3]);
        leddtFirst(CCCode[7], CCCode[2]);
        break;
      }
    }

    keyValue = Key_Scan();
    if (keyTemp != keyValue)
    {
      switch (keyValue)
      {
      case 1:
        if (modeValue < 3)
        {
          modeValue++;
        }
        else
        {
          modeValue = 1;
        }
        LED1(0);
        break;
      case 2:
        if (setValue < 3)
        {
          setValue++;
        }
        else
        {
          setValue = 1;
        }
        LED2(0);
        break;
      case 3:
        LED3(0);
        break;
      case 4:
        LED4(0);
        break;
      case 5:
        LED5(0);
        break;
      case 6:
        LED6(0);
        break;
      default:
        LED1(1);
        LED2(1);
        LED3(1);
        LED4(1);
        LED5(1);
        LED5(1);
        LED6(1);
        break;
      }
    }
    keyTemp = keyValue;
  } //循环
}
