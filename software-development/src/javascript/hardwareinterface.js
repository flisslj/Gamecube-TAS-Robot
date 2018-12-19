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
     
     this.heartBeat = function(callback){
         api= "/api/Heartbeat";
         var heartbeat;
         request(url+port+api+secret, function(err, res, body){
            heartbeat = body;
            console.log(heartbeat);
            callback(heartbeat);

         });
     }

     this.getAttachedHardware = function(callback){
        api="api/GetAttachedHardware";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.getSDSize = function(callback){
        api="api/GetSDSize";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.openSpace = function(callback){
        api="api/OpenSpace";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.getFiles = function(callback){
        api="api/GetFiles";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.getISOs = function(callback){
        api="api/GetISOs";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.getTases = function(callback){
        api="api/GetTases";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.currentISO = function(callback){
        api="api/CurrentISO";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
   this.currentTAS = function(callback){
      api="api/CurrentTAS";
      var response;
      request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
      });
      
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
     this.run = function(callback){
        api="api/Run";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.abort = function(callback){
        api="api/Abort";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.getMemoryDump = function(callback){
        api="api/GetMemoryDump";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     this.getMemoryDumpData = function(callback){
        api="api/GetMemoryDumpData";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
   this.clearMemoryDump = function(callback){
      api="api/clearMemorydump";
      var response;
      request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
      });
      
   }     
 }
