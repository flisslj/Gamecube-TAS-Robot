#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define testControllerPlayback 1

void reset();
void main();
void outputOnDataPins(uint8_t num);
uint8_t inputOnDataPins();
void playback();
void getFrame();
void outputFrame();
void testOutput();

void main()
{
    printf("Hello World\n");
    reset();
    //testOutput();

    if (testControllerPlayback)
    {
        while (1)
        {
            playback();
        }
    }
}

#define InputDeviceType 1
#define InputDeviceVersion 1
#define wait 0
#define DataPin00 2   // physical pins 3
#define DataPin01 3   // physical pins 5
#define DataPin02 4   // physical pins 7
#define DataPin03 5   // physical pins 29
#define DataPin04 6   // physical pins 31
#define DataPin05 7   // physical pins 26
#define DataPin06 8   // physical pins 24
#define DataPin07 9   // physical pins 21
#define CtrlIn1 10    // physical pins 19
#define CtrlIn2 11    // physical pins 23
#define CtrlIn3 12    // physical pins 32
#define CtrlIn4 13    // physical pins 33
#define CtrlOut1 14   // physical pins 8
#define CtrlOut2 15   // physical pins 10
#define CtrlOut3 16   // physical pins 36
#define CtrlOut4 17   // physical pins 11
#define ResetPin 18   // physical pins 12
#define ClockPin 19   // physical pins 35
#define SendPin 20    // physical pins 38
#define ResendPin 21  // physical pins 40
#define GCResetPin 22 // Physical pins 15
#define GCPowerPin 23 // physical pins 16

#define frameSize 40

#define testReset               \
    if (!digitalRead(ResetPin)) \
    {                           \
        return;                 \
    };
#define outputDelay \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");     \
    asm("nop");

#define frameValueSize 40
#define frameBuffer 10
int ctrl1Frames[frameBuffer][frameValueSize];
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
    return (digitalRead(DataPin00) << 0) |
           (digitalRead(DataPin01) << 1) |
           (digitalRead(DataPin02) << 2) |
           (digitalRead(DataPin03) << 3) |
           (digitalRead(DataPin04) << 4) |
           (digitalRead(DataPin05) << 5) |
           (digitalRead(DataPin06) << 6) |
           (digitalRead(DataPin07) << 7);
}

//begin main playback loop to read data from the controller and output to the gamecube.
void playback()
{
    //temporary
    while (1)
    {
        printf("frame playback\n");
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
                ;                         // wait for clock pin high (or reset).
            frame[i] = inputOnDataPins(); //read in data
            digitalWrite(SendPin, 1);
            //write send high
            while (digitalRead(ClockPin) && digitalRead(ResetPin))
            {
            }                         //wait for clock low (or reset)
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
//poll for the controller data from the gamecube that signifies "next frame", than begin the
void outputFrame()
{
    printf("waiting for pull low\n");
    //read for controller input 1. if there isint one, test for reset. if reset, return.
    while (digitalRead(CtrlIn1))
    {
        testReset
    }
    /*
    int startSequence[24] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0};

    int tracker = 0; //value used to track the differences between the input and the expected.

    //read every us~ and store that data.
    for (int i = 0; i < 24; i++)
    {
        delayMicroseconds(2);
        if (startSequence[i] != digitalRead(CtrlIn1))
        {
            tracker++;
        }

        while (digitalRead(CtrlIn1))
        {
            testReset
        }
        //read controller in.
    }

    //arbitrary 10 % difference. if there are more than 10 errors, return.
    if (tracker >= 4)
    {

        return;
    }
    */

    delayMicroseconds(36);
    if (!first)
    {
        delayMicroseconds(62);
    }
    else
    {
        first = 0;
    }

    //printf("outputting\n");
    for (int i = 0; i < 64; i++)
    { //output the values read in.
        digitalWrite(CtrlOut1, 0);
        delayMicroseconds(1);
        digitalWrite(CtrlOut1, ctrl1Frames[0][i]); //for now, no circle buffer
        delayMicroseconds(1);
        digitalWrite(CtrlOut1, ctrl1Frames[0][i]); // for now, no circle buffer.
        delayMicroseconds(1);
        digitalWrite(CtrlOut1, 1);
        delayMicroseconds(1);
    }
    digitalWrite(CtrlOut1, 0);
    delayMicroseconds(1);
    digitalWrite(CtrlOut1, 1); //for now, no circle buffer
    printf("done outputting.");
}

void testOutput()
{
    wiringPiSetupGpio();
    pinMode(CtrlOut1, OUTPUT);
    for (int i = 0; i < 64; i++)
    { //output the values read in.
        ctrl1Frames[0][i] = i % 2;
    }

    while (1)
    {
        for (int i = 0; i < 64; i++)
        { //output the values read in.
            digitalWrite(CtrlOut1, 0);
            delayMicroseconds(1);
            digitalWrite(CtrlOut1, ctrl1Frames[0][i]); //for now, no circle buffer
            delayMicroseconds(1);
            digitalWrite(CtrlOut1, ctrl1Frames[0][i]); // for now, no circle buffer.
            delayMicroseconds(1);
            digitalWrite(CtrlOut1, 1);
            delayMicroseconds(1);
        }
        sleep(1);
        printf("Sending The output. \n");
    }
}
