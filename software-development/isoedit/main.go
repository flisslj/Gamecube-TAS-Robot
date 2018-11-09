package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	fmt.Printf("Hello World.")

	memString := `The frame that the memory dump will trigger on. 
If --infinite is set, the number of frames between memory dumps.
Default value is 600 (10 seconds)`

	clockString := `Sets the value for the game clock to return when checked. 
Recommended Default is 0.
Game clock unaltered (-1) if unset.`

	infString := `If the memory dumps should be every m frames instead of at frame m.`

	isoString := `The location of the iso file.`
	outString := `The location to write the output file to.`

	frameFlag := flag.Int("f", 600, memString)
	//flag.IntVar(frameFlag, "m", 600, memString)

	clockFlag := flag.Int("c", -1, clockString)
	//flag.IntVar(clockFlag, "c", -1, clockString)

	infiniteFlag := flag.Bool("inf", false, infString)
	//flag.BoolVar(infiniteFlag, "i", false, infString)

	isoFlag := flag.String("iso", ".", isoString)

	outputFlag := flag.String("out", "", outString)

	flag.Parse()

	if *isoFlag == "." {
		fmt.Printf("Please enter a valid iso flag string: '%s'", *isoFlag)
		os.Exit(1)
	}

	if *outputFlag == "" {
		fmt.Printf("Please enter a valid output flag string: '%s'", *outputFlag)
		os.Exit(1)
	}

	fmt.Printf("Memory flag value: %d\nClock Flag Value:%d\nInfinite Flag Value:%t\nRemaning Flags: %d\n", *frameFlag, *clockFlag, *infiniteFlag, flag.NArg())
	StartManipulation(*frameFlag, *clockFlag, *infiniteFlag, *isoFlag, *outputFlag)
}

func StartManipulation(frames, clock int, infinite bool, iso, output string) {
	dat, err := ioutil.ReadFile(iso)
	if err != nil {
		fmt.Printf("Error retreving iso file: %s\n", err.Error())
		os.Exit(1)
	}

	fmt.Printf("DataLength: %d\n", len(dat))

}
