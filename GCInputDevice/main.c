#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>

void main()
{
    printf("Hello World\n");
    reset();
}

#define InputDeviceType 1
#define InputDeviceVersion 1
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

//reset board to inital state.
void reset()
{
    while (true)
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
        digitalWrite(SendPin, 1);
        digitalWrite(ResendPin, 1);

        //output type
        outputOnDataPins(InputDeviceType);

        //pull Send Low
        digitalWrite(SendPin, 0);

        //wait for clock pulse
        while (digitalRead(clockPin))
        {
        }

        //wait for end of clock pulse low.
        while (!digitalRead(clockPin))
        {
        }

        //output version
        outputOnDataPins(InputDeviceVersion);

        //pull send high
        digitalWrite(SendPin, 1);

        //wait for clock to go low again.
        while (digitalRead(clockPin))
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
void playBack()
{

    //temporary 
    while (digitalRead(ResetPin)){

    }
}