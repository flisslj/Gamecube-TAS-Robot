
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

    SetGPIOFunc(ResetPin, FuncIn);   //Reset
    SetGPIOFunc(ClockPin, FuncIn);   //Clock

    SetGPIOFunc(SendPin, FuncOut);   //Send
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
    setGPIORisingEdgeTrigger(ResetPin); 
    setGPIOFallingEdgeTrigger(ResetPin);
    
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

