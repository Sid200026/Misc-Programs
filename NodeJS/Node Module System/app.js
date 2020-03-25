// We use the require function to load in other modules
const fs = require('fs');

fs.writeFileSync("hello_world.txt","Hi nice file.\nI am Siddharth");
fs.writeFile("hello_world1.txt","Hi nice file.\nI am Siddharth", err => {
    if (err) {return err;}
    console.log("Operation completed");
});