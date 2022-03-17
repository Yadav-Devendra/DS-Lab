var fs = require('fs');
var data = fs.readFileSync('demo.txt');
console.log(data.toString());
console.log("Reading file using sync");