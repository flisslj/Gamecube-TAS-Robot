package main

import (
	"flag"
	"fmt"
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

	frameFlag := flag.Int("f", 600, memString)
	//flag.IntVar(frameFlag, "m", 600, memString)

	clockFlag := flag.Int("c", -1, clockString)
	//flag.IntVar(clockFlag, "c", -1, clockString)

	infiniteFlag := flag.Bool("i", false, infString)
	//flag.BoolVar(infiniteFlag, "i", false, infString)

	flag.Parse()

	fmt.Printf("Memory flag value: %d\nClock Flag Value:%d\nInfinite Flag Value:%t\n", *frameFlag, *clockFlag, *infiniteFlag)
}
