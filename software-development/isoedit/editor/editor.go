package editor

import (
	"encoding/binary"
	"io/ioutil"
)

type command struct {
	next      *command
	cmdName   string // "mulhwux"
	cmdString string
	cmdSimple []int // "31:D:A:B:0:9:RC"
	asBytes   uint32
	branch    *command
	addr      uint32
}

func EditFile(location string, frames, clock int, infinite bool) {
	replaceFile(location, toBytes(alter(toInts(loadFile(location)), frames, clock, infinite)))
}

//This function grabs the data from the main.dol file and loads it.
func loadFile(location string) []byte {

	dat, err := ioutil.ReadFile(location + "/src/main.dol")

	if err != nil {
		panic(err)
	}

	return dat
}

//This function replaces the main.do file with the converted data.
func replaceFile(location string, data []byte) {

	err := ioutil.WriteFile(location+"/src/main.dol", data, 0644)
	if err != nil {
		panic(err)
	}
}

//convert the data input into a series of integers that are easier to operate on as a whole
func toInts(data []byte) []uint32 {
	out := make([]uint32, len(data))
	for i := 0; i < len(data)/4; i++ {
		out[i] = binary.BigEndian.Uint32(data[i*4 : i*4+4])
	}
	return out
}

//convert the integers BACK to bytes so that the file can be output and saved.
func toBytes(data []uint32) []byte {
	out := make([]byte, len(data)*4)
	for i := 0; i < len(data); i++ {
		binary.BigEndian.PutUint32(out, data[i])
	}
	return out
}

//Function Responsible for the majority of the alterations made to the
func alter(data []uint32, frames, clock int, infinite bool) []uint32 {

	commands := toCommands(data)
	head := makeGraph(commands)

	head = magic(head, frames, infinite)

	alteredCommands := makeArray(head)
	return assemble(alteredCommands)

}

//Convert the integers into command
func toCommands(data []uint32) []command {
	out := make([]command, len(data))
	for i, v := range data {
		out[i] = disassembleInt(v)
		out[i].addr = uint32(i * 4)
	}
	return out

}

//take the commands and convert them into a graph vs a list.
func makeGraph(commands []command) command {

	return commands[0]
}

//this is where the magic happens, and the magic commands are inserted.
func magic(head command, frames int, inf bool) command {

	return head
}

//reconvert the commands back into an array.
func makeArray(head command) []command {

	out := make([]command, 0)

	next := head
	value := head.addr
	for next.next != nil {
		out = append(out, next)
		next = *next.next
		value = value + 4
		next.addr = value
	}
	out = append(out, next)
	return out
}

//assemble the commands into a series of integers again.
func assemble(commands []command) []uint32 {

	out := make([]uint32, len(commands))
	for i, v := range commands {
		out[i] = assembleCommand(v)
	}
	return out
}
