var fs = require('fs');
fs.open('demo.txt','r',(err, data) => {
    if(err){
        console.log(err);
    }else{
        console.log(data);
    }
})