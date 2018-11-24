
#include "gpio.h"

void main()
{
    while (1)
    {
    }
}

#define DataPin00 0
#define DataPin01 1
#define DataPin02 2
#define DataPin03 3
#define DataPin04 4
#define DataPin05 5
#define DataPin06 6
#define DataPin07 7
#define DataPin08 8
#define DataPin09 9
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

