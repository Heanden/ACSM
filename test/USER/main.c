#include "stm32f10x.h"
#include "iopush.h"
#include "key.h"
#include "leddt.h"
#include "myconfig.h"
#include "SysTick.h"
#include "uln2003.h"

extern void clockCount(void);
extern void stopWatchCount(void);

int main(void)
{
    int keyValue = 0;
    int leddtx = 0, ledx = 0, buzzerx = 0;
    SystemInit();
    allConfig();
    while (1)
    {
        clockCount();
        stopWatchCount();

        keyValue = Key_Scan();
        switch (keyValue)
        {
        case KEY_MODE:
            leddtx = 0;
            LED1(0);
            Delay_us(1000);
            LED1(1);
            break;
        case KEY_SET:
            leddtx = 1;
            LED2(0);
            Delay_us(1000);
            LED2(1);
            break;
        case KEY_RIGHT:
            ledx = 0;
            LED3(0);
            Delay_us(1000);
            LED3(1);
            break;
        case KEY_ADD:
            ledx = 1;
            LED4(0);
            Delay_us(1000);
            LED4(1);
            break;
        case KEY_SUB:
            buzzerx = 0;
            LED5(0);
            Delay_us(1000);
            LED5(1);
            break;
        case KEY_ENTER:
            buzzerx = 1;
            LED3(0);
            Delay_us(1000);
            LED3(1);
            break;
        default:
            leddtx = 0;
            ledx = 0;
            buzzerx = 0;
            break;
        }

        if (leddtx == 0)
        {
            switch (testCase)
            {
            case 0:
                leddtTest(0x78, 0, 0, 0);
                break;
            case 1:
                leddtTest(0, 0x7b, 0, 0);
                break;
            case 2:
                leddtTest(0, 0, 0x6d, 0);
                break;
            case 3:
                leddtTest(0, 0, 0, 0x78);
                break;
            case 4:
                leddtTest(0x80, 0x80, 0x80, 0x80);
                break;
            case 5:
                leddtTest(0x78, 0x7b, 0x6d, 0x78);
                break;
            case 6:
                leddtTest(0x80, 0x80, 0x80, 0x80);
                break;
            case 7:
                leddtTest(0x78, 0x7b, 0x6d, 0x78);
                break;
            default:
                testCase = 0;
                break;
            }
        }
        else
            leddtTest(0x3f, 0x4f, 0x07, 0x6d);

        if (ledx == 0)
        {
            LED1(1);
            LED2(1);
            LED3(1);
            LED4(1);
            LED5(1);
            LED6(1);
        }
        else
        {
            switch (testCase)
            {
            case 0:
                LED1(0);
                LED2(0);
                LED3(0);
                LED4(1);
                LED5(1);
                LED6(1);
                break;
            case 1:
                LED1(1);
                LED2(0);
                LED3(0);
                LED4(0);
                LED5(1);
                LED6(1);
                break;
            case 2:
                LED1(1);
                LED2(1);
                LED3(0);
                LED4(0);
                LED5(0);
                LED6(1);
                break;
            case 3:
                LED1(1);
                LED2(1);
                LED3(1);
                LED4(0);
                LED5(0);
                LED6(0);
                break;
            case 4:
                LED1(0);
                LED2(0);
                LED3(0);
                LED4(1);
                LED5(1);
                LED6(1);
                break;
            case 5:
                LED1(1);
                LED2(0);
                LED3(0);
                LED4(0);
                LED5(1);
                LED6(1);
                break;
            case 6:
                LED1(1);
                LED2(1);
                LED3(0);
                LED4(0);
                LED5(0);
                LED6(1);
                break;
            case 7:
                LED1(1);
                LED2(1);
                LED3(1);
                LED4(0);
                LED5(0);
                LED6(0);
                break;
            default:
                testCase = 0;
                break;
            }
        }

        if (buzzerx == 0)
            BUZZERCTL(2);
        else
            BUZZERCTL(0);

    } //循环
}
