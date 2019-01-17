#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

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
        testReset
        getFrame();
        testReset
        outputFrame();
    }
}

//poll for the next frame. Every time, check for the reset pin.
void getFrame()
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
            ;                     //wait for clock low (or reset)
        digitalWrite(SendPin, 0); //set send pin low.
    }
}

//poll for the controller data from the gamecube that signifies "next frame", than begin the
void outputFrame()
{
    //read for controller input 1. if there isint one, test for reset. if reset, return.
    while (digitalRead(CtrlIn1))
    {
        testReset
    }

    int startSequence[96] = {
        0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, // 0 1 0 0
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, // 0 0 0 0
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, // 0 0 0 0
        0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, // 0 0 1 1
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, // 0 0 0 0
        0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1  // 0 0 1 0
    };

    int tracker = 0; //value used to track the differences between the input and the expected.

    //read every us~ and store that data.
    for (int i = 0; i < 96; i++)
    {
        if (startSequence[i] != digitalRead(CtrlIn1))
        {
            tracker++;
        }
        //read controller in.
        asm("nop"); // the number of nops may need to be increased or decreased to properly match the timings of things.
    }

    //arbitrary 10 % difference. if there are more than 10 errors, return.
    if (tracker >= 10)
    {

        return;
    }

    for (int i = 0; i < 64; i++)
    { //output the values read in.
        digitalWrite(CtrlOut1, 0);
        outputDelay;
        digitalWrite(CtrlOut1, ctrl1Frames[0][i]); //for now, no circle buffer
        outputDelay;
        digitalWrite(CtrlOut1, ctrl1Frames[0][i]); // for now, no circle buffer.
        outputDelay;
        digitalWrite(CtrlOut1, 1);
        outputDelay;
    }
}

void testOutput()
{

    for (int i = 0; i < 64; i++)
    { //output the values read in.
        ctrl1Frames[0][i] = 1;
    }

    while (1)
    {
        for (int i = 0; i < 64; i++)
        { //output the values read in.
            digitalWrite(CtrlOut1, 0);
            outputDelay;
            digitalWrite(CtrlOut1, ctrl1Frames[0][i]); //for now, no circle buffer
            outputDelay;
            digitalWrite(CtrlOut1, ctrl1Frames[0][i]); // for now, no circle buffer.
            outputDelay;
            digitalWrite(CtrlOut1, 1);
            outputDelay;
        }
        sleep(1);
        printf("Sending The output. \n");
    }
}