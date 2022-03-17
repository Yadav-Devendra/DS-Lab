// const myImmediate = setImmediate(() => {
//     console.log("This will execute immidiately")
// });

// setTimeout(() => {
//     console.log("this will execute after 2 seconds")
// }, 2000);

// const myInterval = setInterval(() => {
//     console.log("this will execute after 2 seconds")
// }, 2000);

// setTimeout(() => {
//     clearInterval(myInterval);
// }, 10000);

// clearImmediate(myImmediate);


// setImmediate(() => {
//     console.log("this will execute last");
// }, 1000);



// process.nextTick(() => {
//     console.log("this will execute first");
// }, 1000);


// let count = 0
// var si = setInterval(() =>{
//     count++;
//     console.log("Hello " ,count);
//     if (count == 10) {
//         clearInterval(si);
//     }
// }, 500);

const EventEmitter = require('events');
let eventEmitter = new EventEmitter();

eventEmitter.addListener('firstEvent', () => {
    console.log("first event called!");
});

eventEmitter.removeListener("firstEvent", 
)

eventEmitter.emit("firstEvent");


// // Importing events
// const EventEmitter = require('events');
   
// // Initializing event emitter instances 
// var eventEmitter = new EventEmitter();
  
// // Registering to myEvent 
// eventEmitter.on('myEvent', (msg) => {
//    console.log(msg);
// });
  
// // Triggering myEvent
// eventEmitter.emit('myEvent', "First event");




