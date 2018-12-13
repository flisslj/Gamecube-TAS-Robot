package editor

import "strconv"

func dis11Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 10) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	D := getBits(6, 8, num)
	L := getBits(10, 10, num)
	A := getBits(11, 15, num)
	SIMM := getBits(16, 31, num)
	c := command{
		cmdName:   "CMPI",
		cmdString: "CMPI\tCRF" + strconv.Itoa(D) + ", " + strconv.Itoa(L) + ", R" + strconv.Itoa(A) + ", " + strconv.Itoa(SIMM),
		cmdSimple: []int{11, D, A, SIMM},
		asBytes:   num,
	}

	return num, c
}
