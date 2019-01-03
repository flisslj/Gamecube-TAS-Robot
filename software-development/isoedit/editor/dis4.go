package editor

import "strconv"

func dis4Start(num uint32, comm command) (uint32, command) {
	//Search through 26-30 bit variable
	switch getBits(26, 30, num) {
	case 0: //PS_CMPU0 CMPO0 PS_CMPU1 PS_CMPO1
		return dis4StartPSCMPU(num, comm)
	case 6: //PSX_LX PSQ_LUX
		return dis4StartPSQL(num, comm)
	case 7: //PSQ_STX PSQ_STUX
		return dis4StartPSQST(num, comm)
	case 8: //PS_NEG PS_MR PS_NABS PS_ABS
		return dis4StartPS(num, comm)
	case 10:
		return dis4StartPSSUM0(num, comm)
	case 11: //PS_SUM1
		return dis4StartPSSUM1(num, comm)
	case 12: //PS_MULS0
		return dis4StartPSMULS0(num, comm)
	case 13: //PS_MULS1
		return dis4StartPSMULS1(num, comm)
	case 14: //PS_MADDS0
		return dis4StartPSMADDS0(num, comm)
	case 15: //PS_MADDS1
		return dis4StartPSMADDS1(num, comm)
	case 16: //PS_MERGE00 PS_MERGE01 PS_MERGE11]
		return dis4StartPSMERGE(num, comm)
	case 18: //PS_DIV
		return dis4StartPSDIV(num, comm)
	case 20: //PS_SUB
		return dis4StartPSSUB(num, comm)
	case 21: //PS_ADD PS_MERGE10
		return dis4StartPSADDMERGE(num, comm)
	case 22: //DCBZ_L
		return dis4StartDCBZL(num, comm)
	case 23: //PS_SEL
		return dis4StartPSSEL(num, comm)
	case 24: //PS_RES
		return dis4StartPSRES(num, comm)
	case 25: //PS_MUL
		return dis4StartPSMUL(num, comm)
	case 26: //PS_RSQRTE
		return dis4StartPSRSQRTE(num, comm)
	case 28: //PS_MSUB
		return dis4StartPSMSUB(num, comm)
	case 29: //PS_MADD
		return dis4StartPSMADD(num, comm)
	case 30: //PS_NMSUB
		return dis4StartPSNMSUB(num, comm)
	case 31: //PS_NMADD
		return dis4StartPSNMADD(num, comm)
	}

	return 0, command{}
}
func dis4StartPSCMPU(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 25, num)

	if TYPE == 0 {
		CRFD := getBits(6, 8, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_CMPU0",
			cmdString: "PS_CMPU0\tCRF" + strconv.Itoa(CRFD) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, CRFD << 2, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 1 {
		CRFD := getBits(6, 8, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_CMPO0",
			cmdString: "PS_CMPO0\tCRF" + strconv.Itoa(CRFD) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, CRFD << 2, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 2 {
		CRFD := getBits(6, 8, num)
		CRFS := getBits(11, 13, num)
		c := command{
			cmdName:   "PS_CMPU1",
			cmdString: "PS_CMPU1\tCRF" + strconv.Itoa(CRFD) + ",CRF" + strconv.Itoa(CRFS),
			cmdSimple: []int{4, CRFD << 2, CRFS << 7, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 3 {
		CRFD := getBits(6, 8, num)
		CRFS := getBits(11, 13, num)
		c := command{
			cmdName:   "PS_CMPO1",
			cmdString: "PS_CMPO1\tCRF" + strconv.Itoa(CRFD) + ",CRF" + strconv.Itoa(CRFS),
			cmdSimple: []int{4, CRFD << 2, CRFS << 7, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else {
		return num, command{}
	}
}

func dis4StartPSQL(num uint32, comm command) (uint32, command) {
	TYPE := getBits(25, 25, num)

	if TYPE == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		W := getBits(21, 21, num)
		I := getBits(22, 25, num)
		c := command{
			cmdName:   "PSQ_LX",
			cmdString: "PSQ_LX\tFR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B) + "," + strconv.Itoa(W) + "," + strconv.Itoa(I),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 1 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		W := getBits(21, 21, num)
		I := getBits(22, 25, num)
		c := command{
			cmdName:   "PSQ_LUX",
			cmdString: "PSQ_LUX\tFR" + strconv.Itoa(D) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B) + "," + strconv.Itoa(W) + "," + strconv.Itoa(I),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else {
		return num, command{}
	}
}

func dis4StartPSQST(num uint32, comm command) (uint32, command) {
	TYPE := getBits(25, 25, num)

	if TYPE == 0 {
		S := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		W := getBits(21, 21, num)
		I := getBits(22, 25, num)
		c := command{
			cmdName:   "PSQ_STX",
			cmdString: "PSQ_STX\tFR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B) + "," + strconv.Itoa(W) + "," + strconv.Itoa(I),
			cmdSimple: []int{4, S, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 1 {
		S := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		W := getBits(21, 21, num)
		I := getBits(22, 25, num)
		c := command{
			cmdName:   "PSQ_STUX",
			cmdString: "PSQ_STUX\tFR" + strconv.Itoa(S) + ",R" + strconv.Itoa(A) + ",R" + strconv.Itoa(B) + "," + strconv.Itoa(W) + "," + strconv.Itoa(I),
			cmdSimple: []int{4, S, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else {
		return num, command{}
	}
}

func dis4StartPS(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 25, num)

	if TYPE == 1 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_NEG",
				cmdString: "PS_NEG\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_NEG.",
			cmdString: "FNEG.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 2 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_MR",
				cmdString: "PS_MR\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_MR.",
			cmdString: "PS_MR.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 4 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_NABS",
				cmdString: "PS_NABS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_NABS.",
			cmdString: "PS_NABS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 8 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_ABS",
				cmdString: "PS_ABS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_ABS.",
			cmdString: "PS_ABS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else {
		return num, command{}
	}
}
func dis4StartPSSUM0(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_SUM0",
			cmdString: "PS_SUM0\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_SUM0.",
		cmdString: "PS_SUM0.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}
func dis4StartPSSUM1(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_SUM1",
			cmdString: "PS_SUM1\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_SUM1.",
		cmdString: "PS_SUM1.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMULS0(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_MULS0",
			cmdString: "PS_MULS0\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
			cmdSimple: []int{4, D, A << 5, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_MULS0.",
		cmdString: "PS_MULS0.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
		cmdSimple: []int{4, D, A << 5, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMULS1(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_MULS1",
			cmdString: "PS_MULS1\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
			cmdSimple: []int{4, D, A << 5, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_MULS1.",
		cmdString: "PS_MULS1.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
		cmdSimple: []int{4, D, A << 5, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMADDS0(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_MADDS0",
			cmdString: "PS_MADDS0\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_MADDS0.",
		cmdString: "PS_MADDS0.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMADDS1(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_MADDS1",
			cmdString: "PS_MADDS1\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_MADDS1.",
		cmdString: "PS_MADDS1.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMERGE(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 25, num)

	if TYPE == 16 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			A := getBits(11, 15, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_MERGE00",
				cmdString: "PS_MERGE00\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_MERGE00.",
			cmdString: "PS_MERGE00.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 17 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			A := getBits(11, 15, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_MERGE01",
				cmdString: "PS_MERGE01\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_MERGE01.",
			cmdString: "PS_MERGE01.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else if TYPE == 19 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			A := getBits(11, 15, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_MERGE11",
				cmdString: "PS_MERGE11\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_MERGE11.",
			cmdString: "PS_MERGE11.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c

	} else {
		return num, command{}
	}
}

func dis4StartPSDIV(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_DIV",
			cmdString: "PS_DIV\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "PS_DIV.",
		cmdString: "PS_DIV.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSSUB(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_SUB",
			cmdString: "PS_SUB\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "PS_SUB.",
		cmdString: "PS_SUB.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSADDMERGE(num uint32, comm command) (uint32, command) {
	TYPE := getBits(21, 25, num)
	if TYPE == 0 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			A := getBits(11, 15, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_SUB",
				cmdString: "PS_SUB\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_SUB.",
			cmdString: "PS_SUB.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else if TYPE == 18 {
		if getBits(31, 31, num) == 0 {
			D := getBits(6, 10, num)
			A := getBits(11, 15, num)
			B := getBits(16, 20, num)
			c := command{
				cmdName:   "PS_MERGE10",
				cmdString: "PS_MERGE10\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
				cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
				asBytes:   num,
			}
			return num, c
		}
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_MERGE10.",
			cmdString: "PS_MERGE10.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	} else {
		return num, command{}
	}
}

func dis4StartDCBZL(num uint32, comm command) (uint32, command) {
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "DCBZ_L",
		cmdString: "DCBZ_L\tR" + strconv.Itoa(A) + ",R" + strconv.Itoa(B),
		cmdSimple: []int{4 << 5, A, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSSEL(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_SEL",
			cmdString: "PS_SEL\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_SEL.",
		cmdString: "PS_SEL.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSRES(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_RES",
			cmdString: "PS_RES\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "PS_RES.",
		cmdString: "PS_RES.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMUL(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_MUL",
			cmdString: "PS_MUL\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
			cmdSimple: []int{4, D, A << 5, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_MUL.",
		cmdString: "PS_MUL.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
		cmdSimple: []int{4, D, A << 5, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSRSQRTE(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "PS_RSQRTE",
			cmdString: "PS_RSQRTE\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	B := getBits(16, 20, num)
	c := command{
		cmdName:   "PS_RSQRTE.",
		cmdString: "PS_RSQRTE.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D << 5, B, getBits(21, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMSUB(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_MSUB",
			cmdString: "PS_MSUB\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_MSUB.",
		cmdString: "PS_MSUB.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSMADD(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_MADD",
			cmdString: "PS_MADD\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_MADD.",
		cmdString: "PS_MADD.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSNMSUB(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_NMSUB",
			cmdString: "PS_NMSUB\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_NMSUB.",
		cmdString: "PS_NMSUB.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}

func dis4StartPSNMADD(num uint32, comm command) (uint32, command) {
	if getBits(31, 31, num) == 0 {
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "PS_NMADD",
			cmdString: "PS_NMADD\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
			asBytes:   num,
		}
		return num, c
	}
	D := getBits(6, 10, num)
	A := getBits(11, 15, num)
	B := getBits(16, 20, num)
	C := getBits(21, 25, num)
	c := command{
		cmdName:   "PS_NMADD.",
		cmdString: "PS_NMADD.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C) + ",FR" + strconv.Itoa(B),
		cmdSimple: []int{4, D, A, B, C, getBits(26, 31, num)},
		asBytes:   num,
	}
	return num, c
}
