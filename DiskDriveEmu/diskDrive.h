#ifndef DISKDRIVE_H
#define DISKDRIVE_H

//here lie the definitions of the pins
//tread carefully, lest you get torn asunder
//or something

//AUDIO PINS
//AISLR is gc-controlled, and dictates whether you give left or right audio data
//SCLK is the clock for the data, while SD is the data being output by the drive
//I2S system interface
#define DD_AISLR
#define DD_AISD
#define DD_AISCLK

//DATA COMMUNICATION PINS
//DID is an array of parallel pins for communication of byte-by-byte
//DIDIR defines the direction data is going - 0 if GC has it, 1 if DD has it
//STRB, or "strobes" are the clocks controlled by the devices
// H for host (GC), D for drive
#define DIHSTRB
#define DIDSTRB
#define DIDIR
#define DID0
#define DID1
#define DID2
#define DID3
#define DID4
#define DID5
#define DID6
#define DID7

//INTERRUPT PINS
//DICOVER is the easiest - it tells whether is cover is open or not
//DIRSTB is the "reset" pin for the disk drive
//DIERRB is an "Error" from the gc, which can be determined via DID (i think?)
#define DIRSTB
#define DIERRB
#define DICOVER

//UNKNOWN PINS
//it's unclear what non-debugging purpose, if any, these serve
//they are connected "just in case"
#define DIBRK
#define MONI
#define MONOUT




//COMMAND LIST
//these are the commands the GC uses to talk to the disk drive

//identify
//WIP
//TODO
#define CMD_IDENTIFY 0x12000000

//read sector
//reads the sector defined in the latter half of the command
#define CMD_RDSECTOR 0xa8000000

//precache
//probably ignoreable on our system lmao but basically
//asks the disk to find something ahead of time to cache
#define CMD_SEEK 0xab000000

//read status
//returns some status, not sure what
//TODO
#define CMD_RDSTATUS 0xe0000000

//audio stream
//lets the disk drive know its time to start streaming audio
#define CMD_AUDIOSTRM 0xe1000000

//request audio status
//returns some nebulous status on the audio stuff
//TODO
#define CMD_AUDIOSTATUS 0xe2000000

//stop the disk motor
//laughably unuseable i think
#define CMD_MOTORSTOP 0xe3000000

//audio buffer config
//configures the audio buffer
//TODO
#define CMD_AUDIOBUFFCONF 0xe4000000

//debug command
//probably not used in practice
#define CMD_DEBUGCMD 0xfe000000

//debug enable
//similar to above
#define CMD_DEBUGEN 0xff000000

#endif