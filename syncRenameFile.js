var fs = require('fs');
fs.renameSync('demo.txt','Demo.txt');
console.log('File renamed by using sync');