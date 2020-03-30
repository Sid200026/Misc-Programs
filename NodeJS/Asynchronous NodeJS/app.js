console.log("Starting");

setTimeout(() => {
  console.log("Progress");
}, 2000);

setTimeout(() => {
  console.log("About to end");
}, 0);

console.log("Ending");
