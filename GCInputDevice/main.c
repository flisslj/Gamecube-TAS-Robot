#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define testControllerPlayback 1 //THis value is if the controller playback is in testing more or not.
#define wait 0					 //this value defines if the reset triggers should be waited for or not.

void reset();
int main();
void outputOnDataPins(uint8_t num);
uint8_t inputOnDataPins();
void playback();
void getFrame();
void outputFrame();
void testOutput();
void outputData(int bits, int *data, int loops);
int readCommand();
int readBit();

//values of the first byte.
#define CMD_ID 0x00			 //0
#define CTRL_RESET 0x01		 //1
#define CMD_STATUS 0x40		 //64
#define CMD_ORIGIN 0x41		 //65
#define CMD_RECELEBRATE 0x42 //66
#define CMD_STATUS_LONG 0x43 //67
#define CMD_RESET 0xFF		 //255

int main()
{
	printf("Initializing\n");

	//reset();
	testTiming();
}

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

#define frameSize 40

#define testReset               \
	if (!digitalRead(ResetPin)) \
	{                           \
		return;                 \
	};

#define noopCount 165
#define writeWait                        \
	for (int i = 0; i <= noopCount; i++) \
	{                                    \
		asm("nop");                      \
	}

#define write1(pin)       \
	digitalWrite(pin, 1); \
	writeWait;            \
	digitalWrite(pin, 1); \
	writeWait;            \
	digitalWrite(pin, 1); \
	writeWait;            \
	digitalWrite(pin, 0); \
	writeWait;

#define write0(pin)       \
	digitalWrite(pin, 1); \
	writeWait;            \
	digitalWrite(pin, 0); \
	writeWait;            \
	digitalWrite(pin, 0); \
	writeWait;            \
	digitalWrite(pin, 0); \
	writeWait;

#define writeBit(data, pin) \
	if (data)               \
	{                       \
		write1(pin)         \
	}                       \
	else                    \
	{                       \
		write0(pin)         \
	}

#define frameValueSize 40
#define frameBuffer 10

int ctrl1Frames[frameBuffer][frameValueSize];
int ctrlr1BufferIndex = 0;
int ReadLength = 0;
//reset board to inital state.
void reset()
{
	while (1)
	{
		printf("RESETTING\n");
		//set up the datapins to use the GPIO.
		wiringPiSetupGpio();

		//set pin directions.
		pinMode(DataPin00, OUTPUT);
		pinMode(DataPin01, OUTPUT);
		pinMode(DataPin02, OUTPUT);
		pinMode(DataPin03, OUTPUT);
		pinMode(DataPin04, OUTPUT);
		pinMode(DataPin05, OUTPUT);
		pinMode(DataPin06, OUTPUT);
		pinMode(DataPin07, OUTPUT);
		pinMode(CtrlIn1, INPUT);
		pinMode(CtrlIn2, INPUT);
		pinMode(CtrlIn3, INPUT);
		pinMode(CtrlIn4, INPUT);
		pinMode(CtrlOut1, OUTPUT);
		pinMode(CtrlOut2, OUTPUT);
		pinMode(CtrlOut3, OUTPUT);
		pinMode(CtrlOut4, OUTPUT);
		pinMode(ResetPin, INPUT);
		pinMode(ClockPin, INPUT);
		pinMode(SendPin, OUTPUT);
		pinMode(ResendPin, OUTPUT);
		pinMode(GCPowerPin, OUTPUT);
		pinMode(GCResetPin, OUTPUT);
		digitalWrite(SendPin, 1);
		digitalWrite(ResendPin, 1);

		if (wait)
		{
			//output type
			outputOnDataPins(InputDeviceType);

			//pull Send Low
			digitalWrite(SendPin, 0);

			//wait for clock pulse
			while (digitalRead(ClockPin))
			{
			}

			//wait for end of clock pulse low.
			while (!digitalRead(ClockPin))
			{
			}

			//output version
			outputOnDataPins(InputDeviceVersion);

			//pull send high
			digitalWrite(SendPin, 1);

			//wait for clock to go low again.
			while (digitalRead(ClockPin))
			{
			}
		}
		//set pins back to input.
		pinMode(DataPin00, INPUT);
		pinMode(DataPin01, INPUT);
		pinMode(DataPin02, INPUT);
		pinMode(DataPin03, INPUT);
		pinMode(DataPin04, INPUT);
		pinMode(DataPin05, INPUT);
		pinMode(DataPin06, INPUT);
		pinMode(DataPin07, INPUT);

		//begin playback.
		playback();
	}
}

