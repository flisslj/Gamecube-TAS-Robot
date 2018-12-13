var fs = require('fs'),
   request = require('request');
/**
 * this class is used for communicating between the application and the hardware
 */

 function HardwareInterface(){
     let url = "localhost";
     let port = "80"
     let secret = "?secret=" + "password1234";
     let api = "";
     
     this.heartBeat = function(){
         api= "/api/Heartbeat";
         var heartbeat;
         request('http://localhost/api/Heartbeat?secret=password1234', function(err, res, body){
            heartbeat = body;
         });
         return heartbeat;
     }
 }
