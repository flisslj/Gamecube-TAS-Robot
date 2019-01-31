package main

import (
	"bufio"
	//"bytes"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
	"os/exec"
	"strconv"
	"time"
)

var Port int
var Secret string
var Controller string
var Stdin io.WriteCloser
var Stdout io.ReadCloser

func main() {
	PortDesc := `The port to use for the communication.`
	SecretDesc := `The secret key used to make sure that ONLY the controller can send api commands.`
	ControllerDesc := `The location of the controller program to be called. `
	port := flag.Int("p", 8080, PortDesc)
	secret := flag.String("s", "password1234", SecretDesc)
	controller := flag.String("c", "../../controller-dev/src/controller", ControllerDesc)

	flag.Parse()

	Port = *port
	Secret = *secret
	Controller = *controller

	cmd := exec.Command(Controller, "1", "./src")
	stdin, err := cmd.StdinPipe()
	Stdin = stdin
	if err != nil {
		log.Fatal(err)
	}

	stdout, err := cmd.StdoutPipe()
	Stdout = stdout
	if err != nil {
		log.Fatal(err)
	}

	//err = cmd.Start()
	if err != nil {
		fmt.Printf("Program Start errored with error %s.\n", err.Error())
		os.Exit(-1)
	}
	//fmt.Printf("Started program controller. Initing Handler.\n")
	http.HandleFunc("/", defaultHandler)
	http.HandleFunc("/api/", apiHandler)

	http.HandleFunc("/api/Heartbeat/", Heartbeat)
	http.HandleFunc("/api/GetAttachedHardware/", GetAttachedHardware)
	http.HandleFunc("/api/GetSDSize/", GetSDSize)
	http.HandleFunc("/api/OpenSpace/", OpenSpace)
	http.HandleFunc("/api/GetFiles/", GetFiles)
	http.HandleFunc("/api/GetISOs/", GetISOs)
	http.HandleFunc("/api/GetTases/", GetTases)
	http.HandleFunc("/api/CurrentISO/", CurrentISO)
	http.HandleFunc("/api/CurrentTAS/", CurrentTAS)
	http.HandleFunc("/api/SetTas/", SetTas)
	http.HandleFunc("/api/SetISO/", SetISO)
	http.HandleFunc("/api/LoadISO/", LoadISO)
	http.HandleFunc("/api/LoadTAS/", LoadTAS)
	http.HandleFunc("/api/Run/", Run)
	http.HandleFunc("/api/Abort/", Abort)
	http.HandleFunc("/api/GetMemoryDump/", GetMemoryDump)
	http.HandleFunc("/api/GetMemoryDumpData/", GetMemoryDumpData)
	http.HandleFunc("/api/ClearMemoryDump/", ClearMemoryDump)

	log.Fatal(http.ListenAndServe(":"+strconv.Itoa(Port), nil))

}

func confirmSecret(r *http.Request) bool {
	if Secret == "" {
		return true
	}

	keys, ok := r.URL.Query()["secret"]

	if !ok {
		//fmt.Fprintf(w, "Invalid Secret, not ok.")
		return false
	}

	if len(keys[0]) < 1 {
		//fmt.Fprintf(w, "Invalid Secret, keys length less than 1.")
		return false
	}

	// Query()["key"] will return an array of items,
	// we only want the single item.
	key := keys[0]

	if string(key) == Secret {
		return true
	}

	//fmt.Fprintf(w, "Invalid Secret, '%s' did not match '%s'.", string(key), Secret)

	return false
}

//http.HandleFunc("/upload", upload)

// upload logic taken from https://astaxie.gitbooks.io/build-web-application-with-golang/en/04.5.html
func upload(w http.ResponseWriter, r *http.Request, filepath string) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}

	if r.Method == "GET" {
		fmt.Fprintf(w, "Valid Secret! Now do a Post request..")

	} else {
		r.ParseMultipartForm(32 << 20)
		src, _, err := r.FormFile("file")
		if err != nil {
			fmt.Fprintln(w, err)
			return
		}
		defer src.Close()
		dest, err := os.OpenFile(filepath, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			fmt.Fprintln(w, err)
			return
		}
		defer dest.Close()
		io.Copy(dest, src)
	}
}