//output data to the datapins.
void outputOnDataPins(uint8_t num)
{
	digitalWrite(DataPin00, (num & (1 << 0)) >> 0);
	digitalWrite(DataPin01, (num & (1 << 1)) >> 1);
	digitalWrite(DataPin02, (num & (1 << 2)) >> 2);
	digitalWrite(DataPin03, (num & (1 << 3)) >> 3);
	digitalWrite(DataPin04, (num & (1 << 4)) >> 4);
	digitalWrite(DataPin05, (num & (1 << 5)) >> 5);
	digitalWrite(DataPin06, (num & (1 << 6)) >> 6);
	digitalWrite(DataPin07, (num & (1 << 7)) >> 7);
}

//read data from the datapins
uint8_t inputOnDataPins()
{
	return ((digitalRead(DataPin00) << 0) |
			(digitalRead(DataPin01) << 1) |
			(digitalRead(DataPin02) << 2) |
			(digitalRead(DataPin03) << 3) |
			(digitalRead(DataPin04) << 4) |
			(digitalRead(DataPin05) << 5) |
			(digitalRead(DataPin06) << 6) |
			(digitalRead(DataPin07) << 7));
}

//begin main playback loop to read data from the controller and output to the gamecube.
void playback()
{
	//temporary
	while (1)
	{
		//printf("frame playback\n");
		testReset
		getFrame();
		testReset
		outputFrame();
	}
}

//poll for the next frame. Every time, check for the reset pin.
void getFrame()
{
	if (!testControllerPlayback)
	{

		int frame[frameSize];
		//read in the freame, checking for reset every time.
		for (int i = 0; i < frameSize; i++)
		{
			//check for reset.
			testReset;

			while (!digitalRead(ClockPin) && digitalRead(ResetPin))
				;						  // wait for clock pin high (or reset).
			frame[i] = inputOnDataPins(); //read in data
			digitalWrite(SendPin, 1);
			//write send high
			while (digitalRead(ClockPin) && digitalRead(ResetPin))
			{
			}						  //wait for clock low (or reset)
			digitalWrite(SendPin, 0); //set send pin low.
		}
	}
	else
	{
		ctrl1Frames[0][0] = 0;
		ctrl1Frames[0][1] = 0;
		ctrl1Frames[0][2] = 0;
		ctrl1Frames[0][3] = 0;
		ctrl1Frames[0][4] = 0;
		ctrl1Frames[0][5] = 0;
		ctrl1Frames[0][6] = 0;
		ctrl1Frames[0][7] = 0;
		ctrl1Frames[0][8] = 1;
		ctrl1Frames[0][9] = 0;
		ctrl1Frames[0][10] = 0;
		ctrl1Frames[0][11] = 0;
		ctrl1Frames[0][12] = 0;
		ctrl1Frames[0][13] = 0;
		ctrl1Frames[0][14] = 0;
		ctrl1Frames[0][15] = 0;
		ctrl1Frames[0][16] = 0;
		ctrl1Frames[0][17] = 0;
		ctrl1Frames[0][18] = 0;
		ctrl1Frames[0][19] = 0;
		ctrl1Frames[0][20] = 0;
		ctrl1Frames[0][21] = 0;
		ctrl1Frames[0][22] = 0;
		ctrl1Frames[0][23] = 0;
		ctrl1Frames[0][24] = 1;
		ctrl1Frames[0][25] = 0;
		ctrl1Frames[0][26] = 0;
		ctrl1Frames[0][27] = 0;
		ctrl1Frames[0][28] = 0;
		ctrl1Frames[0][29] = 0;
		ctrl1Frames[0][30] = 0;
		ctrl1Frames[0][31] = 0;
		ctrl1Frames[0][32] = 1;
		ctrl1Frames[0][33] = 0;
		ctrl1Frames[0][34] = 0;
		ctrl1Frames[0][35] = 0;
		ctrl1Frames[0][36] = 0;
		ctrl1Frames[0][37] = 0;
		ctrl1Frames[0][38] = 0;
		ctrl1Frames[0][39] = 0;
		ctrl1Frames[0][40] = 1;
		ctrl1Frames[0][41] = 0;
		ctrl1Frames[0][42] = 0;
		ctrl1Frames[0][43] = 0;
		ctrl1Frames[0][44] = 0;
		ctrl1Frames[0][45] = 0;
		ctrl1Frames[0][46] = 0;
		ctrl1Frames[0][47] = 0;
		ctrl1Frames[0][48] = 0;
		ctrl1Frames[0][49] = 0;
		ctrl1Frames[0][50] = 0;
		ctrl1Frames[0][51] = 0;
		ctrl1Frames[0][52] = 0;
		ctrl1Frames[0][53] = 0;
		ctrl1Frames[0][54] = 0;
		ctrl1Frames[0][55] = 0;
		ctrl1Frames[0][56] = 0;
		ctrl1Frames[0][57] = 0;
		ctrl1Frames[0][58] = 0;
		ctrl1Frames[0][59] = 0;
		ctrl1Frames[0][60] = 0;
		ctrl1Frames[0][61] = 0;
		ctrl1Frames[0][62] = 0;
		ctrl1Frames[0][63] = 0;
	}
}

