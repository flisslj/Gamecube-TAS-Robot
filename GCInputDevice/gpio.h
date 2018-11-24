
#ifndef raspberryPiGPIO_h
#define raspberryPiGPIO_h


#include <types.h>

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


void SetGPIOFunc(uint32_t gpio, GPIOFunc function);

void setGPIOFallingEdgeTrigger(uint32_t gpio);
void clearGPIOFallingEdgeTrigger(uint32_t gpio);

void setGPIORisingEdgeTrigger(uint32_t gpio);
void clearGPIORisingEdgeTrigger(uint32_t gpio);

void setGPIOLowSignalTrigger(uint32_t gpio);
void clearGPIOLowSignalTrigger(uint32_t gpio);

void setGPIOHighSignalTrigger(uint32_t gpio);
void clearGPIOHighSignalTrigger(uint32_t gpio);

int checkGPIOEventDetect(uint32_t gpio);
void clearGPIOEventDetect(uint32_t gpio);

//given a gpio pin, set that pin to 1.
void setGPIO(uint32_t gpio);
//given a gpio pin, set that pin to 0;
void clearGPIO(uint32_t gpio);
//get the values for the gpio 0-31
uint32_t getLowGPIO();
//get the values for the gpio 32-53
uint32_t getHighGPIO();
int getGPIOValue(uint32_t gpio);


#endif