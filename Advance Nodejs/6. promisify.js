var { promisify } = require('util');

var delay = (seconds, callback) => {
    if(seconds > 3) {
        callback(new Error('${seconds} seconds it too long!'));
    }
    else {
        setTimeout(()=> callback(null, `the ${seconds} seconds delay is over`),
        seconds
        );
    }
}

var promisifyDelay = promisify(delay);

promisifyDelay(5)
     .then(console.log)
     .catch((error) => console.log(`error: ${error.message}`));
