package editor

var bits = 0
var pscmpu0 = 0
var psqlx = 6

func dis4Start(num uint32, comm command) (uint32, command) {
	//Variable with bits 21-30
	//Variable with bits 25-30
	//Variable with bits 21-30

	//Search through 26-30 bit variable
	switch getBits(26, 30, num) {
	case 0: //PS_CMPU0 CMPO0 PS_CMPU1 PS_CMPO1
	case 6: //PSX_LX PSQ_LUX
	case 7: //PSQ_STX PSQ_STUX
	case 8: //PS_SUM0 PS_NEG PS_MR PS_NABS PS_ABS
	case 11: //PS_SUM1
	case 12: //PS_MULS0
	case 13: //PS_MULS1
	case 14: //PS_MADDS0
	case 15: //PS_MADDS1
	case 16: //PS_MERGE00 PS_MERGE01 PS_MERGE11
	case 18: //PS_DIV
	case 20: //PS_SUB
	case 21: //PS_ADD PS_MERGE10
	case 22: //DCBZ_L
	case 23: //PS_SEL
	case 24: //PS_RES
	case 25: //PS_MUL
	case 26: //PS_RSQRTE
	case 28: //PS_MSUB
	case 29: //PS_MADD
	case 30: //PS_NMSUB
	case 31: //PS_NMADD
	}
	return 0, command{}
}
