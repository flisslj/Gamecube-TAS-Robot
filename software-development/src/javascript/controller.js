
var app = require('electron').remote;
var dialog = app.dialog;
var fs = require('fs');
var hardware = new HardwareInterface();
var fileconverter = new FileConverter();
var currentISO = "";
var currentTAS = "";
var convertedTAS = "";
var currentProject = "";
var framesDebugged = 0;

function newProject(){
   var selectedTAS = dialog.showOpenDialog({
      title:"Select the TAS you're running",
      filters: [{name: 'TAS files', extensions: ['dtm']}]
   });

   currentTAS = selectedTAS[0];

  selectedISO = dialog.showOpenDialog({
      title:"Select the ISO for your TAS",
      filters: [{name: 'ISOs', extensions: ['iso', 'gcm']}]
   });

   currentISO = selectedISO[0];

   convertedTAS = dialog.showSaveDialog({
      title:"Save the converted TAS file",
      defaultPath: "EnterTasNameHere",
      filters: [{name: "GCTAS files", extensions: ['gctas']}]
   });
   fileconverter.convertFile(currentTAS, convertedTAS);
   
   dialog.showSaveDialog({
      title:"Save the project file",
      defaultPath: "EnterProjectNameHere",
      filters: [{name: "GCProject files", extensions: ['gcproj']}]
   }, (filePath) =>{
      currentProject = filePath
      var writeStream = fs.createWriteStream(filePath);
      /**
       * project file format:
       *    tas filepath
       *    converted tas filepath
       *    iso filepath
       *    debug complete?
       *    frames debugged
       */
      writeStream.write(currentTAS + "\n");
      writeStream.write(convertedTAS + "\n");
      writeStream.write(currentISO + "\n");
      writeStream.write("false\n");
      writeStream.write("0\n");
      writeStream.close();
   });

   /**
    * really don't feel like installing jQuery or Angular
    */
   document.getElementById("project_name").innerHTML = currentProject;
   document.getElementById("iso_name").innerHTML = currentISO;
   document.getElementById("tas_name").innerHTML = currentTAS;
}

function openProject(){
   selectedProject = dialog.showOpenDialog({
      title:"Open an existing project",
      filters: [{name: "GCProject files", extensions: ['gcproj']}]
   });

   currentProject = selectedProject[0];

   var project = fs.readFileSync(currentProject, 'utf8')
   var split = project.split("\n");
   currentTAS = split[0];
   convertedTAS = split[1];
   currentISO = split[2];
   framesDebugged = parseInt(split[4]);

   document.getElementById("project_name").innerHTML = currentProject;
   document.getElementById("iso_name").innerHTML = currentISO;
   document.getElementById("tas_name").innerHTML = currentTAS;

}

function saveProject(){
   var writeStream = fs.createWriteStream(currentProject);
   writeStream.write(currentTAS + "\n");
   writeStream.write(convertedTAS + "\n");
   writeStream.write(currentISO + "\n");
   writeStream.write("false\n");
   writeStream.write(framesDebugged + "\n");
   writeStream.close();
}

function loadProject(){
   /**
    * check if iso and tas are already on the device
    */
   //hardware.currentISO(logStuff);
   //hardware.currentTAS(logstuff);
   /**
    * load tas and iso to device
    */
   hardware.loadTAS(convertedTAS, logStuff);
   hardware.loadISO(currentISO, logStuff);
   /**
    * set iso and tas
    */
   hardware.setTAS(convertedTAS, logStuff);
   hardware.setISO(currentISO, logStuff);

}

function runTAS(){
   hardware.run(logStuff);
}

function stopTAS(){
   hardware.abort(logStuff);
}

function doHeartBeat(){
   var  log = logStuff;
   var heartbeat = hardware.getAttachedHardware(log);
}

function logStuff(stuff){
   console.log(stuff);
}