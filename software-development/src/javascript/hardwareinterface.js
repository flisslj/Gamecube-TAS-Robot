var fs = require('fs'),
   request = require('request');
/**
 * this class is used for communicating between the application and the hardware
 * over ethernet / wifi
 */

 function HardwareInterface(){
     let url = "http://localhost:";
     let port = "80"
     let secret = "?secret=" + "password1234";
     let api = "";
     
     /**
      * checks the connection between the controller and application
      * @param callback function for handeling returned data
      */
     this.heartBeat = function(callback){
         api= "/api/Heartbeat";
         var heartbeat;
         request(url+port+api+secret, function(err, res, body){
            heartbeat = body;
            console.log(heartbeat);
            callback(heartbeat);

         });
     }
     /**
      * checks what hardware components are attached to the controller
      * gives version numbers and size of sd card if attached
      */
     this.getAttachedHardware = function(callback){
        api="/api/GetAttachedHardware";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
     }
     /**
      * check the current size of the sd card
      */
     this.getSDSize = function(callback){
        api="/api/GetSDSize";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     /**
      * checks how much space is open on the sd card
      */
     this.openSpace = function(callback){
        api="/api/OpenSpace";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }

     /**
      * get which files are currently on the sd card
      * including both replay files and isos
      */
     this.getFiles = function(callback){
        api="/api/GetFiles";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }

     /**
      * find out what isos are currently loaded onto the sd card
      */
     this.getISOs = function(callback){
        api="/api/GetISOs";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }

     /**
      * find out which replay files are loaded onto the sd card
      */
     this.getTases = function(callback){
        api="/api/GetTases";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }

     /**
      * find out which iso will be launched on the gamecube
      * when a replay is run
      */
     this.currentISO = function(callback){
        api="/api/CurrentISO";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     /**
      * find out which replay file will be read when a replay is
      * launched
      */
   this.currentTAS = function(callback){
      api="/api/CurrentTAS";
      var response;
      request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
      });
      
   }    
   /** post requests needs work
     this.setTAS = function(tasPath){
        api="/api/SetTAS";
        request(url+port+api+secret , function(err, res, body){

        })
     }
     this.setISO = function(tasPath){
        api="/api/SetISO";
        request(url+port+api+secret , function(err, res, body){

        })
     }
     this.loadISO = function(filePath, data){
        api="/api/";
        request(url+port+api+secret , function(err, res, body){

        })
     }
     this.loadTAS = function(filePath, data){
        api="/api/";
        request(url+port+api+secret , function(err, res, body){

        })
     }

     **/

     /**
      * run a replay using the currently loaded replay file and 
      * iso
      */
     this.run = function(callback){
        api="/api/Run";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }

     /**
      * interrupt a currently running replay
      */
     this.abort = function(callback){
        api="/api/Abort";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }
     /**
      * get the next memory dump to be loaded from the gamecube 
      */
     this.getMemoryDump = function(callback){
        api="/api/GetMemoryDump";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }

     /**
      * get technical information on the next memory dump to be loaded
      */
     this.getMemoryDumpData = function(callback){
        api="/api/GetMemoryDumpData";
        var response;
        request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
        });
        
     }

     /**
      * clear all memory dumps waited to be recieved
      */
   this.clearMemoryDump = function(callback){
      api="/api/clearMemorydump";
      var response;
      request(url+port+api+secret , function(err, res, body){
            response = body;
            callback(response)
      });
      
   }     
 }
