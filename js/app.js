const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

let currentData = { leftIR: 0, middleIR: 0, rightIR: 0 };

const port = new SerialPort({
   path: '/dev/ttyACM0',
   baudRate: 9600
});

const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

port.on("open", () => {
  console.log('serial port open');
});

parser.on('data', data => {
  try {
     const { leftIR, middleIR, rightIR } = JSON.parse(data);
     [currentData.leftIR, currentData.middleIR, currentData.rightIR] = [leftIR, middleIR, rightIR];
     
     console.log("data", currentData);
  }catch(err) {
     console.log("error with data", err);
  }
});
