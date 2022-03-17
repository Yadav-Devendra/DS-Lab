var fs = require('fs');
var data = 'Devendra';
fs.writeFileSync('demo.txt',data);
console.log("file saved using sync");