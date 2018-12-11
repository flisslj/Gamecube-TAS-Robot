/**
 * this class is used for communicating between the application and the hardware
 */

 function HardwareInterface (){
     var http = require('http'),
         fs = require('fs');
     let url = "http://" + "localhost";
     let port = "80"
     let secret = "?secret=" + "password1234";
     let request = "";
     
     let heartBeat = function(){
        request = "/api/Heartbeat";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
            var body = '';
            response.on('data', function(d) {
            body += d;
            });
        })
     }

     let getAttachedHardware = function() {
        request = "/api/GetAttachedHardware";
        http.get(url+":"+port+request+secret, (resp)=>{
            // Continuously update stream with data
            var body = '';
            response.on('data', function(d) {
            body += d;
            }); 
        })
     }

     let getSDSize = function() {
        request = "/api/GetSDSize";
        http.get(url+":"+port+request+secret, (resp)=>{
            // Continuously update stream with data
            var body = '';
            response.on('data', function(d) {
            body += d;
            });
        })
     }

     let openSpace = function() {
        request = "/api/OpenSpace";
        http.get(url+":"+port+request+secret, (resp)=>{
            // Continuously update stream with data
            var body = '';
            response.on('data', function(d) {
            body += d;
            });
        })
     }

     let getFiles = function() {
        request = "/api/GetFiles";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

     let getISOs = function() {
        request = "/api/GetISOs";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

     let getTASes = function() {
        request = "/api/GetTASes";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

     let currentISO = function() {
        request = "/api/CurrentIso";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

     let currentTAS = function() {
        request = "/api/CurrentTAS";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }
    
     let setTas = function(filePath){
        request = "/api/SetTas";
        const options = {
           hostname: url,
           port: port,
           path: request+secret,
           method: 'POST',
           headers: {
              'Content-Type': 'TAS-file',
              'Content-Length': ''
           }
        }
        const req = http.request(options, (res) => {

        })
        req.write(fs.readFileSync(filePath));
        req.end()
     }

     let setISO = function(filePath){
        request = "/api/SetISO";
        const options = {
           hostname: url,
           port: port,
           path: request+secret,
           method: 'POST',
           headers: {
              'Content-Type': 'ISO',
              'Content-Length': ''
           }
        }
        const req = http.request(options, (res) => {

        })
        req.write(fs.readFileSync(filePath))
        req.end();
     }

     let loadISO = function(filePath, data){
        request = "/api/LoadISO";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

     let loadTAS = function(filePath, data){
        request = "/api/LoadTAS";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

     let run = function(){
        request = "/api/Run";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

     let abort = function(){
        request = "/api/Abort";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }
     
     let getMemoryDump = function(){
        request = "/api/GetMemoryDump";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }
    
     let getMemoryDumpData = function(){
        request = "/api/GetMemoryDumpData";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }
    
     let clearMemoryDump = function(){
        request = "/api/ClearMemoryDump";
        http.get(url+":"+port+request+secret, (resp)=>{
             // Continuously update stream with data
             var body = '';
             response.on('data', function(d) {
             body += d;
             });
        })
     }

 }