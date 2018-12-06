package editor

import (
	"encoding/binary"
	"io/ioutil"
)

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

	return nil
}
