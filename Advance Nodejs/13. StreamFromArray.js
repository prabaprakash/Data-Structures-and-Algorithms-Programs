const { Readable } = require('stream');

const peaks = [
    "Tallac",
    "Ralston",
    "Rubicon",
    "Twin Peaks",
    "Castle Peak",
    "Rose",
    "Freel Peak"
];

class StreamFromArray extends Readable {

    constructor(array) {
      super({ objectMode: true });
      this.array = array;
      this.index = 0;
    }

    _read() {
      if (this.index <= this.array.length) {
        const chunk = {
          data: this.array[this.index],
          index: this.index
        };
        this.push(chunk);
        this.index += 1;
      } else {
        this.push(null);
      }
    }

}

const peakStream = new StreamFromArray(peaks);

peakStream.on('data', (chunk) => console.log(chunk));

peakStream.on('end', () => console.log('done!'));
