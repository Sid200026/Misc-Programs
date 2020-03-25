const fs = require("fs");
const book = {
  title: "Intro to python",
  author: "Siddharth",
  date: "24.07.11",
  price: 900
};

// First we need to write into the file and then read. Either we use synchronous write or call readFile as a callback to writeFile
fs.writeFileSync("1.json", JSON.stringify(book));

fs.readFile("1.json", (err, data) => {
  if (err) throw err;
  const obj = JSON.parse(data);
  console.log(obj);
});
