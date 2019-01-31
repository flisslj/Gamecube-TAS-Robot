package editor

func dis17Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	CHECK := getBits(6, 31, num)
	c := command{
		cmdName:   "SC",
		cmdString: "SC\t",
		cmdSimple: []int{17, CHECK},
		asBytes:   num,
	}

	return num, c
}
