package editor

import "strconv"

func dis61Start(num uint32, comm command) (uint32, command) {
	//Format needs to be discussed for cmd String
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	W := getBits(16, 16, num)
	I := getBits(17, 19, num)
	d := getBits(20, 31, num)
	c := command{
		cmdName:   "PSQ_STU",
		cmdString: "PSQ_STU\tR" + strconv.Itoa(S) + ", " + strconv.Itoa(d) + " (R" + strconv.Itoa(A) + ")," + strconv.Itoa(W) + "," + strconv.Itoa(I),
		cmdSimple: []int{61, S, A, W, I, d},
		asBytes:   num,
	}

	return num, c
}

//ended on ori command
