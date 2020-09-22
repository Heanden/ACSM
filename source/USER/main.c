#include "stm32f10x.h"
#include "key.h"
#include "leddt.h"
#include "buzzer.h"
#include "led.h"

int main(void)
{
    int topMenu = 1, setCase = 1, posCase = 1, addCommand = 0, subCommand = 0, enterCommand = 0;
    SystemInit();
    keyConfig();
    leddtGpioConfig();
    int keyValue = 0;
    while (1)
    {
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
    }
}