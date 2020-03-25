const fs = require("fs");
const filename = require("../constants/messages");
const add = (title, description) => {
  fs.open(filename, "a+", (err, fd) => {
    if (err) throw err;
    fs.readFile(filename, (err, data) => {
      if (err) throw err;
      data = data.toString(); // Convert buffer to string
      data = data ? JSON.parse(data) : {};
      data[title] = description;
      fs.writeFile(filename, JSON.stringify(data), err => {
        // Could not use file descriptor as we needed to overwrite the contents
        if (err) throw err;
      });
    });
    fs.close(fd, err => {
      if (err) throw err;
    });
  });
};

module.exports = add;
