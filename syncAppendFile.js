var fs = require('fs');
var data = ' VESIT';
fs.appendFileSync('demo.txt',data);
console.log("append by using sync");