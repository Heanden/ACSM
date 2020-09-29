#include "leddt.h"

void pushDigital(int firstHigh, int secondHigh, int firstLow, int secondLow)
{
    int i;
    u8 CCCode[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
    u16 leddtDataFirst, leddtDataSecond;
    if ((firstHigh >= 0) & (secondHigh >= 0) & (firstLow >= 0) & (secondLow >= 0))
    {
        leddtDataFirst = (CCCode[firstHigh] << 8) | (CCCode[firstLow]);
        leddtDataSecond = (CCCode[secondHigh] << 8) | (CCCode[secondLow]);
    }
    else
    {
        if (firstHigh < 0)
        {
            leddtDataFirst = (0 << 8) | (CCCode[firstLow]);
            leddtDataSecond = (CCCode[secondHigh] << 8) | (CCCode[secondLow]);
        }
        if (firstLow < 0)
        {
            leddtDataFirst = (CCCode[firstHigh] << 8) | 0;
            leddtDataSecond = (CCCode[secondHigh] << 8) | (CCCode[secondLow]);
        }
        if (secondHigh < 0)
        {
            leddtDataFirst = (CCCode[firstHigh] << 8) | (CCCode[firstLow]);
            leddtDataSecond = (0 << 8) | (CCCode[secondLow]);
        }
        if (secondLow < 0)
        {
            leddtDataFirst = (CCCode[firstHigh] << 8) | (CCCode[firstLow]);
            leddtDataSecond = (CCCode[secondHigh] << 8) | 0;
        }
    }

    for (i = 0; i < 16; i++)
    {
        if (leddtDataFirst & 0x8000)
        {
            /*
            DAT = 1;
            CLK = 0;
            CLK = 1;
            */
            PA12(1);
            PB12(0);
            PB12(1);
        }
        else
        {
            /*
            DAT = 0;
            CLK = 0;
            CLK = 1;
            */
            PA12(0);
            PB12(0);
            PB12(1);
        }
        leddtDataFirst = leddtDataFirst << 1;

        if (leddtDataSecond & 0x8000)
        {
            /*
            DAT = 1;
            CLK = 0;
            CLK = 1;
            */
            PC14(1);
            PC13(0);
            PC13(1);
        }
        else
        {
            /*
            DAT = 0;
            CLK = 0;
            CLK = 1;
            */
            PC14(0);
            PC13(0);
            PC13(1);
        }
        leddtDataSecond = leddtDataSecond << 1;
    }
}

void leddtTest(u8 firstHigh, u8 firstLow, u8 secondHigh, u8 secondLow)
{
    int i;
    u16 leddtDataFirst, leddtDataSecond;

    leddtDataFirst = (firstHigh) | (firstLow);
    leddtDataSecond = (secondHigh << 8) | (secondLow);

    for (i = 0; i < 16; i++)
    {
        if (leddtDataFirst & 0x8000)
        {
            /*
            DAT = 1;
            CLK = 0;
            CLK = 1;
            */
            PA12(1);
            PB12(0);
            PB12(1);
        }
        else
        {
            /*
            DAT = 0;
            CLK = 0;
            CLK = 1;
            */
            PA12(0);
            PB12(0);
            PB12(1);
        }
        leddtDataFirst = leddtDataFirst << 1;

        if (leddtDataSecond & 0x8000)
        {
            /*
            DAT = 1;
            CLK = 0;
            CLK = 1;
            */
            PC14(1);
            PC13(0);
            PC13(1);
        }
        else
        {
            /*
            DAT = 0;
            CLK = 0;
            CLK = 1;
            */
            PC14(0);
            PC13(0);
            PC13(1);
        }
        leddtDataSecond = leddtDataSecond << 1;
    }
}