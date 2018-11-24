
#include <types.h>

void main()
{
    while (1)
    {
    }
}

//Get and set values
#define GPSET0 (volatile uint32_t *)0x7E20001C //GPIO  Pins 0-31     Pin Output Set 0 32 W
#define GPSET1 (volatile uint32_t *)0x7E200020 //GPIO  Pins 32-53    Pin Output Set 1 32 W
#define GPCLR0 (volatile uint32_t *)0x7E200028 //GPIO  Pins 0-31     Pin Output Clear 0 32 W
#define GPCLR1 (volatile uint32_t *)0x7E20002C //GPIO  Pins 32-53    Pin Output Clear 1 32 W
#define GPLEV0 (volatile uint32_t *)0x7E200034 //GPIO  Pins 0-31     Pin Level 0 32 R
#define GPLEV1 (volatile uint32_t *)0x7E200038 //GPIO  Pins 32-53    Pin Level 1 32 R

//event registers
//detection
#define GPEDS0 (volatile uint32_t *)0x7E200040 //GPIO Pins  0-31    Event Detect Status 0 32 R/W
#define GPEDS1 (volatile uint32_t *)0x7E200044 //GPIO Pins  32-53   Event Detect Status 1 32 R/W
//edge
#define GPREN0 (volatile uint32_t *)0x7E20004C //GPIO Pins  0-31    Rising Edge Detect Enable 0 32 R/W
#define GPREN1 (volatile uint32_t *)0x7E200050 //GPIO Pins  32-53   Rising Edge Detect Enable 1 32 R/W
#define GPFEN0 (volatile uint32_t *)0x7E200058 //GPIO Pins  0-31    Falling Edge Detect Enable 0 32 R/W
#define GPFEN1 (volatile uint32_t *)0x7E20005C //GPIO Pins  32-53   Falling Edge Detect Enable 1 32 R/W
//level
#define GPHEN0 (volatile uint32_t *)0x7E200064 // GPIO Pin High Detect Enable 0 32 R/W
#define GPHEN1 (volatile uint32_t *)0x7E200068 // GPIO Pin High Detect Enable 1 32 R/W
#define GPLEN0 (volatile uint32_t *)0x7E200070 // GPIO Pin Low Detect Enable 0 32 R/W
#define GPLEN1 (volatile uint32_t *)0x7E200074 // GPIO Pin Low Detect Enable 1 32 R/W

//function select
#define GPFSEL0 (volatile uint32_t *)0x7E200000 //GPIO Function Select 0 32 R/W 0-9
#define GPFSEL1 (volatile uint32_t *)0x7E200004 //GPIO Function Select 1 32 R/W 10-19
#define GPFSEL2 (volatile uint32_t *)0x7E200008 //GPIO Function Select 2 32 R/W 20-29
#define GPFSEL3 (volatile uint32_t *)0x7E20000C //GPIO Function Select 3 32 R/W 30-39
#define GPFSEL4 (volatile uint32_t *)0x7E200010 //GPIO Function Select 4 32 R/W 40-49
#define GPFSEL5 (volatile uint32_t *)0x7E200014 //GPIO Function Select 5 32 R/W 50-53

#define DataPin00 00
#define DataPin01 01
#define DataPin02 02
#define DataPin03 03
#define DataPin04 04
#define DataPin05 05
#define DataPin06 06
#define DataPin07 07
#define DataPin08 08
#define DataPin09 09
#define DataPin10 10
#define DataPin11 11
#define DataPin12 12
#define DataPin13 13
#define DataPin14 14
#define DataPin15 15

#define CtrlIn1 16
#define CtrlIn2 17
#define CtrlIn3 18
#define CtrlIn4 19
#define CtrlOut1 20
#define CtrlOut2 21
#define CtrlOut3 22
#define CtrlOut4 23

#define ResetPin 24
#define ClockPin 25
#define ResendPin 26

#define GCPowerPin 27

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
        *GPFED0 = (*GPFED0) | 1 << gpio;
    }

    if (gpio >= 32 && gpio <= 53)
    {
        *GPFED1 = (*GPFED1) | 1 << (gpio - 32);
    }
}

