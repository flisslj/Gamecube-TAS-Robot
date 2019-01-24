package editor

import "strconv"

func dis18Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	NAME := ""
	LI := getBits(6, 29, num)
	TYPE := getBits(30, 31, num)
	if TYPE == 0 {
		NAME = "B"
	} else if TYPE == 1 {
		NAME = "BL"
	} else if TYPE == 2 {
		NAME = "BA"
	} else {
		NAME = "BLA"
	}
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\t" + strconv.Itoa(LI),
		cmdSimple: []int{18, LI, TYPE},
		asBytes:   num,
	}

	return num, c
}
