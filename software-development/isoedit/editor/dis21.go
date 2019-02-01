package editor

import "strconv"

func dis21Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	NAME := ""
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	SH := getBits(16, 20, num)
	MB := getBits(21, 25, num)
	ME := getBits(26, 30, num)
	RC := getBits(31, 31, num)
	if RC == 0 {
		NAME = "RLWINM"
	} else {
		NAME = "RLWINM."
	}
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(S) + ", R" + strconv.Itoa(A) + ", " + strconv.Itoa(SH) + ", " + strconv.Itoa(MB) + ", " + strconv.Itoa(SH) + ", " + strconv.Itoa(ME),
		cmdSimple: []int{21, S, A, SH, MB, ME, RC},
		asBytes:   num,
	}

	return num, c
}
