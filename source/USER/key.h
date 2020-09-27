#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
#include "iopush.h"
/*******
 *�������±���
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

u8 Key_Scan(void);

#endif /* __KEY_H */
