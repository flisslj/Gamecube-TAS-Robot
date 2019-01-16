var fs = require('fs')

function FileConverter(){

    this.convertFile = function(tasfilepath, savefilepath){
        // read in the file
        
        // read header
        // read number of frames (0x15,0x1C 8 bytes total)
        let headerStream = fs.createReadStream(tasfilepath, {start: 0x15, end: 0x1C, encoding: 'hex'});
        let headerString = '0x';
        headerStream.on('readable', ()=> {
            let chunck;
            while(null !== (chunck = headerStream.read())){
                headerString += chunck;
            }
        }).on('end', ()=>{
            let numFrames = parseInt(headerString);
            headerStream.close();
            // set up stream for controller inputs and for writing new file
            let inputStream = fs.createReadStream(tasfilepath, {start: 0x100, encoding: 'hex'});
            let writeStream = fs.createWriteStream(savefilepath, {encoding:'hex'});

            // for each frame
            // write frame number (4 bytes)
            // read inputs (32 bytes, 8 per controller)
            inputStream.on('readable', ()=> {
                let i = 0;
                let chunck;
                while(null !== (chunck = inputStream.read(32))){
                    //let framestring = "0x";

                    let frameNumber = i.toString(16);
                    //writeStream.write(frameNumber);
                    writeStream.write(chunck);
                    i++;
                }
            }).on('end', ()=>{
                writeStream.close();
                inputStream.close();
            });
        });
    }
}