func runCommand(command string) (response string) {
	//if statement to make the program return a
	if false {
		return command
	}
	fmt.Printf("%s\n", command)
	/*io.WriteString(Stdin, command)
	buf := new(bytes.Buffer)
	*/
	c2 := make(chan string, 1)
	go func() {
		reader := bufio.NewReader(os.Stdin)
		text, _ := reader.ReadString('\n')
		c2 <- text
	}()

	select {
	case newStr := <-c2:
		//newStr := buf.String()
		//fmt.Printf("response: %s\n", newStr)
		return newStr
	case <-time.After(3 * time.Second):
		//fmt.Println("Timeout Triggered.")
		return "Timeout"
	}

	return ""
}

func defaultHandler(w http.ResponseWriter, r *http.Request) {
	http.Redirect(w, r, "/api", http.StatusTemporaryRedirect)
}

//todo turn into a basic help page.
func apiHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hi there. THis is the api handeler., I love %s!", r.URL.Path[1:])

}

func Heartbeat(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("heartbeat:3735936751"))
}
func GetAttachedHardware(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("hardware"))
}
func GetSDSize(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("sdsize"))
}
func OpenSpace(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("sdopen"))
}
func GetFiles(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("getfiles"))
}
func GetISOs(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("getisos"))
}
func GetTases(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("gettases"))
}
func CurrentISO(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("getcurrentiso"))
}
func CurrentTAS(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("getcurrenttas"))
}
func SetTas(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	keys, ok := r.URL.Query()["tasPath"]

	if !ok {
		fmt.Fprintf(w, "Error: Not ok.")
		return
	}

	if len(keys[0]) < 1 {
		fmt.Fprintf(w, "Error: No Value.")
		return
	}

	// Query()["key"] will return an array of items,
	// we only want the single item.
	tasPath := keys[0]
	fmt.Fprintf(w, "%s", runCommand("settas:"+tasPath))

}
func SetISO(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	keys, ok := r.URL.Query()["isoPath"]

	if !ok {
		fmt.Fprintf(w, "Error: Not ok.")
		return
	}

	if len(keys[0]) < 1 {
		fmt.Fprintf(w, "Error: No Value.")
		return
	}

	// Query()["key"] will return an array of items,
	// we only want the single item.
	ISOPath := keys[0]
	fmt.Fprintf(w, "%s", runCommand("setiso:"+ISOPath))

}
func LoadISO(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	keys, ok := r.URL.Query()["filepath"]

	if !ok {
		fmt.Fprintf(w, "Error: Not ok.")
		return
	}

	if len(keys[0]) < 1 {
		fmt.Fprintf(w, "Error: No Value.")
		return
	}

	filepath := keys[0]
	upload(w, r, filepath)
	fmt.Fprintf(w, "%s", runCommand("loadiso:"+filepath))

}
func LoadTAS(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	keys, ok := r.URL.Query()["filepath"]

	if !ok {
		fmt.Fprintf(w, "Error: Not ok.")
		return
	}

	if len(keys[0]) < 1 {
		fmt.Fprintf(w, "Error: No Value.")
		return
	}

	filepath := keys[0]
	upload(w, r, filepath)
	fmt.Fprintf(w, "%s", runCommand("loadtas:"+filepath))

}
func Run(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("run"))
}
func Abort(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("abort"))
}
func GetMemoryDump(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("getmemorydump"))
}
func GetMemoryDumpData(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("getmemorydumpdata"))
}
func ClearMemoryDump(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
	fmt.Fprintf(w, "%s", runCommand("clearmemorydump"))
}
