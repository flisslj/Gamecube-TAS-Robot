package editor

func dis31Start(num uint32, comm command) (uint32, command) {
	//12/13/18 Put a "default format" Needs to be discussed on how this should be done due to somewhat complex tings
	t := 0
	if num == 0 {
		t = getBits(26, 30, comm.asBytes)

	} else {
		t = getBits(26, 30, num)

	}

	switch t {
	case 0:
		return dis31StartCMP(num, comm)
	case 4:
		return dis31StartTW(num, comm)
	case 8:
		fallthrough
	case 520:
		return dis31StartSUBFCX(num, comm)
	case 10:
		fallthrough
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
		fallthrough
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
		fallthrough
	case 616:
		return dis31StartNEGX(num, comm)
	case 119:
		return dis31StartLBZUX(num, comm)
	case 124:
		return dis31StartNORX(num, comm)
	case 136:
		fallthrough
	case 648:
		return dis31StartSUBFEX(num, comm)
	case 138:
		fallthrough
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
		fallthrough
	case 712:
		return dis31StartSUBFZEX(num, comm)
	case 202:
		fallthrough
	case 714:
		return dis31StartADDZEX(num, comm)
	case 210:
		return dis31StartMTSR(num, comm)
	case 215:
		return dis31StartSTBX(num, comm)
	case 232:
		fallthrough
	case 744:
		return dis31StartSUBFMEX(num, comm)
	case 234:
		fallthrough
	case 746:
		return dis31StartADDMEX(num, comm)
	case 235:
		fallthrough
	case 747:
		return dis31StartMULLWX(num, comm)
	case 242:
		return dis31StartMTSRIN(num, comm)
	case 246:
		return dis31StartDCBTST(num, comm)
	case 247:
		return dis31StartSTBUX(num, comm)
	case 266:
		fallthrough
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
		fallthrough
	case 971:
		return dis31StartDIVWUX(num, comm)
	case 467:
		return dis31StartMTSPR(num, comm)
	case 470:
		return dis31StartDCBI(num, comm)
	case 476:
		return dis31StartNANDX(num, comm)
	case 491:
		fallthrough
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
	return num, command{}
}
func dis31StartTW(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSUBFCX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartADDCX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMULHWUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMFCR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLWARX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLWZX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSLWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartCNTLZWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartANDX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartCMPL(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSUBFX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDCBST(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLWZUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartANDCX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMULHWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMFMSR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDCBF(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLBZX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartNEGX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLBZUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartNORX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSUBFEX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartADDEX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMTCRF(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMTMSR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTWCXd(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTWUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSUBFZEX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartADDZEX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMTSR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTBX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSUBFMEX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartADDMEX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMULLWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMTSRIN(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDCBTST(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTBUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartADDX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDCBT(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLHZX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartEQVX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartTLBIE(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartECIWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLHZUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartXORX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMFSPR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLHAX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMFTB(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLHAUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTHX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartORCX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartECOWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTHUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartORX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDIVWUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMTSPR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDCBI(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartNANDX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDIVWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMCRXR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLSWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLWBRX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLFSX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSRWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartTLBSYNC(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLFSUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMFSR(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLSWI(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSYNC(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLFDX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLFDUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartMFSRIN(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTSWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTWBRX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTFSX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTFSUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTSWI(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTFDX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTFDUX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartLHBRX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSRAWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSRAWIX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartEIEIO(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTHBRX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartEXTSHX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartEXTSBX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartICBI(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartSTFIWX(num uint32, comm command) (uint32, command) {
	return num, command{}
}
func dis31StartDCBZ(num uint32, comm command) (uint32, command) {
	return num, command{}
}
