const { createWriteStream } = require('fs');

const writeStream = createWriteStream('./file.txt');

process.stdin.pipe(writeStream);
