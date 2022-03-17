var fs = require('fs');
var data = 'devendra yadav';
fs.writeFile('demo.txt',data,(err) => {
    if(err){
        console.log(err);
    }
    console.log('saved using async');
});