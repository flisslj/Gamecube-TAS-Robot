package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
	"strconv"
)

var Port int
var Secret string

func main() {
	PortDesc := `The port to use for the communication.`
	SecretDesc := `The secret key used to make sure that ONLY the controller can send api commands.`

	port := flag.Int("p", 80, PortDesc)
	secret := flag.String("s", "password1234", SecretDesc)

	flag.Parse()

	Port = *port
	Secret = *secret

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

func defaultHandler(w http.ResponseWriter, r *http.Request) {
	http.Redirect(w, r, "/api", http.StatusTemporaryRedirect)
}

//todo turn into a basic help page.
func apiHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hi there. THis is the api handeler., I love %s!", r.URL.Path[1:])

}

func confirmSecret(r *http.Request) bool {
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

	if string(key) == Secret || Secret == "" {
		return true
	}

	//fmt.Fprintf(w, "Invalid Secret, '%s' did not match '%s'.", string(key), Secret)

	return false
}

//http.HandleFunc("/upload", upload)

// upload logic taken from https://astaxie.gitbooks.io/build-web-application-with-golang/en/04.5.html
func upload(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}

	if r.Method == "GET" {
		fmt.Fprintf(w, "Valid Secret! Now do a Post request..")

	} else {
		r.ParseMultipartForm(32 << 20)
		file, handler, err := r.FormFile("uploadfile")
		if err != nil {
			fmt.Println(err)
			return
		}
		defer file.Close()
		fmt.Fprintf(w, "%v", handler.Header)
		f, err := os.OpenFile("./test/"+handler.Filename, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			fmt.Println(err)
			return
		}
		defer f.Close()
		io.Copy(f, file)
	}
}

func Heartbeat(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func GetAttachedHardware(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func GetSDSize(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func OpenSpace(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func GetFiles(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func GetISOs(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func GetTases(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func CurrentISO(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func CurrentTAS(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func SetTas(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func SetISO(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func LoadISO(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func LoadTAS(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func Run(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func Abort(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func GetMemoryDump(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func GetMemoryDumpData(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
func ClearMemoryDump(w http.ResponseWriter, r *http.Request) {
	if !confirmSecret(r) {
		fmt.Fprintf(w, "Invalid Secret.")
		return
	}
}
