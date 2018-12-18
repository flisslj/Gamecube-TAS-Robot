var fs = require('fs'),
   request = require('request');
/**
 * this class is used for communicating between the application and the hardware
 */

 function HardwareInterface(){
     let url = "http://localhost:";
     let port = "80"
     let secret = "?secret=" + "password1234";
     let api = "";
     
     this.heartBeat = function(){
         api= "/api/Heartbeat";
         var heartbeat;
         request(url+port+api+secret, function(err, res, body){
            heartbeat = body;
         });
         return heartbeat;
     }

     this.getAttachedHardware = function(){
        api="api/GetAttachedHardware";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.getSDSize = function(){
        api="api/GetSDSize";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.openSpace = function(){
        api="api/OpenSpace";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.getFiles = function(){
        api="api/GetFiles";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.getISOs = function(){
        api="api/GetISOs";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.getTases = function(){
        api="api/GetTases";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.currentISO = function(){
        api="api/CurrentISO";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
   this.currentTAS = function(){
      api="api/CurrentTAS";
      var response;
      request(url+port+api+secret , function(err, res, body){
            response = body;
      });
      return response;
   }    
   /** post requests needs work
     this.setTAS = function(tasPath){
        api="api/SetTAS";
        request(url+port+api+secret , function(err, res, body){

        })
     }
     this.setISO = function(tasPath){
        api="api/SetISO";
        request(url+port+api+secret , function(err, res, body){

        })
     }
     this.loadISO = function(filePath, data){
        api="api/";
        request(url+port+api+secret , function(err, res, body){

        })
     }
     this.loadTAS = function(filePath, data){
        api="api/";
        request(url+port+api+secret , function(err, res, body){

        })
     }

     **/
     this.run = function(){
        api="api/Run";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.abort = function(){
        api="api/Abort";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.getMemoryDump = function(){
        api="api/GetMemoryDump";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
     this.getMemoryDumpData = function(){
        api="api/GetMemoryDumpData";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
        });
        return response;
     }
   this.clearMemoryDump = function(){
      api="api/clearMemorydump";
      var response;
      request(url+port+api+secret , function(err, res, body){
            response = body;
      });
      return response;
   }     
 }
