const path = require("path");
const express = require("express");
const app = express();

// www.google.com
// www.google.com/about
// www.google.com/contact

app.get("", (_req, res) => {
  // req contains information about the request ; res contains a bunch of methods which determine what we send back to the requestor
  res.send("Homepage");
});
app.get("/about", (_req, res) => {
  res.send("About Us");
});
app.get("/contact", (_req, res) => {
  res.send("Contact Me");
});
app.get("/profile", (_req, res) => {
  res.send("Profile, Page");
});
app.get("/help", (_req, res) => {
  res.send("Help Page");
});
app.get("/static", (_req, res) => {
  res.send("<h1>Hi</h1>"); // We can also send html via express ie. we can serve static files via express
});
app.get("/json", (_req, res) => {
  res.send(["hi", "one"]); // If we pass an array or an object as a parameter to send, then it is converted into json
});
app.get("/api/weather", (_req, res) => {
  res.send({ weather: "Brilliant" });
});

const current_directory = __dirname

app.use("/webpage", express.static(path.join(current_directory, "public")))

// To start the server

// The callback function is optional and is displayed when the server is up and running
app.listen(3000, () => console.log("Listening on port 3000"));

console.log("Starting"); // This is displayed first since the above process is asynchronous
