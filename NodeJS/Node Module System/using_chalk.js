const chalk = require('chalk')

const success = chalk.bold.green;
const error = chalk.bold.red;

console.log(success.inverse('Success'));
console.log(error.inverse("Error"));