int first = 1;
int ID_Data[24] = {
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};
//poll for the controller data from the gamecube that signifies "next frame", than begin the
void outputFrame()
{
	uint16_t i = readCommand();
	switch (i)
	{
	case CMD_ID: //report the controller id. In this case, if the controller has a rumble motor or not.
		outputData(24, ID_Data, ((ReadLength / 4)));
		printf("CMD_ID\n");
		break;
	case CTRL_RESET: //reset was detected in bit read. Reset the playback.
		return;
		printf("CTRL_RESET\n");
	case CMD_STATUS:
		//outputData(64, ctrl1Frames[ctrlr1BufferIndex++ % frameBuffer], ((5 * ReadLength) / 4));
		outputData(64, ctrl1Frames[0], ((ReadLength / 4)));
		printf("CMD_STATE\n");
		break;
	case CMD_ORIGIN:
		printf("CMD_ORIGIN\n");
		break;
	case CMD_RECELEBRATE: //do nothing.
		printf("CMD_RECAL\n");
		break;
	case CMD_STATUS_LONG:
		printf("CMD_LONG\n");
		break;
	case CMD_RESET: //reset the "motor"
		printf("CMD_RESET\n");
		break;
	default:
		printf("DEFAULT:%x\n", i);
	}
}

//outputData handles the physical output of the bits to the pins themselves.
//due to the restrictions of the timing, loops is the number of times that the digital read is
//called before the known timing is finished.
//bits is the number of bits that is to be output. 0 outputs only the trailing one bit.
//data contains the data that is to be output.
void outputData(int bits, int *data, int loops)
{
	//for the number of bits to be output
	//if (digitalRead(CtrlIn1))
	//{
	//	printf("UP\n");
	//}
	for (int i = 0; i < bits; i++)
	{
		writeBit(!data[i], CtrlIn1)
	}
	writeBit(0, CtrlIn1)
}

//readCommand reads in the output command from the gamecube,
//The data and timing is used to prepare the output for proper response.
//The return value is the last 8 bits excluding the stop bit of the command.
//readCommand expects the data line to be high when called.
int readCommand()
{
	//printf("Reading command\n");
	//wait for line level to be low, testing reset along the way.
	//if reset, return 1 (REPLAY reset)
	while (!digitalRead(CtrlIn1))
	{
		//read the reset pin. If reset, rerturn the controller reset value.
		if (!digitalRead(ResetPin))
		{
			return CTRL_RESET;
		}
	}
	uint32_t data = 7;
	int numBits = 0;
	while (1)
	{
		switch (readBit())
		{
		case 0: //a zero has been read in.
			data = data << 1;
			numBits++;
			break;
		case 1: //a 1 has been read in from the data.
			data = (data << 1) + 1;
			numBits++;
			break;
		case 2: //Time Length too long. Time to return the final value.
			//printf("data: %d\nnumBits: %d\n",data,numBits);
			return (data >> (numBits - 8)) & 0xff;
			break;
		}
	}
	//This value should be impossible. Return reset because an error has occured.
	return CTRL_RESET;
}

