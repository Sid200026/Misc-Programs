const fs = require("fs");
const chalk = require("chalk");
const filename = require("../constants/messages");

const rm = title => {
  fs.readFile(`${filename}`, (err, data) => {
    if (err) throw err;
    data = data.toString(); // Convert buffer to string
    data = data ? JSON.parse(data) : {};
    if (data[title]) {
      delete data[title];
      fs.writeFile(`${filename}`, JSON.stringify(data), err => {
        if (err) throw err;
        console.log(chalk.bgGreen.red("Deleted successfulyy"));
      });
    } else {
      console.log(chalk.bgRed.whiteBright("Error : The title does not exist"));
    }
  });
};

module.exports = rm;
