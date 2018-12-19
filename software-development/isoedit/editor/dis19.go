package editor

import "strconv"

func dis19Start(num uint32, comm command) (uint32, command) {
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}

	TYPE := getBits(21, 30, num)
	NAME := ""
	switch TYPE {
	//TYPE MCRF
	case 0:
		CRFD := getBits(6, 8, num)
		CRFS := getBits(11, 13, num)
		c := command{
			cmdName:   "MCRF",
			cmdString: "MCRF\tCRF" + strconv.Itoa(CRFD) + ", CRF" + strconv.Itoa(CRFS),
			cmdSimple: []int{19, CRFD << 2, CRFS << 6, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//BCLRx
	case 16:
		BO := getBits(6, 10, num)
		BI := getBits(11, 15, num)
		LK := getBits(31, 31, num)
		if LK == 0 {
			NAME = "BCLR"
		} else {
			NAME = "BCLRL"
		}
		c := command{
			cmdName:   NAME,
			cmdString: NAME + "\t" + strconv.Itoa(BO) + ", " + strconv.Itoa(BI),
			cmdSimple: []int{19, BO, BI << 5, TYPE, LK},
			asBytes:   num,
		}

		return num, c
	//CASE CRNOR
	case 33:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CRNOR",
			cmdString: "CRNOR\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE RFI
	case 50:
		c := command{
			cmdName:   "RFI",
			cmdString: "RFI\t",
			cmdSimple: []int{19 << 15, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE CRANDC
	case 129:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CRANDC",
			cmdString: "CRANDC\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE ISYNC
	case 150:
		c := command{
			cmdName:   "ISYNC",
			cmdString: "ISYNC\t",
			cmdSimple: []int{19 << 15, TYPE << 1},
			asBytes:   num,
		}
		return num, c
	case 193:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CRXOR",
			cmdString: "CRXOR\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE CRNAND
	case 225:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CRNANDC",
			cmdString: "CRNANDC\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE CRAND
	case 257:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CRAND",
			cmdString: "CRAND\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE CREQV
	case 289:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CREQV",
			cmdString: "CREQV\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE CRORC
	case 417:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CRORC",
			cmdString: "CRORC\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE CROR
	case 449:
		CRBD := getBits(6, 10, num)
		CRBA := getBits(11, 15, num)
		CRBB := getBits(16, 20, num)
		c := command{
			cmdName:   "CROR",
			cmdString: "CROR\tCRB" + strconv.Itoa(CRBD) + ", CRB" + strconv.Itoa(CRBA) + ", " + strconv.Itoa(CRBB),
			cmdSimple: []int{19, CRBD, CRBA, CRBB, TYPE << 1},
			asBytes:   num,
		}

		return num, c
	//CASE BCCTRx
	case 528:
		BO := getBits(6, 10, num)
		BI := getBits(11, 15, num)
		LK := getBits(31, 31, num)
		if LK == 0 {
			NAME = "BCCTR"
		} else {
			NAME = "BCCTRL"
		}
		c := command{
			cmdName:   NAME,
			cmdString: NAME + "\t" + strconv.Itoa(BO) + ", " + strconv.Itoa(BI),
			cmdSimple: []int{19, BO, BI << 5, TYPE, LK},
			asBytes:   num,
		}
		return num, c
	}
	return num, comm
}
