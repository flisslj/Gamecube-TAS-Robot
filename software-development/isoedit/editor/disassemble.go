package editor

import (
	"fmt"
	"os"
)

func disassembleInt(cmd uint32) command {

	switch getBits(0, 5, cmd) {
	case 3:
		dis3Start(cmd, command{})
	case 4:
	default:
		fmt.Println("Command ", cmd, " Does not exist.")
		os.Exit(1)
	}
	return command{}
}

func assembleCommand(cmd command) uint32 {
	switch getBits(0, 5, cmd.asBytes) {
	case 3:
		dis3Start(0, cmd)
	case 4:
	default:
		fmt.Println("Command ", cmd, " Does not exist.")
		os.Exit(1)
	}

	return 0
}

func getBits(low, high uint32, command uint32) uint32 {

	width := high - low + 1
	// shifted over.
	base := command >> low

	mask := uint32((1 << width) - 1)

	//clear upto the high bits.

	return base & mask
}
