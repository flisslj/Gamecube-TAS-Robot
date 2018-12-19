var fs = require('fs')

function fileConverter(){

    let convertFile = function(filepath){
        // read in the file
        
        // read header
        // read number of frames (0x15,0x1C 8 bytes total)
        let headerStream = fs.createReadStream(filepath, {start: 0x15, end: 0x1C, encoding: 'hex'});
        let headerString = '0x';
        headerStream.on('readable', ()=> {
            let chunck;
            while(null !== (chunck = readable.read())){
                headerString += chunck;
            }
        });
        let numFrames = parseInt(headerString);
        headerStream.close();
        // set up stream for controller inputs and for writing new file
        let inputStream = fs.createReadStream(filepath, {start: 0x100, encoding: 'hex'});
        let writeStream = fs.createWriteStream();

        // for each frame
        for(let i = 0; i < numFrames; i++){
            // write frame number (4 bytes)
            let frameNumber = i.toString(16);
            writeStream.write(frameNumber);
            // read inputs (32 bytes, 8 per controller)
            let inputString = '0x'
            inputStream.on('readable', ()=> {
                let chunck;
                while(null !== (chunck = readable.read(32))){
                    inputString += chunck;
                }
            });
            // write inputs to new file
            writeStream.write(inputString)
        }
        writeStream.close();
        inputStream.close();
    }
}