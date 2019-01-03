package editor

import "strconv"

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
	case 7:
		return dis63StartMFFS(num, comm)
	case 8: //FNEG and FMR and FNABS and FABS
		return dis63StartFunc(num, comm)
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
	TYPE := getBits(21, 25, num)

	if TYPE == 0 {
		CRFD := getBits(6, 8, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FCMPU",
			cmdString: "FCMPU\tCRF" + strconv.Itoa(CRFD) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, CRFD << 2, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 1 {
		CRFD := getBits(6, 8, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FCMPO",
			cmdString: "FCMPO\tCRF" + strconv.Itoa(CRFD) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, CRFD << 2, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 2 {
		CRFD := getBits(6, 8, num)
		CRFS := getBits(11, 13, num)
		c := command{
			cmdName:   "MCRFS",
			cmdString: "MCRFS\tCRF" + strconv.Itoa(CRFD) + ",CRF" + strconv.Itoa(CRFS),
			cmdSimple: []int{63, CRFD << 2, CRFS << 7, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else {
		return num, command{}
	}

}

func dis63StartMTFS(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 25, num)

	if TYPE == 1 {
		if getBits(31, 31, num) == 0 {
			CRFD := getBits(6, 10, num)
			c := command{
				cmdName:   "MTFSB0",
				cmdString: "MTFSB0\tCRF" + strconv.Itoa(CRFD),
				cmdSimple: []int{63, CRFD << 10, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		CRFD := getBits(6, 10, num)
		c := command{
			cmdName:   "MTFSB0.",
			cmdString: "MTFSB0.\tCRF" + strconv.Itoa(CRFD),
			cmdSimple: []int{63, CRFD << 10, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 2 {
		if getBits(31, 31, num) == 0 {
			CRFD := getBits(6, 10, num)
			c := command{
				cmdName:   "MTFSB1",
				cmdString: "MTFSB1\tCRF" + strconv.Itoa(CRFD),
				cmdSimple: []int{63, CRFD << 10, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		CRFD := getBits(6, 10, num)
		c := command{
			cmdName:   "MTFSB1.",
			cmdString: "MTFSB1.\tCRF" + strconv.Itoa(CRFD),
			cmdSimple: []int{63, CRFD << 10, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 4 {
		if getBits(31, 31, num) == 0 {
			CRFD := getBits(6, 8, num)
			IMM := getBits(16, 19, num)
			c := command{
				cmdName:   "MCRFS",
				cmdString: "MCRFS\tCRF" + strconv.Itoa(CRFD) + "," + strconv.Itoa(IMM),
				cmdSimple: []int{63, CRFD << 7, IMM << 1, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		CRFD := getBits(6, 8, num)
		IMM := getBits(16, 19, num)
		c := command{
			cmdName:   "MCRFS.",
			cmdString: "MCRFS.\tCRF" + strconv.Itoa(CRFD) + "," + strconv.Itoa(IMM),
			cmdSimple: []int{63, CRFD << 7, IMM << 1, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else {
		return num, command{}
	}
}
func dis63StartFunc(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 25, num)

	if TYPE == 1 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "FNEG",
				cmdString: "FNEG\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FNEG.",
			cmdString: "FNEG.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 2 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "FMR",
				cmdString: "FMR\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FMR.",
			cmdString: "FMR.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 4 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "FNABS",
				cmdString: "FNABS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FNABS.",
			cmdString: "FNABS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 8 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "FABS",
				cmdString: "FABS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FABS.",
			cmdString: "FABS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else {
		return num, command{}
	}
}
func dis63StartMFFS(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 25, num)

	if TYPE == 18 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			c := command{
				cmdName:   "MFFS",
				cmdString: "MFFS\tFR" + strconv.Itoa(D),
				cmdSimple: []int{63, D << 10, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		c := command{
			cmdName:   "MFFS.",
			cmdString: "MFFS.\tFR" + strconv.Itoa(D),
			cmdSimple: []int{63, D << 10, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 22 {
		if getBits(31, 31, num) == 0 {
			FM := getBits(7, 14, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "MTFSF",
				cmdString: "MTFSF\t" + strconv.Itoa(FM) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{63 << 1, FM << 1, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		FM := getBits(7, 14, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "MTFSF.",
			cmdString: "MTFSF.\t" + strconv.Itoa(FM) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63 << 1, FM << 1, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else {
		return num, command{}
	}
}
func dis63StartFRSP(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FRSP",
			cmdString: "FRSP\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "FRSP.",
		cmdString: "FRSP.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFCTIW(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FCTIW",
			cmdString: "FCTIW\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63 << 1, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "FCTIW.",
		cmdString: "FCTIW.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63 << 1, D << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFCTIWZ(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FCTIWZ",
			cmdString: "FCTIWZ\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "FCTIWZ.",
		cmdString: "FCTIWZ.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFDIV(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FDIV",
			cmdString: "FDIV\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "FDIV.",
		cmdString: "FDIV.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFSUB(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FSUB",
			cmdString: "FSUB\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "FSUB.",
		cmdString: "FSUB.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFADD(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FADD",
			cmdString: "FADD\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "FADD.",
		cmdString: "FADD.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFSEL(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FSEL",
			cmdString: "FSEL\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "FSEL.",
		cmdString: "FSEL.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFMUL(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FMUL",
			cmdString: "FMUL\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
			cmdSimple: []int{63, D, A << 5, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "FMUL.",
		cmdString: "FMUL.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
		cmdSimple: []int{63, D, A << 5, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFRSQRTE(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FRSQRTE",
			cmdString: "FRSQRTE\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "FRSQRTE.",
		cmdString: "FRSQRTE.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFMSUB(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FMSUB",
			cmdString: "FMSUB\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "FMSUB.",
		cmdString: "FMSUB.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFMADD(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FMADD",
			cmdString: "FMADD\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "FMADD.",
		cmdString: "FMADD.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFNMSUB(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FNMSUB",
			cmdString: "FNMSUB\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "FNMSUB.",
		cmdString: "FNMSUB.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c

}
func dis63StartFNMADD(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FNMADD",
			cmdString: "FNMADD\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "FNMADD.",
		cmdString: "FNMADD.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{63, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c

}

//ended on ori command
