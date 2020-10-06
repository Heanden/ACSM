
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "SysTick.h"
#include "uln2003.h"

extern void timeCount(void);
extern void StopwatchCount(void);

int main(void)
{
  SystemInit();
  SysTick_Init();
  ulnhdr_config();

  while (1)
  {
    /******电机******/
    PA0(1);
    Delay_us(8000);
    PA0(0);
    PA1(1);
    Delay_us(8000);
    PA1(0);
    PA2(1);
    Delay_us(8000);
    PA2(0);
    PA3(1);
    Delay_us(8000);
    PA3(0);
    /******电机******/


  } //循环
}
