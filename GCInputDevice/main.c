
#include <types.h>

void main()
{
    while (1)
    {
    }
}

#define GPSET0 (volatile uint32_t *)0x7E20001C //GPIO  Pins 0-31     Pin Output Set 0 32 W
#define GPSET1 (volatile uint32_t *)0x7E200020 //GPIO  Pins 32-53    Pin Output Set 1 32 W (Starts Counting at 0)
#define GPCLR0 (volatile uint32_t *)0x7E200028 //GPIO  Pins 0-31     Pin Output Clear 0 32 W
#define GPCLR1 (volatile uint32_t *)0x7E20002C //GPIO  Pins 32-53    Pin Output Clear 1 32 W (Starts Counting at 0)
#define GPLEV0 (volatile uint32_t *)0x7E200034 //GPIO  Pins 0-31     Pin Level 0 32 R
#define GPLEV1 (volatile uint32_t *)0x7E200038 //GPIO  Pins 32-53    Pin Level 1 32 R (Starts Counting at 0)

#define GPFSEL0 (volatile uint32_t *)0x7E200000 //GPIO Function Select 0 32 R/W 0-9
#define GPFSEL1 (volatile uint32_t *)0x7E200004 //GPIO Function Select 1 32 R/W 10-19
#define GPFSEL2 (volatile uint32_t *)0x7E200008 //GPIO Function Select 2 32 R/W 20-29
#define GPFSEL3 (volatile uint32_t *)0x7E20000C //GPIO Function Select 3 32 R/W 30-39
#define GPFSEL4 (volatile uint32_t *)0x7E200010 //GPIO Function Select 4 32 R/W 40-49
#define GPFSEL5 (volatile uint32_t *)0x7E200014 //GPIO Function Select 5 32 R/W 50-53

typedef enum
{
    In,   //     000 = GPIO Pin 9 is an input
    Out,  //     001 = GPIO Pin 9 is an output
    Alt5, //     010 = GPIO Pin 9 takes alternate function 5
    Alt4, //     011 = GPIO Pin 9 takes alternate function 4
    Alt0, //     100 = GPIO Pin 9 takes alternate function 0
    Alt1, //     101 = GPIO Pin 9 takes alternate function 1
    Alt2, //     110 = GPIO Pin 9 takes alternate function 2
    Alt3  //     111 = GPIO Pin 9 takes alternate function 3
} GPIOFunc;
//     Function Select

void SetGPIOFunc(uint32_t gpio, GPIOFunc function)
{

    //divide the gpio by ten to get the bank. then switch case to the
    uint32_t Register = gpio / 10;
    uint32_t row = gpio % 10;
    uint32_t *Address;

    //calculate the register that needs to be set.
    switch (Register)
    {
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

    //set the value at address to the function where the row times three is the lowest byte location.
    *Address = (function << (row * 3));
}

//given a gpio pin, set that pin to 1.
void setGPIO(uint32_t gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPSET0 = 1 << gpio
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPSET1 = 1 << (gpio-32)
    }
}

//given a gpio pin, set that pin to 0;
void clearGPIO(uint32_t gpio)
{
        if (gpio >= 0 && gpio <= 31)
    {
        *GPCLR0 = 1 << gpio
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPCLR1 = 1 << (gpio-32)
    }
}

//get the values for the gpio 0-31
uint32_t getLowGPIO()
{
    return *GPLEV0
}

//get the values for the gpio 32-53
uint32_t getHighGPIO()
{
    return *GPLEV1
}