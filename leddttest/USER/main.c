
#include "leddt.h"
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "SysTick.h"
#include "key.h"

u8 CCCode[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

int main(void)
{
  int i, keyValue;
  SystemInit();
  SysTick_Init();
  leddtGpioConfig();
  Key_GPIO_Config();
  while (1)
  {
    keyValue = Key_Scan();
    if (keyValue)
    {
      leddtFirst(CCCode[keyValue], CCCode[keyValue]);
      leddtSecond(CCCode[keyValue], CCCode[keyValue]);
    }

    /*
      leddtFirst(CCCode[i], CCCode[0]);
      Delay_us(10);
      leddtSecond(CCCode[0], CCCode[0]);
      Delay_us(1000000 / 2);

      leddtFirst(CCCode[0], CCCode[i]);
      Delay_us(10);
      leddtSecond(CCCode[0], CCCode[0]);
      Delay_us(1000000 / 2);

      leddtFirst(CCCode[0], CCCode[0]);
      Delay_us(10);
      leddtSecond(CCCode[i], CCCode[0]);
      Delay_us(1000000 / 2);

      leddtFirst(CCCode[0], CCCode[0]);
      Delay_us(10);
      leddtSecond(CCCode[0], CCCode[i]);
      Delay_us(1000000 / 2);
      */

  } //循环
  return 0;
}
