
var hardware = new HardwareInterface();
function doHeartBeat(){
   var  log = logShit;
   var heartbeat = hardware.getAttachedHardware(log);
}

function logShit(shit){
   console.log(shit);
}