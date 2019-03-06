package editor

import "strconv"

func dis31Start(num uint32, comm command) (uint32, command) {
	//12/13/18 Put a "default format" Needs to be discussed on how this should be done due to somewhat complex tings
	t := 0
	if num == 0 {
		t = getBits(21, 30, comm.asBytes)

	} else {
		t = getBits(21, 30, num)

	}

	switch t {
	case 0:
		return dis31StartCMP(num, comm)
	case 4:
		return dis31StartTW(num, comm)
	case 8:
		return dis31StartSUBFCX(num, comm)
	case 520:
		return dis31StartSUBFCX(num, comm)
	case 10:
		return dis31StartADDCX(num, comm)
	case 522:
		return dis31StartADDCX(num, comm)
	case 11:
		return dis31StartMULHWUX(num, comm)
	case 19:
		return dis31StartMFCR(num, comm)
	case 20:
		return dis31StartLWARX(num, comm)
	case 23:
		return dis31StartLWZX(num, comm)
	case 24:
		return dis31StartSLWX(num, comm)
	case 26:
		return dis31StartCNTLZWX(num, comm)
	case 28:
		return dis31StartANDX(num, comm)
	case 32:
		return dis31StartCMPL(num, comm)
	case 40:
		return dis31StartSUBFX(num, comm)
	case 552:
		return dis31StartSUBFX(num, comm)
	case 54:
		return dis31StartDCBST(num, comm)
	case 55:
		return dis31StartLWZUX(num, comm)
	case 60:
		return dis31StartANDCX(num, comm)
	case 75:
		return dis31StartMULHWX(num, comm)
	case 83:
		return dis31StartMFMSR(num, comm)
	case 86:
		return dis31StartDCBF(num, comm)
	case 87:
		return dis31StartLBZX(num, comm)
	case 104:
		return dis31StartNEGX(num, comm)
	case 616:
		return dis31StartNEGX(num, comm)
	case 119:
		return dis31StartLBZUX(num, comm)
	case 124:
		return dis31StartNORX(num, comm)
	case 136:
		return dis31StartSUBFEX(num, comm)
	case 648:
		return dis31StartSUBFEX(num, comm)
	case 138:
		return dis31StartADDEX(num, comm)
	case 650:
		return dis31StartADDEX(num, comm)
	case 144:
		return dis31StartMTCRF(num, comm)
	case 146:
		return dis31StartMTMSR(num, comm)
	case 150:
		return dis31StartSTWCXd(num, comm)
	case 151:
		return dis31StartSTWX(num, comm)
	case 183:
		return dis31StartSTWUX(num, comm)
	case 200:
		return dis31StartSUBFZEX(num, comm)
	case 712:
		return dis31StartSUBFZEX(num, comm)
	case 202:
		return dis31StartADDZEX(num, comm)
	case 714:
		return dis31StartADDZEX(num, comm)
	case 210:
		return dis31StartMTSR(num, comm)
	case 215:
		return dis31StartSTBX(num, comm)
	case 232:
		return dis31StartSUBFMEX(num, comm)
	case 744:
		return dis31StartSUBFMEX(num, comm)
	case 234:
		return dis31StartADDMEX(num, comm)
	case 746:
		return dis31StartADDMEX(num, comm)
	case 235:
		return dis31StartMULLWX(num, comm)
	case 747:
		return dis31StartMULLWX(num, comm)
	case 242:
		return dis31StartMTSRIN(num, comm)
	case 246:
		return dis31StartDCBTST(num, comm)
	case 247:
		return dis31StartSTBUX(num, comm)
	case 266:
		return dis31StartADDX(num, comm)
	case 778:
		return dis31StartADDX(num, comm)
	case 278:
		return dis31StartDCBT(num, comm)
	case 279:
		return dis31StartLHZX(num, comm)
	case 284:
		return dis31StartEQVX(num, comm)
	case 306:
		return dis31StartTLBIE(num, comm)
	case 310:
		return dis31StartECIWX(num, comm)
	case 311:
		return dis31StartLHZUX(num, comm)
	case 316:
		return dis31StartXORX(num, comm)
	case 339:
		return dis31StartMFSPR(num, comm)
	case 343:
		return dis31StartLHAX(num, comm)
	case 371:
		return dis31StartMFTB(num, comm)
	case 375:
		return dis31StartLHAUX(num, comm)
	case 407:
		return dis31StartSTHX(num, comm)
	case 412:
		return dis31StartORCX(num, comm)
	case 438:
		return dis31StartECOWX(num, comm)
	case 439:
		return dis31StartSTHUX(num, comm)
	case 444:
		return dis31StartORX(num, comm)
	case 459:
		return dis31StartDIVWUX(num, comm)
	case 971:
		return dis31StartDIVWUX(num, comm)
	case 467:
		return dis31StartMTSPR(num, comm)
	case 470:
		return dis31StartDCBI(num, comm)
	case 476:
		return dis31StartNANDX(num, comm)
	case 491:
		return dis31StartDIVWX(num, comm)
	case 1003:
		return dis31StartDIVWX(num, comm)
	case 512:
		return dis31StartMCRXR(num, comm)
	case 533:
		return dis31StartLSWX(num, comm)
	case 534:
		return dis31StartLWBRX(num, comm)
	case 535:
		return dis31StartLFSX(num, comm)
	case 536:
		return dis31StartSRWX(num, comm)
	case 566:
		return dis31StartTLBSYNC(num, comm)
	case 567:
		return dis31StartLFSUX(num, comm)
	case 595:
		return dis31StartMFSR(num, comm)
	case 597:
		return dis31StartLSWI(num, comm)
	case 598:
		return dis31StartSYNC(num, comm)
	case 599:
		return dis31StartLFDX(num, comm)
	case 631:
		return dis31StartLFDUX(num, comm)
	case 659:
		return dis31StartMFSRIN(num, comm)
	case 661:
		return dis31StartSTSWX(num, comm)
	case 662:
		return dis31StartSTWBRX(num, comm)
	case 663:
		return dis31StartSTFSX(num, comm)
	case 695:
		return dis31StartSTFSUX(num, comm)
	case 725:
		return dis31StartSTSWI(num, comm)
	case 727:
		return dis31StartSTFDX(num, comm)
	case 759:
		return dis31StartSTFDUX(num, comm)
	case 790:
		return dis31StartLHBRX(num, comm)
	case 792:
		return dis31StartSRAWX(num, comm)
	case 824:
		return dis31StartSRAWIX(num, comm)
	case 854:
		return dis31StartEIEIO(num, comm)
	case 918:
		return dis31StartSTHBRX(num, comm)
	case 922:
		return dis31StartEXTSHX(num, comm)
	case 954:
		return dis31StartEXTSBX(num, comm)
	case 982:
		return dis31StartICBI(num, comm)
	case 983:
		return dis31StartSTFIWX(num, comm)
	case 1014:
		return dis31StartDCBZ(num, comm)
	}

	return num, command{}
}

