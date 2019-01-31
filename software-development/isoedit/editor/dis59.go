package editor

import "strconv"

func dis59Start(num uint32, comm command) (uint32, command) {
	//Format needs to be discussed for cmd String
	if num == 0 {

		output := uint32((comm.cmdSimple[0]) + (comm.cmdSimple[1] << 6) + (comm.cmdSimple[2] << 11) + (comm.cmdSimple[3] << 16))

		return output, comm
	}
	TYPE := getBits(26, 31, num)
	switch TYPE {
	//CASE FDIVS and FDIVS.
	case 36:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FDIVS",
			cmdString: "FDIVS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D, A, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	case 37:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FDIVS.",
			cmdString: "FDIVS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D, A, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	//CASE FSUBS and FSUBS.
	case 40:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FSUBS",
			cmdString: "FSUBS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D, A, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	case 41:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FSUBS.",
			cmdString: "FSUBS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D, A, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	//CASE FADDS and FADDS.
	case 42:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FADDS",
			cmdString: "FADDS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D, A, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	case 43:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FADDS.",
			cmdString: "FADDS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D, A, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	//CASE FRES and FRES.
	case 48:
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FRES",
			cmdString: "FRES\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D << 5, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	case 49:
		D := getBits(6, 10, num)
		B := getBits(16, 20, num)
		c := command{
			cmdName:   "FRES",
			cmdString: "FRES\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(B),
			cmdSimple: []int{59, D << 5, B << 5, TYPE},
			asBytes:   num,
		}
		return num, c
	case 50:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FMULS",
			cmdString: "FMULS\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
			cmdSimple: []int{59, D, A << 5, C, TYPE},
			asBytes:   num,
		}
		return num, c
	case 51:
		D := getBits(6, 10, num)
		A := getBits(11, 15, num)
		C := getBits(21, 25, num)
		c := command{
			cmdName:   "FMULS.",
			cmdString: "FMULS.\tFR" + strconv.Itoa(D) + ",FR" + strconv.Itoa(A) + ",FR" + strconv.Itoa(C),
			cmdSimple: []int{59, D, A << 5, C, TYPE},
			asBytes:   num,
		}
		return num, c
	case 56:
		return num, comm
	default:
		return num, comm
	}

}

//ended on ori command
