package editor

import "strconv"

func dis16Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	NAME := ""
	BO := getBits(6, 10, num)
	BI := getBits(11, 15, num)
	BD := getBits(16, 29, num)
	TYPE := getBits(30, 31, num)
	if TYPE == 0 {
		NAME = "BC"
	} else if TYPE == 1 {
		NAME = "BCL"
	} else if TYPE == 2 {
		NAME = "BCA"
	} else {
		NAME = "BCLA"
	}
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\t" + strconv.Itoa(BO) + ", " + strconv.Itoa(BI) + ", " + strconv.Itoa(BD),
		cmdSimple: []int{16, BO, BI, BD, TYPE},
		asBytes:   num,
	}

	return num, c
}
