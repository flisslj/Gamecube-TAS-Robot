
#include "gpio.h"


//     Function Select

void SetGPIOFunc(int gpio, GPIOFunc function)
{

    //divide the gpio by ten to get the bank. then switch case to the
    int Register = gpio / 10;
    int row = gpio % 10;

    //calculate the register that needs to be set.
    switch (Register){
    case 0:
        *GPFSEL0 = (function << (row * 3));
        break;
    case 1:
        *GPFSEL1 = (function << (row * 3));
        break;
    case 2:
        *GPFSEL2 = (function << (row * 3));
        break;
    case 3:
        *GPFSEL3 = (function << (row * 3));
        break;
    case 4:
        *GPFSEL4 = (function << (row * 3));
        break;
    case 5:
        *GPFSEL5 = (function << (row * 3));
        break;
    }


}

void setGPIOFallingEdgeTrigger(int gpio)
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

void clearGPIOFallingEdgeTrigger(int gpio)
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

void setGPIORisingEdgeTrigger(int gpio)
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

void clearGPIORisingEdgeTrigger(int gpio)
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

void setGPIOLowSignalTrigger(int gpio)
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
void clearGPIOLowSignalTrigger(int gpio)
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

void setGPIOHighSignalTrigger(int gpio)
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
void clearGPIOHighSignalTrigger(int gpio)
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

int checkGPIOEventDetect(int gpio)
{

    int v = 0;
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
void clearGPIOEventDetect(int gpio)
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
void setGPIO(int gpio)
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
void clearGPIO(int gpio)
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
int getLowGPIO()
{
    return *GPLEV0;
}

//get the values for the gpio 32-53
int getHighGPIO()
{
    return *GPLEV1;
}

int getGPIOValue(int gpio)
{
    int v = 0;
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