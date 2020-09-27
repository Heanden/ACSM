#ifndef __MYCONFIG_H
#define __MYCONFIG_H

#include "stm32f10x.h"
#include "iopush.h"
#include "key.h"
#include "leddt.h"
#include "uln2003.h"
#include "SysTick.h"

void LED_GPIO_Config(void);
void LDR_input_config(void);
void buzzer(void);
void Key_GPIO_Config(void);
void leddtGpioConfig(void);
void steppingMotorConfig(void);
void allConfig(void);

#endif /* __MYCONFIG_H */