//readBit reads a single bit from the input dataline.

int readBit()
{
	uint32_t cycles1 = 1; //set to 1 to account for extra cycles from function calls etc.
	uint32_t cycles2 = 1;
	//printf("readingBit\n");
	while (1)
	{
		cycles1++;
		if (!digitalRead(CtrlIn1))
		{
			break;
		}
	}

	while (1)
	{
		cycles2++;
		if (digitalRead(CtrlIn1))
		{
			break;
		}
		//the read has lasted longer than the total length of one bit. It is time to return a response.
		if (((cycles2 > (ReadLength)) && (cycles2 != 1) && (cycles1 != 1) && (ReadLength != 0)) || cycles2 > 200)
		{ //printf("1:%d\n2:%d\n", cycles1, cycles2);
			return 2;
		}
	}

	//set ReadLength so that the
	ReadLength = (cycles1 + cycles2);

	if (cycles1 > cycles2)
	{
		//printf("0");
		return 0;
	}
	//printf("1");
	return 1;
}

void testOutput()
{
	wiringPiSetupGpio();
	pinMode(CtrlOut1, OUTPUT);
	while (1)
	{

		for (int i = 0; i <= noopCount; i++)
		{
			asm("nop");
		}
		digitalWrite(CtrlOut1, 1);

		for (int i = 0; i <= noopCount; i++)
		{
			asm("nop");
		}
		digitalWrite(CtrlOut1, 0);
	}
}

#define GCNoopCount 206
#define readWait                           \
	for (int i = 0; i <= GCNoopCount; i++) \
	{                                      \
		asm("nop");                        \
	}

//readCommand2 itterates through listening on the controller input pin,
//reset is watched the entire time that the command is waited for.
//if the reset is ever triggered, a specific reset signal is returned.
//otherwise, the system waits for the controller pin to lower to ground.
int readCommand2()
{
	//wait for line level to be low, testing reset along the way.
	//if reset, return 1 (REPLAY reset)
	while (!digitalRead(CtrlIn1))
	{
		//read the reset pin. If reset, rerturn the controller reset value.
		if (!digitalRead(ResetPin))
		{
			return CTRL_RESET;
		}
	}

	//GCNoopCount 6.25 us~~

	//once the controller line pin is low, start the for loop.
	uint64_t inputValue = 0;

	int risingEdge = 0;
	for (int i = 0; i < GCNoopCount; i++)
	{
		//once the pin is high, record the value of the
		if (digitalRead(CtrlIn1))
		{
			if (risingEdge == 0)
			{
				risingEdge = 1;
				//if I is more than half way, it is a 0.
				if (i > (GCNoopCount / 2))
				{
					inputValue = (inputValue << 1) + 0;
				}
				else
				{
					inputValue = (inputValue << 1) + 1;
				}
			}
			else
			{
				asm("nop");
				asm("nop"); // /2
				asm("nop"); // >

				asm("nop"); // <<
				asm("nop"); // +

				//equal delay to above
			}
		}
		else
		{
			if (risingEdge == 1)
			{
				//value fell. Reset to beginning
				risingEdge = 0;
				i = -1;
			}
			else
			{
				asm("nop");
				asm("nop");

				asm("nop"); // /2
				asm("nop"); // >

				asm("nop"); // <<
				asm("nop"); // +
			}
		}
	}
	return inputValue;
}

int testTiming()
{
	printf("RESETTING\n");
	//set up the datapins to use the GPIO.
	wiringPiSetupGpio();

	//set pin directions.
	pinMode(CtrlOut1, OUTPUT);
	pinMode(CtrlIn2, INPUT);

	int i = 0;
	while (1)
	{
		i ^= 1;
		digitalWrite(CtrlOut1, i);
		for (int i = 0; i < GCNoopCount; i++)
		{

			if (digitalRead(CtrlIn2))
			{
				asm("nop");
				asm("nop");

				asm("nop"); // /2
				asm("nop"); // >

				asm("nop"); // <<
				asm("nop"); // +
				asm("nop");
			}
			else
			{
				asm("nop");
				asm("nop");

				asm("nop"); // /2
				asm("nop"); // >

				asm("nop"); // <<
				asm("nop"); // +
				asm("nop");
			}
		}
	}
}