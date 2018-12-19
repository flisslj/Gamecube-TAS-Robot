
#ifndef raspberryPiGPIO_h
#define raspberryPiGPIO_h



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

//Get and set values
#define GPSET0 (volatile long *)0x3F20001C //GPIO  Pins 0-31     Pin Output Set 0 32 W
#define GPSET1 (volatile long *)0x3F200020 //GPIO  Pins 32-53    Pin Output Set 1 32 W
#define GPCLR0 (volatile long *)0x3F200028 //GPIO  Pins 0-31     Pin Output Clear 0 32 W
#define GPCLR1 (volatile long *)0x3F20002C //GPIO  Pins 32-53    Pin Output Clear 1 32 W
#define GPLEV0 (volatile long *)0x3F200034 //GPIO  Pins 0-31     Pin Level 0 32 R
#define GPLEV1 (volatile long *)0x3F200038 //GPIO  Pins 32-53    Pin Level 1 32 R

//event registers              0x00200000 
//detection                    0x3F000000
#define GPEDS0 (volatile long *)0x3F200040 //GPIO Pins  0-31    Event Detect Status 0 32 R/W
#define GPEDS1 (volatile long *)0x3F200044 //GPIO Pins  32-53   Event Detect Status 1 32 R/W
//edge
#define GPRED0 (volatile long *)0x3F20004C //GPIO Pins  0-31    Rising Edge Detect Enable 0 32 R/W
#define GPRED1 (volatile long *)0x3F200050 //GPIO Pins  32-53   Rising Edge Detect Enable 1 32 R/W
#define GPFED0 (volatile long *)0x3F200058 //GPIO Pins  0-31    Falling Edge Detect Enable 0 32 R/W
#define GPFED1 (volatile long *)0x3F20005C //GPIO Pins  32-53   Falling Edge Detect Enable 1 32 R/W
//level
#define GPHEN0 (volatile long *)0x3F200064 // GPIO Pin High Detect Enable 0 32 R/W
#define GPHEN1 (volatile long *)0x3F200068 // GPIO Pin High Detect Enable 1 32 R/W
#define GPLEN0 (volatile long *)0x3F200070 // GPIO Pin Low Detect Enable 0 32 R/W
#define GPLEN1 (volatile long *)0x3F200074 // GPIO Pin Low Detect Enable 1 32 R/W

//function select
#define GPFSEL0 (volatile long *)0x3F200000 //GPIO Function Select 0 32 R/W 0-9
#define GPFSEL1 (volatile long *)0x3F200004 //GPIO Function Select 1 32 R/W 10-19
#define GPFSEL2 (volatile long *)0x3F200008 //GPIO Function Select 2 32 R/W 20-29
#define GPFSEL3 (volatile long *)0x3F20000C //GPIO Function Select 3 32 R/W 30-39
#define GPFSEL4 (volatile long *)0x3F200010 //GPIO Function Select 4 32 R/W 40-49
#define GPFSEL5 (volatile long *)0x3F200014 //GPIO Function Select 5 32 R/W 50-53


void SetGPIOFunc(long  gpio, GPIOFunc function);

void setGPIOFallingEdgeTrigger(long  gpio);
void clearGPIOFallingEdgeTrigger(long  gpio);

void setGPIORisingEdgeTrigger(long  gpio);
void clearGPIORisingEdgeTrigger(long  gpio);

void setGPIOLowSignalTrigger(long  gpio);
void clearGPIOLowSignalTrigger(long  gpio);

void setGPIOHighSignalTrigger(long  gpio);
void clearGPIOHighSignalTrigger(long  gpio);

long  checkGPIOEventDetect(long  gpio);
void clearGPIOEventDetect(long  gpio);

//given a gpio pin, set that pin to 1.
void setGPIO(long  gpio);
//given a gpio pin, set that pin to 0;
void clearGPIO(long  gpio);
//get the values for the gpio 0-31
long  getLowGPIO();
//get the values for the gpio 32-53
long  getHighGPIO();
long  getGPIOValue(long  gpio);


#endif