func dis31StartCMP(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 10) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	D := getBits(6, 8, num)
	L := getBits(10, 10, num)
	A := getBits(11, 15, num)
	SIMM := getBits(16, 31, num)
	c := command{
		cmdName:   "CMP",
		cmdString: "CMP\tCRF" + strconv.Itoa(D) + ", " + strconv.Itoa(L) + ", R" + strconv.Itoa(A) + ", " + strconv.Itoa(SIMM),
		cmdSimple: []int{31, D, A, SIMM},
		asBytes:   num,
	}

	return num, c
}
func dis31StartTW(num uint32, comm command) (uint32, command) {
	//Grab bits from 6-20, 11-15 adn 16-31 and place them in the command
	//Add twl to the command name

	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	TO := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "TW",
		cmdString: "TW\t" + strconv.Itoa(TO) + ", R" + strconv.Itoa(A) + ", R" + strconv.Itoa(B),
		cmdSimple: []int{31 TO, A, B, getBits(21, 31)},
		asBytes:   num,
	}

	return num, c
}
func dis31StartSUBFCX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "SUBFC"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "SUBFC."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "SUBFCO"
	} else {
		NAME = "SUBFCO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartADDCX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "ADDC"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "ADDC."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "ADDCO"
	} else {
		NAME = "ADDCO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMULHWUX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "MULHWU"
	} else {
		NAME = "MULHWU."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMFCR(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	c := command{
		cmdName:   "MFCR",
		cmdString: "MFCR\t" + "R" + strconv.Itoa(D),
		cmdSimple: []int{31, D << 10, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLWARX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LWARX",
		cmdString: "LWARX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLWZX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LWZX",
		cmdString: "LWZX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSLWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "SLW"
	} else {
		NAME = "SLW."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartCNTLZWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "CNTLZW"
	} else {
		NAME = "CNTLZW."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S),
		cmdSimple: []int{31, S, A << 5, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartANDX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "AND"
	} else {
		NAME = "AND."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartCMPL(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 10) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	D := getBits(6, 8, num)
	L := getBits(10, 10, num)
	A := getBits(11, 15, num)
	SIMM := getBits(16, 31, num)
	c := command{
		cmdName:   "CMPL",
		cmdString: "CMPL\tCRF" + strconv.Itoa(D) + ", " + strconv.Itoa(L) + ", R" + strconv.Itoa(A) + ", " + strconv.Itoa(SIMM),
		cmdSimple: []int{31, D, A, SIMM},
		asBytes:   num,
	}

	return num, c
}
func dis31StartSUBFX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "SUB"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "SUB."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "SUBO"
	} else {
		NAME = "SUBO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartDCBST(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "DCBST",
		cmdString: "DCBST\t" + "R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLWZUX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LWZUX",
		cmdString: "LWZUX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartANDCX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "ANDC"
	} else {
		NAME = "ANDC."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMULHWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "MULHW"
	} else {
		NAME = "MULHW."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMFMSR(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	c := command{
		cmdName:   "MFMSR",
		cmdString: "MFMSR\t" + "R" + strconv.Itoa(D),
		cmdSimple: []int{31, D << 10, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartDCBF(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "DCBF",
		cmdString: "DCBF\t" + "R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLBZX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LBZX",
		cmdString: "LBZX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartNEGX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "NEG"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "NEG."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "NEGO"
	} else {
		NAME = "NEGO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A),
		cmdSimple: []int{31, D, A << 5, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis31StartLBZUX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LBZUX",
		cmdString: "LBZUX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartNORX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "NOR"
	} else {
		NAME = "NOR."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSUBFEX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "SUBFE"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "SUBFE."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "SUBFEO"
	} else {
		NAME = "SUBFEO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartADDEX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "ADDE"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "ADDE."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "ADDEO"
	} else {
		NAME = "ADDEO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMTCRF(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 10) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	S := getBits(6, 10, num)
	CRM := getBits(12, 19, num)
	c := command{
		cmdName:   "MTCRF",
		cmdString: "MTCRF\t" + strconv.Itoa(CRM) + ", R" + strconv.Itoa(S),
		cmdSimple: []int{31, S, 0, CRM, 0, getBits(21, 31)},
		asBytes:   num,
	}

	return num, c
}
func dis31StartMTMSR(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	c := command{
		cmdName:   "MTMSR",
		cmdString: "MTMSR\t" + "R" + strconv.Itoa(S),
		cmdSimple: []int{31, S << 10, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTWCXd(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "STWCX.",
		cmdString: "STWCX.\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTWX(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "STWX",
		cmdString: "STWX\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTWUX(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "STWUX",
		cmdString: "STWUX\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSUBFZEX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "SUBFZE"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "SUBFZE."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "SUBFZEO"
	} else {
		NAME = "SUBFZEO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartADDZEX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "ADDZE"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "ADDZE."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "ADDZEO"
	} else {
		NAME = "ADDZEO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMTSR(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	SR := getBits(12, 15, num)
	c := command{
		cmdName:   "MTSR",
		cmdString: "MTSR\t" + strconv.Itoa(SR) + ",R" + strconv.Itoa(S),
		cmdSimple: []int{31, S, 0, SR << 4, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTBX(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "STBX",
		cmdString: "STBX\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis31StartSUBFMEX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "SUBFME"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "SUBFME."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "SUBFMEO"
	} else {
		NAME = "SUBFMEO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A),
		cmdSimple: []int{31, D, A << 5, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartADDMEX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "ADDME"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "ADDME."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "ADDMEO"
	} else {
		NAME = "ADDMEO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A),
		cmdSimple: []int{31, D, A << 5, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMULLWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "MULW"
	} else {
		NAME = "MULW."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMTSRIN(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "MTSRIN",
		cmdString: "MTSRIN\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis31StartDCBTST(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "DCBTST",
		cmdString: "DCBTST\t" + "R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTBUX(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "STBUX",
		cmdString: "STBUX\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartADDX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "ADD"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "ADD."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "ADDO"
	} else {
		NAME = "ADDO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartDCBT(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "DCBTST",
		cmdString: "DCBTST\t" + "R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLHZX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LHZX",
		cmdString: "LHZX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartEQVX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "EQV"
	} else {
		NAME = "EQV."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartTLBIE(num uint32, comm command) (uint32, command) {
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "TLBIE",
		cmdString: "TLBIE\t" + "R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 10, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartECIWX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "ECIWX",
		cmdString: "ECIWX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLHZUX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LHZUX",
		cmdString: "LHZUX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartXORX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "XOR"
	} else {
		NAME = "XOR."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMFSPR(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	SPR := getBits(11, 20, num)
	c := command{
		cmdName:   "MFSPR",
		cmdString: "MFSPR\t" + "R" + strconv.Itoa(D) + "," + strconv.Itoa(SPR),
		cmdSimple: []int{31, D, SPR, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLHAX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LHAX",
		cmdString: "LHAX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMFTB(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	TBR := getBits(11, 20, num)
	c := command{
		cmdName:   "MFSPR",
		cmdString: "MFSPR\t" + "R" + strconv.Itoa(D) + "," + strconv.Itoa(TBR),
		cmdSimple: []int{31, D, TBR, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLHAUX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LHAUX",
		cmdString: "LHAUX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTHX(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "STHX",
		cmdString: "STHX\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartORCX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "ORC"
	} else {
		NAME = "ORC."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartECOWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "ECOWX"
	} else {
		NAME = "ECOWX."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTHUX(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "STHUX",
		cmdString: "STHUX" + "\tR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartORX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "OR"
	} else {
		NAME = "OR."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartDIVWUX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "DIVWU"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "DIVWU."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "DIVWUO"
	} else {
		NAME = "DIVWUO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMTSPR(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	SPR := getBits(11, 20, num)
	c := command{
		cmdName:   "MTSPR",
		cmdString: "MTSPR\t" + "R" + strconv.Itoa(D) + "," + strconv.Itoa(SPR),
		cmdSimple: []int{31, D, SPR, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartDCBI(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "DCBI",
		cmdString: "DCBI\t" + "R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartNANDX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "NAND"
	} else {
		NAME = "NAND."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartDIVWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 21, num)
	DOT := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 && DOT == 0 {
		NAME = "DIVW"
	} else if TYPE == 0 && DOT == 1 {
		NAME = "DIVW."
	} else if TYPE == 1 && DOT == 0 {
		NAME = "DIVWO"
	} else {
		NAME = "DIVWO."
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMCRXR(num uint32, comm command) (uint32, command) {
	D := getBits(6, 8, num)
	c := command{
		cmdName:   "MCRXR",
		cmdString: "MCRXR\t" + "CRF" + strconv.Itoa(D),
		cmdSimple: []int{31, D << 12, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLSWX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LSWX",
		cmdString: "LSWX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLWBRX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LWBRX",
		cmdString: "LWBRX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLFSX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LSWX",
		cmdString: "LSWX\t" + "FR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSRWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "SRW"
	} else {
		NAME = "SRW."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartTLBSYNC(num uint32, comm command) (uint32, command) {
	NAME:= "TLBSYNC";
	c := command{
		cmdName:   NAME,
		cmdString: NAME,
		cmdSimple: []int{31, getBits(6, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLFSUX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LSUX",
		cmdString: "LSUX\t" + "FR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMFSR(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	SR := getBits(12, 15, num)
	c := command{
		cmdName:   "MFSR",
		cmdString: "MFSR\t" + "R" + strconv.Itoa(D) + strconv.Itoa(SR) + "," + strconv.Itoa(D),
		cmdSimple: []int{31, D, 0, SR << 4, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLSWI(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	NB := getBits(16, 20, num)
	c := command{
		cmdName:   "LSWI",
		cmdString: "LSWI\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(NB),
		cmdSimple: []int{31, D, A, NB, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSYNC(num uint32, comm command) (uint32, command) {
	NAME:= "SYNC";
	c := command{
		cmdName:   NAME,
		cmdString: NAME,
		cmdSimple: []int{31, getBits(6, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLFDX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LFDX",
		cmdString: "LFDX\t" + "FR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLFDUX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LFDUX",
		cmdString: "LFDUX\t" + "FR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartMFSRIN(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "MTSRIN",
		cmdString: "MTSRIN\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTSWX(num uint32, comm command) (uint32, command) {
	NAME := "STSWX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTWBRX(num uint32, comm command) (uint32, command) {
	NAME := "STWBRX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTFSX(num uint32, comm command) (uint32, command) {
	NAME := "STFSX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tFR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTFSUX(num uint32, comm command) (uint32, command) {
	NAME := "STFSUX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tFR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTSWI(num uint32, comm command) (uint32, command) {
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	NB := getBits(16, 20, num)
	c := command{
		cmdName:   "STSWI",
		cmdString: "STSWI\t" + "R" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(NB),
		cmdSimple: []int{31, S, A, NB, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTFDX(num uint32, comm command) (uint32, command) {
	NAME := "STFDX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tFR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTFDUX(num uint32, comm command) (uint32, command) {
	NAME := "STFDUX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tFR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartLHBRX(num uint32, comm command) (uint32, command) {
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "LHBRX",
		cmdString: "LHBRX\t" + "R" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSRAWX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "SRAW"
	} else {
		NAME = "SRAW."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSRAWIX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "SRAWI"
	} else {
		NAME = "SRAWI."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	SH := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S) + ",R" + strconv.Itoa(SH),
		cmdSimple: []int{31, S, A, SH, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartEIEIO(num uint32, comm command) (uint32, command) {
	NAME:= "EIEIO";
	c := command{
		cmdName:   NAME,
		cmdString: NAME,
		cmdSimple: []int{31, getBits(6, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTHBRX(num uint32, comm command) (uint32, command) {
	NAME := "STHBRX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartEXTSHX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "EXTSH"
	} else {
		NAME = "EXTSH."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S),
		cmdSimple: []int{31, S, A << 5, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartEXTSBX(num uint32, comm command) (uint32, command) {
	TYPE := getBits(31, 31, num)
	NAME := ""
	if TYPE == 0 {
		NAME = "EXTSB"
	} else {
		NAME = "EXTSB."
	}
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(S),
		cmdSimple: []int{31, S, A << 5, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartICBI(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "ICBI",
		cmdString: "ICBI\t" + "R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartSTFIWX(num uint32, comm command) (uint32, command) {
	NAME := "STFIWX"
	S := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   NAME,
		cmdString: NAME + "\tFR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31, S, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis31StartDCBZ(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "DCBZ",
		cmdString: "DCBZ\t" + "R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{31 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}
