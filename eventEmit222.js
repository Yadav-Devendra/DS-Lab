const EventEmitter = require('events');
let eventEmitter = new EventEmitter();

let fun1 = () => {
    console.log('first event called');
};

let fun2 = () => {
    console.log('second event called');
};

eventEmitter.on('first', fun1);
eventEmitter.on('first', fun2);
eventEmitter.emit('first');
eventEmitter.removeListener('first', fun1);
eventEmitter.emit('first');
eventEmitter.removeAllListeners();
eventEmitter.emit('first');

console.log(eventEmitter.getMaxListeners());
console.log(EventEmitter.defaultMaxListeners);

eventEmitter.setMaxListeners(20);

console.log(eventEmitter.getMaxListeners());
console.log(EventEmitter.defaultMaxListeners);

eventEmitter.prependListener('first', fun2);
eventEmitter.emit('first');
console.log(eventEmitter.listeners('first'));
console.log(eventEmitter.listenerCount('first'));

eventEmitter.on('myEvent', (msg) => {
    setImmediate( () => {
        console.log("Message from async: " + msg);
    });
});
var fun = (msg) => {
    console.log("Message from fun: " + msg);
};

eventEmitter.on('myEvent', fun);
eventEmitter.emit('myEvent', "Event occurred");