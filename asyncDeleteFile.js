var fs = require('fs');
fs.unlink('demo.txt',(err) => {
    if(err){
        console.log(err);
    }else{
        console.log('deleted');
    }
});
console.log('delete using async');