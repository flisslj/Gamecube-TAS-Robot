# ISO Editor

The goal of this specific software sub-project is to take in a Gamecube game .ISO file, and modify it to produce the specific memory dump.


## Process

1. Open ISO
2. Pull main file from ISO
3. Edit file
   1. Disassemble binary file
   2. Locate Frame Loop
   3. Insert Necessary Memory Dump Code
   4. Reassemble binary file
4. Reload file into new ISO

## Usage

```
isoedit [options] <FIle Location> [Output File Location] 
```

- `-f` The frame that the memory dump will trigger on. 
   - If `-inf` is set, the number of frames between memory dumps. 
   - Default value is 600 (10 seconds)
- `-c` Sets the value for the game clock to return when checked. 
   - Recommended Default is 0.
   - Game clock unaltered if unset.
- `-inf` If the memory dumps should be every m frames. 
   - Default value is false. 
- `-iso` The input file location string. (Required)
- `-out` The output file location String. (Required)


Written in golang(go)

