package editor

func dis63Start(num uint32, comm command) (uint32, command) {
	//Format needs to be discussed for cmd String
	t := 0
	if num == 0 {
		t = getBits(26, 30, comm.asBytes)

	} else {
		t = getBits(26, 30, num)

	}

	switch t {
	case 0:
		return dis63StartFCMP(num, comm)
	case 6:
		return dis63StartMTFS(num, comm)
	case 8:
		return dis63StartFunc(num, comm)
	case 7:
		return dis63StartMFFS(num, comm)
	case 12:
		return dis63StartFRSP(num, comm)
	case 14:
		return dis63StartFCTIW(num, comm)
	case 15:
		return dis63StartFCTIWZ(num, comm)
	case 18:
		return dis63StartFDIV(num, comm)
	case 20:
		return dis63StartFSUB(num, comm)
	case 21:
		return dis63StartFADD(num, comm)
	case 23:
		return dis63StartFSEL(num, comm)
	case 25:
		return dis63StartFMUL(num, comm)
	case 26:
		return dis63StartFRSQRTE(num, comm)
	case 28:
		return dis63StartFMSUB(num, comm)
	case 29:
		return dis63StartFMADD(num, comm)
	case 30:
		return dis63StartFNMSUB(num, comm)
	case 31:
		return dis63StartFNMADD(num, comm)
	}
	return num, comm
}

func dis63StartFCMP(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis63StartMTFS(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFunc(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartMFFS(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFRSP(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFCTIW(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFCTIWZ(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFDIV(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFSUB(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFADD(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFSEL(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFMUL(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFRSQRTE(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFMSUB(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFMADD(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFNMSUB(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis63StartFNMADD(num uint32, comm command) (uint32, command) {
	return num, command{}
}

//ended on ori command
