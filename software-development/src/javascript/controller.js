
var hardware = new HardwareInterface();
function doHeartBeat(){
   var heartbeat = hardware.heartBeat();
   console.log(heartbeat);
}