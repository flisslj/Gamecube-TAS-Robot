package editor

import "strconv"

func dis51Start(num uint32, comm command) (uint32, command) {
	//Format needs to be discussed for cmd String
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	d := getBits(16, 31, num)
	c := command{
		cmdName:   "LFDU",
		cmdString: "LFDU\tR" + strconv.Itoa(D) + ", " + strconv.Itoa(d) + " (R" + strconv.Itoa(A) + ")",
		cmdSimple: []int{51, D, A, d},
		asBytes:   num,
	}

	return num, c
}

//ended on ori command
