/*
    Part of the Raspberry-Pi Bare Metal Tutorials
    https://www.valvers.com/rpi/bare-metal/
    Copyright (c) 2013, Brian Sidebotham

    This software is licensed under the MIT License.
    Please see the LICENSE file included with this software.

*/

/* The base address of the GPIO peripheral (ARM Physical Address) This is defined in the
   Peripherals manual provided by Broadcom and it differs between the different Raspberry Pi
   models */
#define IOBPLUS
#define RPI3

#define GPIO_BASE 0x3F200000UL

/* The RPi3B+ again made the ACT LED available on a GPIO pin (of course on yet another pin!) */
#define LED_GPFSEL GPIO_GPFSEL0
#define LED_GPFBIT 12
#define LED_GPSET GPIO_GPSET0
#define LED_GPCLR GPIO_GPCLR0
#define LED_GPIO_BIT 3
#define LED_READ_BIT 5

#define InputDeviceType 1
#define InputDeviceVersion 1
#define DataPin00 2   // physical pins 3
#define DataPin01 3   // physical pins 5
#define DataPin02 4   // physical pins 7
#define DataPin03 5   // physical pins 29
#define DataPin04 6   // physical pins 31
#define DataPin05 7   // physical pins 26
#define DataPin06 8   // physical pins 24
#define DataPin07 9   // physical pins 21
#define CtrlIn1 10	// physical pins 19
#define CtrlIn2 11	// physical pins 23
#define CtrlIn3 12	// physical pins 32
#define CtrlIn4 13	// physical pins 33
#define CtrlOut1 14   // physical pins 8
#define CtrlOut2 15   // physical pins 10
#define CtrlOut3 16   // physical pins 36
#define CtrlOut4 17   // physical pins 11
#define ResetPin 18   // physical pins 12
#define ClockPin 19   // physical pins 35
#define SendPin 20	// physical pins 38
#define ResendPin 21  // physical pins 40
#define GCResetPin 22 // Physical pins 15
#define GCPowerPin 23 // physical pins 16

#define GPIO_GPFSEL0 0
#define GPIO_GPFSEL1 1
#define GPIO_GPFSEL2 2
#define GPIO_GPFSEL3 3
#define GPIO_GPFSEL4 4
#define GPIO_GPFSEL5 5

#define GPIO_GPSET0 7
#define GPIO_GPSET1 8

#define GPIO_GPCLR0 10
#define GPIO_GPCLR1 11

#define GPIO_GPLEV0 13
#define GPIO_GPLEV1 14

#define GPIO_GPEDS0 16
#define GPIO_GPEDS1 17

#define GPIO_GPREN0 19
#define GPIO_GPREN1 20

#define GPIO_GPFEN0 22
#define GPIO_GPFEN1 23

#define GPIO_GPHEN0 25
#define GPIO_GPHEN1 26

#define GPIO_GPLEN0 28
#define GPIO_GPLEN1 29

#define GPIO_GPAREN0 31
#define GPIO_GPAREN1 32

#define GPIO_GPAFEN0 34
#define GPIO_GPAFEN1 35

#define GPIO_GPPUD 37
#define GPIO_GPPUDCLK0 38
#define GPIO_GPPUDCLK1 39

#define noop1 asm("nop");
#define noop10 \
	noop1;     \
	noop1;     \
	noop1;     \
	noop1;     \
	noop1;     \
	noop1;     \
	noop1;     \
	noop1;     \
	noop1;     \
	noop1;

#define noop100 \
	noop10;     \
	noop10;     \
	noop10;     \
	noop10;     \
	noop10;     \
	noop10;     \
	noop10;     \
	noop10;     \
	noop10;     \
	noop10;

#define noop1000 \
	noop100;     \
	noop100;     \
	noop100;     \
	noop100;     \
	noop100;     \
	noop100;     \
	noop100;     \
	noop100;     \
	noop100;     \
	noop100;

/** GPIO Register set */
volatile unsigned int *gpio;

/** Simple loop variable */
volatile unsigned int tim;
volatile int tim1;
volatile unsigned int inputValue;
volatile unsigned int risingEdge;
volatile unsigned int j = 0;
volatile unsigned int v1 = 0;

