/**
 * this class is used for communicating between the application and the hardware
 */

 function HardwareInterface (){
     var http = require('http');
     let url = "http://" + "localhost:";
     let port = "80"
     let secret = "&secret=" + "password1234";
     let request;
     
     let heartBeat = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let getAttachedHardware = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let getSDSize = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let openSpace = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let getFiles = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let getISOs = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let getTASes = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let currentISO = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let currentTAS = function() {
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }
    
     let setTas = function(){
        request = "";
        //these need to be post requests
     }

     let setISO = function(){
        request = "";
        //these need to be post requests
     }

     let loadISO = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let loadTAS = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let run = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

     let abort = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }
     
     let getMemoryDump = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }
    
     let getMemoryDumpData = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }
    
     let clearMemoryDump = function(){
        request = "";
        http.get(url+port+request+parameters+secret, (resp)=>{

        })
     }

 }