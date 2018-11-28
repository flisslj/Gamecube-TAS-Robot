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
	http.HandleFunc("/api/upload/", upload)
	log.Fatal(http.ListenAndServe(":"+strconv.Itoa(Port), nil))

}

func defaultHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Default Response. You are talking to the pi. Congratulations")
}

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
		return
	}
	fmt.Println("method:", r.Method)
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
