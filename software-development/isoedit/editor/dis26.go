package editor

import "strconv"

func dis26Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}

	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	UIMM := getBits(16, 31, num)

	c := command{
		cmdName:   "XORI",
		cmdString: "XORI\tR" + strconv.Itoa(S) + ", R" + strconv.Itoa(A) + ", " + strconv.Itoa(UIMM),
		cmdSimple: []int{26, S, A, UIMM},
		asBytes:   num,
	}

	return num, c
}

//ended on ori command
