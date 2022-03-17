var fs = require('fs');
var data = ' VESIT';
fs.appendFile('demo.txt', data,(err) => {
    if(err){
        console.log(err);
    }else{
        console.log('saved');
    }
});
console.log('file append using async');