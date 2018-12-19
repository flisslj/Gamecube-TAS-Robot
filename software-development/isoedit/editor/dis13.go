package editor

import "strconv"

func dis13Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	SIMM := getBits(16, 31, num)
	c := command{
		cmdName:   "ADDIC.",
		cmdString: "ADDIC.\tR" + strconv.Itoa(D) + ", R" + strconv.Itoa(A) + ", " + strconv.Itoa(SIMM),
		cmdSimple: []int{13, D, A, SIMM},
		asBytes:   num,
	}

	return num, c
}
