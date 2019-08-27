var fs = require('fs');
var { promisify } = require('util');
var writeFile = promisify(fs.writeFile);
var unlink = promisify(fs.unlink);
var readdir = promisify(fs.readdir);
var beep = () => process.stdout.write("\x07");
var delay = (seconds) => new Promise((resolves) => {
    setTimeout(resolves, seconds*1000);
})

async function start() {

  var files = await readdir(__dirname);
  console.log(files);

}

start();
