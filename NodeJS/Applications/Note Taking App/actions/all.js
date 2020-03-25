const fs = require("fs");
const chalk = require("chalk");
const filename = require("../constants/messages");

const all = () => {
  fs.readFile(`${filename}`, (err, data) => {
    if (err) throw err;
    data = data.toString(); // Convert buffer to string
    data = data ? JSON.parse(data) : {};
    for(title in data) {
        console.log(chalk.bgGreen.red(`TITLE : ${title}`));
        console.log(chalk.bgWhite.red(`DESCRIPTION : ${data[title]}\n`));
    }
  });
};

module.exports = all;
