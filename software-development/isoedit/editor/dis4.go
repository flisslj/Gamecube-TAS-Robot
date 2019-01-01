package editor

func dis4Start(num uint32, comm command) (uint32, command) {
	//Search through 26-30 bit variable
	switch getBits(26, 30, num) {
	case 0: //PS_CMPU0 CMPO0 PS_CMPU1 PS_CMPO1
		return dis4StartPSCMPU(num, comm)
	case 6: //PSX_LX PSQ_LUX
		return dis4StartPSQL(num, comm)
	case 7: //PSQ_STX PSQ_STUX
		return dis4StartPSQST(num, comm)
	case 8: //PS_SUM0 PS_NEG PS_MR PS_NABS PS_ABS
		return dis4StartPS(num, comm)
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
	return num, command{}
}

func dis4StartPSQL(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSQST(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPS(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSSUM1(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMULS0(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMULS1(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMADDS0(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMADDS1(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMERGE(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSDIV(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSSUB(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSADDMERGE(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartDCBZL(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSSEL(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSRES(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMUL(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSRSQRTE(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMSUB(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSMADD(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSNMSUB(num uint32, comm command) (uint32, command) {
	return num, command{}
}

func dis4StartPSNMADD(num uint32, comm command) (uint32, command) {
	return num, command{}
}
