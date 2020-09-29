#ifndef __MYCONFIG_H
#define __MYCONFIG_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
void LED_GPIO_Config(void);
void LDR_input_config(void);
void buzzer(void);
void Key_GPIO_Config(void);
void leddtGpioConfig(void);
void steppingMotorConfig(void);
void allConfig(void);

#endif /* __MYCONFIG_H */
