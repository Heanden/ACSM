#include "stm32f10x.h"
#include "buzzer.h"
#include "clock.h"
#include "key.h"
#include "led.h"
#include "leddt.h"
#include "SysTick.h"
#include "uln2003.h"

__IO u8 clockShow_hourTens = 0;
__IO u8 clockShow_hourOnes = 0;
__IO u8 clockShow_minTens = 0;
__IO u8 clockShow_minOnes = 0;

int main(void)
{
    int topMenu = 1, setCase = 1, posCase = 1, addCommand = 0, subCommand = 0, enterCommand = 0;
    SystemInit();
    keyConfig();
    leddtGpioConfig();
    int keyValue = 0;
    while (1)
    {
        clockCount();
        stopWatchCount();

        keyValue = Key_Scan();
        switch (keyValue)
        {
        case KEY_MODE:
            if (topMenu < 3)
                topMenu++;
            else
                topMenu = 1;
            break;
        case KEY_SET:
            if (setCase < 3)
                setCase++;
            else
                setCase = 1;
            break;
        case KEY_RIGHT:
            if (posCase < 4)
                posCase++;
            else
                posCase = 1;
            break;
        case KEY_ADD:
            addCommand = 1;
            break;
        case KEY_SUB:
            subCommand = 1;
            break;
        case KEY_ENTER:
            enterCommand = 1;
            break;
        default:
            break;
        }

        switch (topMenu)
        {
        case 1:
            pushDigital(stopWatch_minTens, stopWatch_minOnes, stopWatch_secTens, stopWatch_secOnes);
            break;
        case 2:
            pushDigital(clockShow_hourTens, clockShow_hourOnes, clockShow_minTens, clockShow_minOnes);
            break;
        case 3:
            pushDigital(hourTens, hourOnes, minTens, minOnes);
            break;
        }

    } //循环
}