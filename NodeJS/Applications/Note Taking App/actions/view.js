const fs = require("fs");
const chalk = require("chalk");
const filename = require("../constants/messages");

const view = title => {
  fs.readFile(`${filename}`, (err, data) => {
    if (err) throw err;
    data = data.toString(); // Convert buffer to string
    data = data ? JSON.parse(data) : {};
    if (data[title]) {
      console.log(chalk.bgGreen.red(`TITLE : ${title}`));
      console.log(chalk.bgWhite.red(`DESCRIPTION : ${data[title]}`));
    } else {
      console.log(chalk.bgRed.whiteBright("Error : The title does not exist"));
    }
  });
};

module.exports = view;
