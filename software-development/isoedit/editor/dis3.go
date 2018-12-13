package editor

import (
	"strconv"
)

func dis3Start(num uint32, comm command) (uint32, command) {
	//Grab bits from 6-20, 11-15 adn 16-31 and place them in the command
	//Add twl to the command name

	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	TO := getBits(6, 10, num)
	A := getBits(11, 15, num)
	SIMM := getBits(16, 31, num)
	c := command{
		cmdName:   "TWI",
		cmdString: "TWI\t" + strconv.Itoa(TO) + ", R" + strconv.Itoa(A) + ", " + strconv.Itoa(SIMM),
		cmdSimple: []int{3, TO, A, SIMM},
		asBytes:   num,
	}

	return num, c
}
