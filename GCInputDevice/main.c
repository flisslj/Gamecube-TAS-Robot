
//#include "gpio.h"
#include <stdint.h>

#define DataPin00 0
#define DataPin01 1
#define DataPin02 2
#define DataPin03 3
#define DataPin04 4
#define DataPin05 5
#define DataPin06 6
#define DataPin07 7

#define CtrlIn1 8
#define CtrlIn2 9
#define CtrlIn3 10
#define CtrlIn4 11
#define CtrlOut1 12
#define CtrlOut2 13
#define CtrlOut3 14
#define CtrlOut4 15

#define ResetPin 16
#define ClockPin 17
#define SendPin 18
#define ResendPin 19

#define GCPowerPin 20


#define GPSET0 (volatile long *)0x3F20001C //GPIO  Pins 0-31     Pin Output Set 0 32 W
#define GPCLR0 (volatile long *)0x3F200028 //GPIO  Pins 0-31     Pin Output Clear 0 32 W

#define GPFSEL0 (volatile long *)0x3F200000 //GPIO Function Select 0 32 R/W 0-9
#define GPFSEL1 (volatile long *)0x3F200004 //GPIO Function Select 1 32 R/W 10-19
#define GPFSEL2 (volatile long *)0x3F200008 //GPIO Function Select 2 32 R/W 20-29

#define GPPUD     (volatile long *)0x3F200094 //GPIO Function Select 2 32 R/W 20-29
#define GPPUDCLK0 (volatile long *)0x3F200098 //GPIO Function Select 2 32 R/W 20-29

#define BUSY_WAIT __asm__ __volatile__("")
#define BUSY_WAIT_N 0x100000

void mainA()
{

    uint32_t i;
    /* At the low level, everything is done by writing to magic memory addresses.
     *
     * The device tree files (dtb / dts), which are provided by hardware vendors,
     * tell the Linux kernel about those magic values.
     */
    volatile uint32_t * const GPFSEL4 = (uint32_t *)0x3F200010;
    volatile uint32_t * const GPFSEL3 = (uint32_t *)0x3F20000C;
    volatile uint32_t * const GPSET1  = (uint32_t *)0x3F200020;
    volatile uint32_t * const GPCLR1  = (uint32_t *)0x3F20002C;
    *GPFSEL4 = (*GPFSEL4 & ~(7 << 21)) | (1 << 21);
    *GPFSEL3 = (*GPFSEL3 & ~(7 << 15)) | (1 << 15);
    while (1) { 
        *GPSET1 = 1 << (47 - 32);
        *GPCLR1 = 1 << (35 - 32);
        for (i = 0; i < BUSY_WAIT_N; ++i) { BUSY_WAIT; }
        *GPCLR1 = 1 << (47 - 32);
        *GPSET1 = 1 << (35 - 32);
        for (i = 0; i < BUSY_WAIT_N; ++i) { BUSY_WAIT; }
    }
}

void mainB()
{
    while (1)
    {
    }
}

void mainC()
{
    while (1)
    {
    }
}

void mainD()
{
    while (1)
    {
    }
}
/*
void initializePins()
{
    //Inputs
    SetGPIOFunc(DataPin00, FuncIn); //Data 0 Input
    SetGPIOFunc(DataPin01, FuncIn); //Data 1 Input
    SetGPIOFunc(DataPin02, FuncIn); //Data 2 Input
    SetGPIOFunc(DataPin03, FuncIn); //Data 3 Input
    SetGPIOFunc(DataPin04, FuncIn); //Data 4 Input
    SetGPIOFunc(DataPin05, FuncIn); //Data 5 Input
    SetGPIOFunc(DataPin06, FuncIn); //Data 6 Input
    SetGPIOFunc(DataPin07, FuncIn); //Data 7 Input

    SetGPIOFunc(CtrlIn1, FuncOut); //ctrl 1 Out
    SetGPIOFunc(CtrlIn2, FuncOut); //ctrl 2 Out
    SetGPIOFunc(CtrlIn3, FuncOut); //ctrl 3 Out
    SetGPIOFunc(CtrlIn4, FuncOut); //ctrl 4 Out
    SetGPIOFunc(CtrlOut1, FuncIn); //ctrl 1 In
    SetGPIOFunc(CtrlOut2, FuncIn); //ctrl 2 In
    SetGPIOFunc(CtrlOut3, FuncIn); //ctrl 3 In
    SetGPIOFunc(CtrlOut4, FuncIn); //ctrl 4 In

    SetGPIOFunc(ResetPin, FuncIn); //Reset
    SetGPIOFunc(ClockPin, FuncIn); //Clock

    SetGPIOFunc(SendPin, FuncOut);    //Send
    SetGPIOFunc(ResendPin, FuncOut);  //Resend
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
    setGPIORisingEdgeTrigger(ResetPin);
    setGPIOFallingEdgeTrigger(ResetPin);
}

//reset interupt has been triggerd. Run the reset routine.
void resetInterupt()
{
    clearGPIOEventDetect(ResetPin);
}

//Triggered by the dataclock. Reads the data on the datapins and writes that data to a buffer.
//when the data is done, crc is checked andthe data is added to the buffers.
void DataClockInterupt()
{
    clearGPIOEventDetect(ResetPin);
}

//Controller is triggered by the start of the gamecube polling for the next controller data.
void ControllerPollInterupt()
{
    clearGPIOEventDetect(CtrlIn1); // temporary
    clearGPIOEventDetect(CtrlIn2); // temporary
    clearGPIOEventDetect(CtrlIn3); // temporary
    clearGPIOEventDetect(CtrlIn4); // temporary
}

int controller1Data[64];
int controller2Data[64];
int controller3Data[64];
int controller4Data[64];

int controller1Bit;
int controller2Bit;
int controller3Bit;
int controller4Bit;

void controllerOutput2()
{
    //Start low.
    clearGPIO(CtrlOut2);

    //dealy for X time.

    //if 1, raise
    if (controller1Data[controller1Bit++])
    {
        setGPIO(CtrlOut2);
    }
    else
    {
        clearGPIO(CtrlOut2);
    }
    //delay for XX time

    //raise final bit
    setGPIO(CtrlOut2);
    //delay for X time.
}

void controllerOutput3()
{
    //Start low.
    clearGPIO(CtrlOut3);

    //dealy for X time.

    //if 1, raise
    if (controller1Data[controller1Bit++])
    {
        setGPIO(CtrlOut3);
    }
    else
    {
        clearGPIO(CtrlOut3);
    }
    //delay for XX time

    //raise final bit
    setGPIO(CtrlOut3);
    //delay for X time.
}

void controllerOutput4()
{
    //Start low.
    clearGPIO(CtrlOut4);

    //dealy for X time.

    //if 1, raise
    if (controller1Data[controller1Bit++])
    {
        setGPIO(CtrlOut4);
    }
    else
    {
        clearGPIO(CtrlOut4);
    }
    //delay for XX time

    //raise final bit
    setGPIO(CtrlOut4);
    //delay for X time.
}
*/