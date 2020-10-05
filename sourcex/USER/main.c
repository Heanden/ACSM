
#include "leddt.h"
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "SysTick.h"
#include "key.h"

u8 CCCode[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

extern void leddtFirst(u8 leddtHigh, u8 leddtLow);
extern void leddtSecond(u8 leddtHigh, u8 leddtLow);
extern void timeCount(void);

int main(void)
{
  int keyValue = 1, modeValue = 1, setValue, rightValue, addValue, subValue, enterValue;
  int secOnesTemp, keyTemp = 0;
  int stopwatchShowFirstHigh, stopwatchShowFirstLow, stopwatchShowSecondHigh, stopwatchShowSecondLow;
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
    timeCount();
    StopwatchCount();
    if (secOnesTemp != timeSecOnesCount)
    {
      switch (modeValue)
      {
      case 1:
        leddtFirst(CCCode[timeMinTensCount], CCCode[timeMinOnesCount]);
        leddtSecond(CCCode[timeSecTensCount], CCCode[timeSecOnesCount]);

        break;
      case 2:
        leddtFirst(CCCode[2], CCCode[2]);
        leddtSecond(CCCode[2], CCCode[2]);
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
