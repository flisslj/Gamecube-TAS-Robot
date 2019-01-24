package main

import (
	"Gamecube-TAS-Robot/software-development/isoedit/editor"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"regexp"
	"strconv"
	"strings"
)

func main() {

	//editor.Test()
	flagParse()
}

func flagParse() {
	memString := `The frame that the memory dump will trigger on. 
	If --infinite is set, the number of frames between memory dumps.
	Default value is 600 (10 seconds)`

	clockString := `Sets the value for the game clock to return when checked. 
	Recommended Default is 0.
	Game clock unaltered ( <= -1) if unset.`

	infString := `If the memory dumps should be every m frames instead of at frame m.`

	isoString := `The location of the iso file.`
	outString := `The location to write the output file to.`
	compString := `The location of gcr. if unset, gcr assumed installed.`

	frameFlag := flag.Int("f", 600, memString)
	//flag.IntVar(frameFlag, "m", 600, memString)

	clockFlag := flag.Int("c", -1, clockString)
	//flag.IntVar(clockFlag, "c", -1, clockString)

	infiniteFlag := flag.Bool("inf", false, infString)
	//flag.BoolVar(infiniteFlag, "i", false, infString)

	isoFlag := flag.String("iso", "", isoString)

	outputFlag := flag.String("out", "", outString)
	compFlag := flag.String("gcr", "", compString)

	flag.Parse()

	//check if iso entered.
	if *isoFlag == "" {
		fmt.Printf("Please enter a valid iso flag string: '%s'", *isoFlag)
		os.Exit(1)
	}

	//check if iso exists.
	if _, err := os.Stat(*isoFlag); os.IsNotExist(err) {
		fmt.Printf("Iso '%s' not detected.", *isoFlag)
		os.Exit(1)
	}

	//if the output flag is NOT set, increment the iso by 1 when outputting.
	outputName := *outputFlag
	if *outputFlag == "" {
		split := strings.Split(*isoFlag, ".")
		outputName = strings.Join(split[0:len(split)-1], ".")
		getNum := regexp.MustCompile("[0-9]{1,}$")
		number := getNum.FindString(outputName)
		num, err := strconv.Atoi(number)
		if err != nil {
			outputName = outputName + "1.iso"
		} else {
			outputName = outputName[0:len(outputName)-len(number)] + strconv.Itoa(num+1) + ".iso"
		}

	}

	if *infiniteFlag {
		fmt.Printf("Set to trigger memory dump every %d frames.\n", *frameFlag)
	} else {
		fmt.Printf("Set to trigger memory dump on frame %d.\n", *frameFlag)
	}

	if *clockFlag <= -1 {
		fmt.Printf("Clock Value unaltered.\n")
	} else {
		fmt.Printf("Clock Value Set to %d\n", *clockFlag)
	}

	fmt.Printf("Input Iso: %s\n", *isoFlag)
	fmt.Printf("Output Iso: %s\n", outputName)

	StartManipulation(*frameFlag, *clockFlag, *infiniteFlag, *isoFlag, outputName, *compFlag)
}

func StartManipulation(frames, clock int, infinite bool, iso, output, gcrLoc string) {

	//extract the files from the iso to a directory.
	rungcr(gcrLoc, iso, "root", "e", "./")

	editor.EditFile("./root/&&systemdata/Start.dol", frames, clock, infinite)

	//recombine the files into a proper structure?
	rungcr(gcrLoc, "./root", output)

}

func rungcr(gcrLoc string, commands ...string) {

	//if gcr is installed.
	if gcrLoc == "" {
		cmd := exec.Command("gcr.exe", commands...)
		err := cmd.Run()

		if err != nil {
			fmt.Println("gcr not installed. Please install gcr (https://gcr.wiimm.de) or set gcr location with -gcr flag. ")
			os.Exit(1)
		}
		return
	}

	//if not installed, try for the base folder/gcr.exe and try base/bin/gcr.exe
	gcrPath := gcrLoc
	if _, err := os.Stat("/path/to/whatever"); !os.IsNotExist(err) {
		cmd := exec.Command(gcrPath, commands...)
		err := cmd.Run()
		if err != nil {
			fmt.Println("gcr set with -gcr flag and gcr.exe detected, however an error has occurred.")
			os.Exit(1)
		}
		return
	}

	gcrPath = gcrLoc + "/gcr.exe"
	if _, err := os.Stat("gcr.exe"); !os.IsNotExist(err) {
		cmd := exec.Command(gcrPath, commands...)
		err := cmd.Run()
		if err != nil {
			fmt.Println("gcr set with -gcr flag and gcr.exe detected, however an error has occurred.")
			os.Exit(1)
		}
		return
	}

	gcrPath = gcrLoc + "/bin/gcr.exe"
	if _, err := os.Stat(""); !os.IsNotExist(err) {
		cmd := exec.Command(gcrPath, commands...)
		err := cmd.Run()
		if err != nil {
			fmt.Println("gcr set with -gcr flag and gcr.exe detected, however an error has occurred.")
			os.Exit(1)
		}
		return
	}

	fmt.Println("gcr set with -gcr flag but gcr.exe was not detected.")
	os.Exit(1)
}
