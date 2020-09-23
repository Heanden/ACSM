#include "clock.h"

void clockCount(void)
{
    if (secOnes > 9)
    {
        secOnes = 0;
        secTens++;
    }

    if (secTens > 5)
    {
        secTens = 0;
        minOnes++;
    }

    if (minOnes > 9)
    {
        minOnes = 0;
        minTens++;
    }

    if (minTens > 5)
    {
        minTens = 0;
        hourOnes++;
    }

    if (hourOnes > 9)
    {
        hourOnes = 0;
        hourTens++;
    }

    if (hourTens > 1 && hourOnes > 3)
    {
        hourOnes = 0;
        hourTens = 0;
    }
}

void stopWatchCount(void)
{
    if (stopWatch_secOnes > 9)
    {
        stopWatch_secOnes = 0;
        stopWatch_secTens++;
    }

    if (stopWatch_secTens > 5)
    {
        stopWatch_secTens = 0;
        stopWatch_minOnes++;
    }

    if (stopWatch_minOnes > 9)
    {
        stopWatch_minOnes = 0;
        stopWatch_minTens++;
    }

    if (stopWatch_minTens > 5)
    {
        stopWatch_minTens = 0;
    }
}