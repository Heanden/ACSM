#include "stm32f10x.h"
#include "key.h"

int main(void)
{
    int topMenu = 1, setCase = 1, posCase = 1, addCommand = 0, subCommand = 0, enterCommand = 0;
    SystemInit();
    Key_GPIO_Config(GPIO_Pin_14, GPIO_Mode_Out_PP, RCC_APB2Periph_GPIOC, GPIOC); //PC14,推挽输出
    Key_GPIO_Config(GPIO_Pin_1, GPIO_Mode_Out_PP, RCC_APB2Periph_GPIOA, GPIOA);  //PA1,推挽输出
    Key_GPIO_Config(GPIO_Pin_13, GPIO_Mode_IPD, RCC_APB2Periph_GPIOC, GPIOC);    //PC13,下拉输入
    Key_GPIO_Config(GPIO_Pin_15, GPIO_Mode_IPD, RCC_APB2Periph_GPIOC, GPIOC);    //PC15,下拉输入
    Key_GPIO_Config(GPIO_Pin_0, GPIO_Mode_IPD, RCC_APB2Periph_GPIOA, GPIOA);     //PA0,下拉输入

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