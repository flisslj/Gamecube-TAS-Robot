
#include <types.h>

void main()
{
    while (1)
    {
    }
}

#define GPSET0 (volatile uint32_t *)0x7E20001C //GPIO  Pins 0-31     Pin Output Set 0 32 W
#define GPSET1 (volatile uint32_t *)0x7E200020 //GPIO  Pins 32-53    Pin Output Set 1 32 W
#define GPCLR0 (volatile uint32_t *)0x7E200028 //GPIO  Pins 0-31     Pin Output Clear 0 32 W
#define GPCLR1 (volatile uint32_t *)0x7E20002C //GPIO  Pins 32-53    Pin Output Clear 1 32 W
#define GPLEV0 (volatile uint32_t *)0x7E200034 //GPIO  Pins 0-31     Pin Level 0 32 R
#define GPLEV1 (volatile uint32_t *)0x7E200038 //GPIO  Pins 32-53    Pin Level 1 32 R

#define GPEDS0 (volatile uint32_t *)0x7E200040 //GPIO Pins  0-31    Event Detect Status 0 32 R/W
#define GPEDS1 (volatile uint32_t *)0x7E200044 //GPIO Pins  32-53   Event Detect Status 1 32 R/W
#define GPREN0 (volatile uint32_t *)0x7E20004C //GPIO Pins  0-31    Rising Edge Detect Enable 0 32 R/W
#define GPREN1 (volatile uint32_t *)0x7E200050 //GPIO Pins  32-53   Rising Edge Detect Enable 1 32 R/W
#define GPFEN0 (volatile uint32_t *)0x7E200058 //GPIO Pins  0-31    Falling Edge Detect Enable 0 32 R/W
#define GPFEN1 (volatile uint32_t *)0x7E20005C //GPIO Pins  32-53   Falling Edge Detect Enable 1 32 R/W

#define GPFSEL0 (volatile uint32_t *)0x7E200000 //GPIO Function Select 0 32 R/W 0-9
#define GPFSEL1 (volatile uint32_t *)0x7E200004 //GPIO Function Select 1 32 R/W 10-19
#define GPFSEL2 (volatile uint32_t *)0x7E200008 //GPIO Function Select 2 32 R/W 20-29
#define GPFSEL3 (volatile uint32_t *)0x7E20000C //GPIO Function Select 3 32 R/W 30-39
#define GPFSEL4 (volatile uint32_t *)0x7E200010 //GPIO Function Select 4 32 R/W 40-49
#define GPFSEL5 (volatile uint32_t *)0x7E200014 //GPIO Function Select 5 32 R/W 50-53

typedef enum
{
    FuncIn,   //     000 = GPIO Pin 9 is an input
    FuncOut,  //     001 = GPIO Pin 9 is an output
    FuncAlt5, //     010 = GPIO Pin 9 takes alternate function 5
    FuncAlt4, //     011 = GPIO Pin 9 takes alternate function 4
    FuncAlt0, //     100 = GPIO Pin 9 takes alternate function 0
    FuncAlt1, //     101 = GPIO Pin 9 takes alternate function 1
    FuncAlt2, //     110 = GPIO Pin 9 takes alternate function 2
    FuncAlt3  //     111 = GPIO Pin 9 takes alternate function 3
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

void setGPIOFallingEdgeTrigger(uint32_t gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPFED0 = 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPFED1 = 1 << (gpio - 32);
    }
}

void setGPIORisingEdgeTrigger(uint32_t gpio)
{
    if (gpio >= 0 && gpio <= 31)
    {
        *GPRED0 = 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPRED1 = 1 << (gpio - 32);
    }
}

void clearGPIOEdgeTrigger(uint32_t gpio)
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

int checkGPIOEdgeTrigger(uint32_t gpio)
{

    int v = 0;
    if (gpio >= 0 && gpio <= 31)
    {
        v = (*GPEDS0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        v = *GPEDS1 | 1 << (gpio - 32);
    }
    if (v)
    {
        return 1;
    }
    return 0;
}

//given a gpio pin, set that pin to 1.
void setGPIO(uint32_t gpio)
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
void clearGPIO(uint32_t gpio)
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
uint32_t getLowGPIO()
{
    return *GPLEV0;
}

//get the values for the gpio 32-53
uint32_t getHighGPIO()
{
    return *GPLEV1;
}

int getGPIOValue(uint32_t gpio)
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

void initializePins()
{
    //Inputs
    SetGPIOFunc(0, FuncIn);
    SetGPIOFunc(1, FuncIn);
    SetGPIOFunc(2, FuncIn);
    SetGPIOFunc(3, FuncIn);
    SetGPIOFunc(4, FuncIn);
    SetGPIOFunc(5, FuncIn);
    SetGPIOFunc(6, FuncIn);
    SetGPIOFunc(7, FuncIn);
    SetGPIOFunc(8, FuncIn);
    SetGPIOFunc(9, FuncIn);
    SetGPIOFunc(10, FuncIn);
    SetGPIOFunc(11, FuncIn);
    SetGPIOFunc(12, FuncIn);
    SetGPIOFunc(13, FuncIn);
    SetGPIOFunc(14, FuncIn);
    SetGPIOFunc(15, FuncIn);

    SetGPIOFunc(16, FuncOut); //ctrl 1 Out
    SetGPIOFunc(17, FuncOut); //ctrl 2 Out
    SetGPIOFunc(18, FuncOut); //ctrl 3 Out
    SetGPIOFunc(19, FuncOut); //ctrl 4 Out
    SetGPIOFunc(20, FuncIn); //ctrl 1 In
    SetGPIOFunc(21, FuncIn); //ctrl 2 In
    SetGPIOFunc(22, FuncIn); //ctrl 3 In
    SetGPIOFunc(23, FuncIn); //ctrl 4 In

    SetGPIOFunc(24, FuncIn);  //Reset
    SetGPIOFunc(25, FuncIn);  //Clock
    SetGPIOFunc(26, FuncOut); //Resend

    SetGPIOFunc(27, FuncOut); //GC Power


    //Enable the rising edge triggers and falling edge triggers.
    setGPIOFallingEdgeTrigger(20);
    setGPIOFallingEdgeTrigger(21);
    setGPIOFallingEdgeTrigger(22);
    setGPIOFallingEdgeTrigger(23);
    
    setGPIORisingEdgeTrigger(20);
    setGPIORisingEdgeTrigger(21);
    setGPIORisingEdgeTrigger(22);
    setGPIORisingEdgeTrigger(23);
    


    //SetGPIOFunc(0, FuncOut); //ctrlr
}