var fs = require('fs');
fs.readFile('demo.txt',(err, data) => {
    if(err){
        console.log(err);
    }else{
        console.log(data.toString());
    }
});
console.log("Read file using async");