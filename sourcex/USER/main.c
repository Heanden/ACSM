
#include "leddt.h"
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "SysTick.h"
#include "key.h"

u8 CCCode[17] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00};

extern void leddtFirst(u8 leddtHigh, u8 leddtLow);
extern void leddtSecond(u8 leddtHigh, u8 leddtLow);
extern void timeCount(void);
extern void StopwatchCount(void);

int main(void)
{
  int secOnesTemp, secTensTemp, minOnesTemp, minTensTemp, keyTemp = 0;
  int keyValue = 0, modeValue = 1, setValue = 1, rightValue = 0;
  int clocksShowFirstHigh, clocksShowFirstLow, clocksShowSecondHigh, clocksShowSecondLow;
  int infoShowFirstHigh = 0, infoShowFirstLow = 3, infoShowSecondHigh = 7, infoShowSecondLow = 2;
  int alarmNotesFirstHigh = 0, alarmNotesFirstLow = 0, alarmNotesSecondHigh = 0, alarmNotesSecondLow = 0;
  unsigned int blinkMark = 0;
  int alarmMark;
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

    /*****显示时钟*****/
    if (modeValue == 2 && setValue == 1 && !rightValue)
    {
      clocksShowFirstHigh = timeHrTensCount;
      clocksShowFirstLow = timeHrOnesCount;
      clocksShowSecondHigh = timeMinTensCount;
      clocksShowSecondLow = timeMinOnesCount;
    }
    /*****时钟闪烁第一位*****/
    else if (modeValue == 2 && setValue == 1 && rightValue == 1)
    {
      if (blinkMark)
        clocksShowFirstHigh = timeHrTensCount;
      else
        clocksShowFirstHigh = 16;
      clocksShowFirstLow = timeHrOnesCount;
      clocksShowSecondHigh = timeMinTensCount;
      clocksShowSecondLow = timeMinOnesCount;
    }
    /*****时钟闪烁第二位*****/
    else if (modeValue == 2 && setValue == 1 && rightValue == 2)
    {
      clocksShowFirstHigh = timeHrTensCount;
      if (blinkMark)
        clocksShowFirstLow = timeHrOnesCount;
      else
        clocksShowFirstLow = 16;
      clocksShowSecondHigh = timeMinTensCount;
      clocksShowSecondLow = timeMinOnesCount;
    }
    /*****时钟闪烁第三位*****/
    else if (modeValue == 2 && setValue == 1 && rightValue == 3)
    {
      clocksShowFirstHigh = timeHrTensCount;
      clocksShowFirstLow = timeHrOnesCount;
      if (blinkMark)
        clocksShowSecondHigh = timeMinTensCount;
      else
        clocksShowSecondHigh = 16;
      clocksShowSecondLow = timeMinOnesCount;
    }
    /*****时钟闪烁第四位*****/
    else if (modeValue == 2 && setValue == 1 && rightValue == 4)
    {
      clocksShowFirstHigh = timeHrTensCount;
      clocksShowFirstLow = timeHrOnesCount;
      clocksShowSecondHigh = timeMinTensCount;
      if (blinkMark)
        clocksShowSecondLow = timeMinOnesCount;
      else
        clocksShowSecondLow = 16;
    }
    /*****显示闹钟*****/
    else if (modeValue == 2 && setValue == 2 && !rightValue)
    {
      clocksShowFirstHigh = alarmNotesFirstHigh;
      clocksShowFirstLow = alarmNotesFirstLow;
      clocksShowSecondHigh = alarmNotesSecondHigh;
      clocksShowSecondLow = alarmNotesSecondLow;
    }
    /*****闹钟闪烁第一位*****/
    else if (modeValue == 2 && setValue == 2 && rightValue == 1)
    {
      if (blinkMark)
        clocksShowFirstHigh = alarmNotesFirstHigh;
      else
        clocksShowFirstHigh = 16;
      clocksShowFirstLow = alarmNotesFirstLow;
      clocksShowSecondHigh = alarmNotesSecondHigh;
      clocksShowSecondLow = alarmNotesSecondLow;
    }
    /*****闹钟闪烁第二位*****/
    else if (modeValue == 2 && setValue == 2 && rightValue == 2)
    {
      clocksShowFirstHigh = alarmNotesFirstHigh;
      if (blinkMark)
        clocksShowFirstLow = alarmNotesFirstLow;
      else
        clocksShowFirstLow = 16;
      clocksShowSecondHigh = alarmNotesSecondHigh;
      clocksShowSecondLow = alarmNotesSecondLow;
    }
    /*****闹钟闪烁第三位*****/
    else if (modeValue == 2 && setValue == 2 && rightValue == 3)
    {
      clocksShowFirstHigh = alarmNotesFirstHigh;
      clocksShowFirstLow = alarmNotesFirstLow;
      if (blinkMark)
        clocksShowSecondHigh = alarmNotesSecondHigh;
      else
        clocksShowSecondHigh = 16;
      clocksShowSecondLow = alarmNotesSecondLow;
    }
    /*****闹钟闪烁第四位*****/
    else if (modeValue == 2 && setValue == 2 && rightValue == 4)
    {
      clocksShowFirstHigh = alarmNotesFirstHigh;
      clocksShowFirstLow = alarmNotesFirstLow;
      clocksShowSecondHigh = alarmNotesSecondHigh;
      if (blinkMark)
        clocksShowSecondLow = alarmNotesSecondLow;
      else
        clocksShowSecondLow = 16;
    }

    if (secOnesTemp != timeSecOnesCount || secTensTemp != timeSecTensCount || minOnesTemp != timeMinOnesCount || minTensTemp != timeMinTensCount)
    {
      blinkMark = ~blinkMark;
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

        if (setValue == 3 && modeValue == 2)
        {
          setValue = 1;
        }

        LED2(0);
        break;
      case 3:
        if (rightValue < 4)
        {
          rightValue++;
        }
        else
        {
          rightValue = 1;
        }
        LED3(0);
        break;

      case 4:                                //add
        if (modeValue == 2 && setValue == 1) //clock
        {
          switch (rightValue)
          {
          case 1:
            timeHrTensCount++;
            break;
          case 2:
            timeHrOnesCount++;
            break;
          case 3:
            timeMinTensCount++;
            break;
          case 4:
            timeMinOnesCount++;
            break;
          default:
            break;
          }
        }
        else if (modeValue == 2 && setValue == 2) //alarm
        {
          switch (rightValue)
          {
          case 1:
            clocksShowFirstHigh++;
            break;
          case 2:
            clocksShowFirstLow++;
            break;
          case 3:
            clocksShowSecondHigh++;
            break;
          case 4:
            clocksShowSecondLow++;
            break;
          default:
            break;
          }
        }
        LED4(0);
        break;
      case 5:                                //sub
        if (modeValue == 2 && setValue == 1) //clock
        {
          switch (rightValue)
          {
          case 1:
            timeHrTensCount--;
            break;
          case 2:
            timeHrOnesCount--;
            break;
          case 3:
            timeMinTensCount--;
            break;
          case 4:
            timeMinOnesCount--;
            break;
          default:
            break;
          }
        }
        else if (modeValue == 2 && setValue == 2) //alarm
        {
          switch (rightValue)
          {
          case 1:
            clocksShowFirstHigh--;
            break;
          case 2:
            clocksShowFirstLow--;
            break;
          case 3:
            clocksShowSecondHigh--;
            break;
          case 4:
            clocksShowSecondLow--;
            break;
          default:
            break;
          }
        }
        LED5(0);
        break;
      case 6:
        rightValue = 0;
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
    if (alarmMark == 1)
    {
      if (alarmNotesFirstHigh == timeHrTensCount)
      {
        if (alarmNotesFirstHigh == timeHrTensCount)
        {
          if (alarmNotesFirstHigh == timeHrTensCount)
          {
            if (alarmNotesFirstHigh == timeHrTensCount)
            {
              if (blinkMark)
              {
                leddtFirst(0x78, 0x78);
                leddtSecond(0x78, 0x78);
              }
            }
          }
        }
      }
    }
  } //循环
}
