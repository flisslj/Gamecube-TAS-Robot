package editor

import (
	"fmt"
	"os"
)

func disassembleInt(cmd uint32) command {

	sw := getBits(0, 5, cmd)

	switch sw {

	//case 1:
	//	_, b := dis1Start(cmd, command{})
	//	return b
	//case 2:
	//	_, b := dis2Start(cmd, command{})
	//	return b
	case 3:
		_, b := dis3Start(cmd, command{})
		return b
	case 4:
		_, b := dis4Start(cmd, command{})
		return b
	//case 5:
	//	_, b := dis5Start(cmd, command{})
	//	return b
	//case 6:
	//	_, b := dis6Start(cmd, command{})
	//	return b
	case 7:
		_, b := dis7Start(cmd, command{})
		return b
	case 8:
		_, b := dis8Start(cmd, command{})
		return b
	//case 9:
	//	_, b := dis9Start(cmd, command{})
	//	return b
	case 10:
		_, b := dis10Start(cmd, command{})
		return b
	case 11:
		_, b := dis11Start(cmd, command{})
		return b
	case 12:
		_, b := dis12Start(cmd, command{})
		return b
	case 13:
		_, b := dis13Start(cmd, command{})
		return b
	case 14:
		_, b := dis14Start(cmd, command{})
		return b
	case 15:
		_, b := dis15Start(cmd, command{})
		return b
	case 16:
		_, b := dis16Start(cmd, command{})
		return b
	case 17:
		_, b := dis17Start(cmd, command{})
		return b
	case 18:
		_, b := dis18Start(cmd, command{})
		return b
	case 19:
		_, b := dis19Start(cmd, command{})
		return b
	case 20:
		_, b := dis20Start(cmd, command{})
		return b
	case 21:
		_, b := dis21Start(cmd, command{})
		return b
	//case 22:
	//	_, b := dis22Start(cmd, command{})
	//	return b
	case 23:
		_, b := dis23Start(cmd, command{})
		return b
	case 24:
		_, b := dis24Start(cmd, command{})
		return b
	case 25:
		_, b := dis25Start(cmd, command{})
		return b
	case 26:
		_, b := dis26Start(cmd, command{})
		return b
	case 27:
		_, b := dis27Start(cmd, command{})
		return b
	case 28:
		_, b := dis28Start(cmd, command{})
		return b
	case 29:
		_, b := dis29Start(cmd, command{})
		return b
	//case 30:
	//	_, b := dis30Start(cmd, command{})
	//	return b
	case 31:
		_, b := dis31Start(cmd, command{})
		return b
	case 32:
		_, b := dis32Start(cmd, command{})
		return b
	case 33:
		_, b := dis33Start(cmd, command{})
		return b
	case 34:
		_, b := dis34Start(cmd, command{})
		return b
	case 35:
		_, b := dis35Start(cmd, command{})
		return b
	case 36:
		_, b := dis36Start(cmd, command{})
		return b
	case 37:
		_, b := dis37Start(cmd, command{})
		return b
	case 38:
		_, b := dis38Start(cmd, command{})
		return b
	case 39:
		_, b := dis39Start(cmd, command{})
		return b
	case 40:
		_, b := dis40Start(cmd, command{})
		return b
	case 41:
		_, b := dis41Start(cmd, command{})
		return b
	case 42:
		_, b := dis42Start(cmd, command{})
		return b
	case 43:
		_, b := dis43Start(cmd, command{})
		return b
	case 44:
		_, b := dis44Start(cmd, command{})
		return b
	case 45:
		_, b := dis45Start(cmd, command{})
		return b
	case 46:
		_, b := dis46Start(cmd, command{})
		return b
	case 47:
		_, b := dis47Start(cmd, command{})
		return b
	case 48:
		_, b := dis48Start(cmd, command{})
		return b
	case 49:
		_, b := dis49Start(cmd, command{})
		return b
	case 50:
		_, b := dis50Start(cmd, command{})
		return b
	case 51:
		_, b := dis51Start(cmd, command{})
		return b
	case 52:
		_, b := dis52Start(cmd, command{})
		return b
	case 53:
		_, b := dis53Start(cmd, command{})
		return b
	case 54:
		_, b := dis54Start(cmd, command{})
		return b
	case 55:
		_, b := dis55Start(cmd, command{})
		return b
	case 56:
		_, b := dis56Start(cmd, command{})
		return b
	case 57:
		_, b := dis57Start(cmd, command{})
		return b
	//case 58:
	//	_, b := dis58Start(cmd, command{})
	//	return b
	case 59:
		_, b := dis59Start(cmd, command{})
		return b
	case 60:
		_, b := dis60Start(cmd, command{})
		return b
	case 61:
		_, b := dis61Start(cmd, command{})
		return b
	//case 62:
	//	_, b := dis62Start(cmd, command{})
	//	return b
	case 63:
		_, b := dis63Start(cmd, command{})
		return b
	default:
		if sw != 0 {
			fmt.Println("Command ", sw, " Does not exist.")
		}
		//os.Exit(1)
	}
	return command{}
}

func assembleCommand(cmd command) uint32 {
	switch getBits(0, 5, cmd.asBytes) {
	case 3:
		dis3Start(0, cmd)
	case 4:
	default:
		fmt.Println("Command ", cmd, " Does not exist.")
		os.Exit(1)
	}

	return 0
}

func getBits(low, high uint32, command uint32) int {

	high, low = 31-low, 31-high

	//clear upto the high bits.

	width := high - low + 1
	// shifted over.
	base := command >> low

	mask := uint32((1 << width) - 1)

	//clear upto the high bits.

	return int(base & mask)
}
