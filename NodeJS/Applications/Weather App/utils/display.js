const chalk = require("chalk");

const display = (...args) => {
  args.forEach(ele => console.log(chalk.bgBlackBright.whiteBright(ele)));
};

module.exports = {
    display,
}