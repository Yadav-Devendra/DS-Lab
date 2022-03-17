var fs = require('fs');
fs.rename('Demo.txt','demo.txt',(err) => {
    if(err){
        console.log(err);
    }else{
        console.log('file renamed');
    }
});
console.log('rename using async');