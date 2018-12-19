package editor

import "strconv"

func dis39Start(num uint32, comm command) (uint32, command) {
	//Format needs to be discussed for cmd String
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	d := getBits(16, 31, num)
	c := command{
		cmdName:   "STBU",
		cmdString: "STBU\tR" + strconv.Itoa(S) + ", " + strconv.Itoa(d) + " (R" + strconv.Itoa(A) + ")",
		cmdSimple: []int{39, S, A, d},
		asBytes:   num,
	}

	return num, c
}

//ended on ori command
