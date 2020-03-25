const fs = require("fs");

fs.appendFile(
  "hello_world.txt",
  "\nThis will start from the next line",
  err => {
    if (err) {
      throw err;
    } else {
        console.log("Message written successfully");
    }
  }
);