/** Main function - we'll never return from here */
int main(void) __attribute__((naked));
int main(void)
{
	/**/
	// ---------------------------------------------------------------------- Switch to Supervisor mode
	asm("mrs r0, cpsr");
	asm("bic r0, r0, #0x1F"); // clear mode bits
	asm("orr r0, r0, #0x13"); // set Supervisor mode
	asm("msr spsr_cxsf, r0");
	asm("add r0, pc, #4");  // hold (in ELR_hyp) the address to return to  (to make 'eret' working right)
	asm("msr ELR_hyp, r0"); // save the address in ELR_hyp
	asm("eret");			// apply the mode change (Exception return)

	/**/
	// ---------------------------------------------------------------------- Fill VBAR
	asm("mrc p15, 0, r1, c12, c0, 0"); // get VBAR
	asm("mov r0, #0x8000");			   // the address of our 8 handlers

	asm("ldmia r0!, {r2,r3,r4,r5, r6,r7,r8,r9}"); // load multiple registers from consecutive memory locations using an address from the register r0
	asm("stmia r1!, {r2,r3,r4,r5, r6,r7,r8,r9}"); // fill VBAR
	asm("ldmia r0!, {r2,r3,r4,r5, r6,r7,r8,r9}"); // continue filling VBAR...
	asm("stmia r1!, {r2,r3,r4,r5, r6,r7,r8,r9}");

	// ---------------------------------------------------------------------- Init cache
	asm("mov r12,#0");
	asm("mcr p15, 0, r12, c7, c10, 1"); // DCCMVAC - Clean data or unified cache line by virtual address to PoC.
	asm("dsb");							// Data sync barrier
	asm("mov r12, #0");
	asm("mcr p15, 0, r12, c7, c5, 0"); // ICIALLU - Invalidate all instruction caches to PoU. If branch predictors are architecturally visible, also flush them.
	asm("mov r12, #0");
	asm("mcr p15, 0, r12, c7, c5, 6"); // BPIALL  - Invalidate all entries from branch predictors.
	asm("dsb");						   // Data sync barrier
	asm("isb");						   // Instruction sync barrier

	//fucks it up.
	/*
	// ---------------------------------------------------------------------- Set secure state
	asm("mrc p15, 0, r1, c1, c1, 0"); // Get SCR  (Secure Configuration Register)
	asm("bic r1, r1, #1");			  // Reset 'Non-secure' bit (set secure state)
	asm("mcr p15, 0, r1, c1, c1, 0"); // Write to SCR

	*/
	// ---------------------------------------------------------------------- Turn on Instruction cache
	asm("mrc p15,0,r2,c1,c0,0");
	asm("orr r2, #0x1000"); // Instruction cache
	//orr r2, #0x0800    // Branch prediction (does not affect this result)
	//orr r2, #0x0004    // Data cache        (does not affect this result)
	//orr r2, #0x0001  // MMU               (does not work! don't know why yet)
	asm("mcr p15,0,r2,c1,c0,0");

	/* Assign the address of the GPIO peripheral (Using ARM Physical Address) */
	gpio = (unsigned int *)GPIO_BASE;

	/* Write 1 to the GPIO init nibble in the Function Select GPIO peripheral register to set
       the GPIO pin for the ACT LED as an output */
	gpio[GPIO_GPFSEL0] |= (1 << LED_GPFBIT);
	gpio[GPIO_GPFSEL0] |= (1 << 9);

	gpio[GPIO_GPFSEL0] &= ~(0b111 << 15); //clear function on
	gpio[GPIO_GPFSEL1] &= ~(0b111 << 0);  //clear function on
	gpio[LED_GPCLR] = (1 << 3);

	//
	gpio[LED_GPSET] = (1 << 3);

	while (1)
	{

		//output0();
		testRead();

		switch (v1)
		{
		case 1:
			//id.type[0] = 0x29;
			//id.type[1] = 0x00;
			output0();
			output0();
			output1();
			output0();

			output1();
			output0();
			output0();
			output1();

			output0();
			output0();
			output0();
			output0();

			output0();
			output0();
			output0();
			output0();

			output1();

		default:
			j = 0;
			while (j <= 8)
			{

				if ((v1 >> (8 - j)) & 0b1)
				{
					output1();
				}
				else
				{
					output0();
				}

				j = j + 1;
			}
		}
	}
}

volatile int v2 = 0;
void testRead()
{

	v1 = 0;

	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
	gpio[LED_GPSET] = (1 << 4);

	while ((gpio[GPIO_GPLEV0] & (1 << CtrlIn1)))
	{
		asm("nop");
		//read the reset pin. If reset, rerturn the controller reset value.
	}

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	v1 = (gpio[GPIO_GPLEV0] & (1 << CtrlIn1)) >> CtrlIn1 + (v1 << 1);
	gpio[LED_GPCLR] = (1 << 4);

	asm("push {r1}");
	asm("movs  r1, #110");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
}

void output1()
{
	//account for 3 instructions at the beginning of the function and one at the end by removing
	//several noops at the very end.

	gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);
	/*noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop10;
	noop10;
	noop10;
	noop10;
	noop10;
	noop10;
	noop10;*/

	asm("push {r1}");
	asm("movs  r1, #105");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	gpio[LED_GPSET] = (1 << LED_GPIO_BIT);
	/*noop1000;
	noop1000;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop10;
	noop10;
	noop10;*/

	asm("push {r1}");
	asm("movs  r1, #300");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
}

void output0()
{
	gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);
	/*noop1000;
	noop1000;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop10;
	noop10;
	noop10;
	noop10;
	noop10;*/

	asm("push {r1}");
	asm("movs  r1, #312");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");

	gpio[LED_GPSET] = (1 << LED_GPIO_BIT);
	/*noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop100;
	noop10;
	noop10;
	noop10;
	noop10;*/
	asm("push {r1}");
	asm("movs  r1, #80");
	asm("1: subs  r1, r1, #1");
	asm("bne 1b");
	asm("pop {r1}");
}