void clearGPIOFallingEdgeTrigger(uint32_t gpio)
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

void setGPIORisingEdgeTrigger(uint32_t gpio)
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

void clearGPIORisingEdgeTrigger(uint32_t gpio)
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

void setGPIOLowSignalTrigger(uint32_t gpio)
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
void clearGPIOLowSignalTrigger(uint32_t gpio)
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

void setGPIOHighSignalTrigger(uint32_t gpio)
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
void clearGPIOHighSignalTrigger(uint32_t gpio)
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

int checkGPIOEventDetect(uint32_t gpio)
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
void clearGPIOEventDetect(uint32_t gpio)
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
    SetGPIOFunc(DataPin00, FuncIn);
    SetGPIOFunc(DataPin01, FuncIn);
    SetGPIOFunc(DataPin02, FuncIn);
    SetGPIOFunc(DataPin03, FuncIn);
    SetGPIOFunc(DataPin04, FuncIn);
    SetGPIOFunc(DataPin05, FuncIn);
    SetGPIOFunc(DataPin06, FuncIn);
    SetGPIOFunc(DataPin07, FuncIn);
    SetGPIOFunc(DataPin08, FuncIn);
    SetGPIOFunc(DataPin09, FuncIn);
    SetGPIOFunc(DataPin10, FuncIn);
    SetGPIOFunc(DataPin11, FuncIn);
    SetGPIOFunc(DataPin12, FuncIn);
    SetGPIOFunc(DataPin13, FuncIn);
    SetGPIOFunc(DataPin14, FuncIn);
    SetGPIOFunc(DataPin15, FuncIn);

    SetGPIOFunc(CtrlIn1, FuncOut); //ctrl 1 Out
    SetGPIOFunc(CtrlIn2, FuncOut); //ctrl 2 Out
    SetGPIOFunc(CtrlIn3, FuncOut); //ctrl 3 Out
    SetGPIOFunc(CtrlIn4, FuncOut); //ctrl 4 Out
    SetGPIOFunc(CtrlOut1, FuncIn); //ctrl 1 In
    SetGPIOFunc(CtrlOut2, FuncIn); //ctrl 2 In
    SetGPIOFunc(CtrlOut3, FuncIn); //ctrl 3 In
    SetGPIOFunc(CtrlOut4, FuncIn); //ctrl 4 In

    SetGPIOFunc(ResetPin, FuncIn);   //Reset
    SetGPIOFunc(ClockPin, FuncIn);   //Clock/Send
    SetGPIOFunc(ResendPin, FuncOut); //Resend

    SetGPIOFunc(GCPowerPin, FuncOut); //GC Power

    //Enable the rising edge triggers and falling edge triggers.
    setGPIOFallingEdgeTrigger(CtrlIn1);
    setGPIOFallingEdgeTrigger(CtrlIn2);
    setGPIOFallingEdgeTrigger(CtrlIn3);
    setGPIOFallingEdgeTrigger(CtrlIn4);

    setGPIORisingEdgeTrigger(CtrlIn1);
    setGPIORisingEdgeTrigger(CtrlIn2);
    setGPIORisingEdgeTrigger(CtrlIn3);
    setGPIORisingEdgeTrigger(CtrlIn4);

    setGPIORisingEdgeTrigger(ClockPin);
}


//reset interupt has been triggerd. Run the reset routine.
void resetInterupt()
{
    clearGPIOEventDetect(ResetPin)
}

//Triggered by the dataclock. Reads the data on the datapins and writes that data to a buffer.
//when the data is done, crc is checked andthe data is added to the buffers.
void DataClockInterupt()
{
    clearGPIOEventDetect(ResetPin)
}

//Controller is triggered by the start of the gamecube polling for the next controller data. 
void ControllerPollInterupt()
{
    clearGPIOEventDetect(CtrlIn1) // temporary
    clearGPIOEventDetect(CtrlIn2) // temporary
    clearGPIOEventDetect(CtrlIn3) // temporary
    clearGPIOEventDetect(CtrlIn4) // temporary
}

