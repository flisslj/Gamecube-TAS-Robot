
#include "gpio.h"

//     Function Select

void SetGPIOFunc(long gpio, GPIOFunc function)
{

    //divide the gpio by ten to get the bank. then switch case to the
    long Register = gpio / 10;
    long row = gpio % 10;

    //calculate the register that needs to be set.
    switch (Register)
    {
    case 0:
        *GPFSEL0 = (*GPFSEL0 & (~(0x7 << (row * 3)))) | (function << (row * 3));
        break;
    case 1:
        *GPFSEL1 = (*GPFSEL1 & (~(0x7 << (row * 3)))) | (function << (row * 3));
        break;
    case 2:
        *GPFSEL2 = (*GPFSEL2 & (~(0x7 << (row * 3)))) | (function << (row * 3));
        break;
    case 3:
        *GPFSEL3 = (*GPFSEL3 & (~(0x7 << (row * 3)))) | (function << (row * 3));
        break;
    case 4:
        *GPFSEL4 = (*GPFSEL4 & (~(0x7 << (row * 3)))) | (function << (row * 3));
        break;
    case 5:
        *GPFSEL5 = (*GPFSEL5 & (~(0x7 << (row * 3)))) | (function << (row * 3));
        break;
    }
}

void setGPIOFallingEdgeTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPFED0 = (*GPFED0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPFED1 = (*GPFED1) | 1 << (gpio - 32);
    }
}

void clearGPIOFallingEdgeTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPFED0 = (*GPFED0) & ~(1 << gpio);
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPFED1 = (*GPFED1) & ~(1 << gpio);
    }
}

void setGPIORisingEdgeTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPRED0 = (*GPRED0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPRED1 = (*GPRED1) | 1 << (gpio - 32);
    }
}

void clearGPIORisingEdgeTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPRED0 = (*GPRED0) & ~(1 << gpio);
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPRED1 = (*GPRED1) & ~(1 << gpio);
    }
}

void setGPIOLowSignalTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPLEN0 = (*GPLEN0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPLEN1 = (*GPLEN1) | 1 << (gpio - 32);
    }
}
void clearGPIOLowSignalTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPLEN0 = (*GPLEN0) & ~(1 << gpio);
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPLEN1 = (*GPLEN1) & ~(1 << gpio);
    }
}

void setGPIOHighSignalTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPHEN0 = (*GPHEN0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPHEN1 = (*GPHEN1) | 1 << (gpio - 32);
    }
}
void clearGPIOHighSignalTrigger(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPHEN0 = (*GPHEN0) & ~(1 << gpio);
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPHEN1 = (*GPHEN1) & ~(1 << gpio);
    }
}

long checkGPIOEventDetect(long gpio)
{

    long v = 0;
    if (gpio >= 0 && gpio <= 31)
    {
        v = (*GPEDS0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        v = (*GPEDS1) | 1 << (gpio - 32);
    }
    if (v)
    {
        return 1;
    }
    return 0;
}
void clearGPIOEventDetect(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPEDS0 = 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPEDS1 = 1 << (gpio - 32);
    }
}

//given a gpio pin, set that pin to 1.
void setGPIO(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPSET0 = 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPSET1 = 1 << (gpio - 32);
    }
}

//given a gpio pin, set that pin to 0;
void clearGPIO(long gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPCLR0 = 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPCLR1 = 1 << (gpio - 32);
    }
}

//get the values for the gpio 0-31
long getLowGPIO()
{
    return *GPLEV0;
}

//get the values for the gpio 32-53
long getHighGPIO()
{
    return *GPLEV1;
}

long getGPIOValue(long gpio)
{
    long v = 0;
    if (gpio >= 0 && gpio <= 31)
    {
        v = (*GPLEV0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        v = *GPLEV1 | 1 << (gpio - 32);
    }
    if (v)
    {
        return 1;
    }
    return 0;
}