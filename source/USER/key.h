#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
/*******
 *按键按下标置
 KEY_ON 0
 KEY_OFF 1
 ********/
#define KEY_ON 0
#define KEY_OFF 1

#define KEY_MODE 4
#define KEY_SET 5
#define KEY_RIGHT 6
#define KEY_ADD 3
#define KEY_SUB 2
#define KEY_ENTER 1

void Key_GPIO_Config(u16 GPIO_Pin_x, u16 GPIOMode, u32 RCC_APB2Periph_GPIOx, GPIO_TypeDef *GPIOx);
u8 Key_Scan(void);

#endif /* __LED_H */
