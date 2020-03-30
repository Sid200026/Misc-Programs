const api = require("./api/weather");
const utils = require("./utils/display");
const express = require("express");
const app = express();
const port = 3000;

api.weatherInfo("Beijing", utils.display);

app.get("", (req, res) => {
  res.send("Welcome to Weather App");
});
app.get("/weather", (req, res) => {
  res.send("Weather route");
});

app.listen(port, () => console.log(`Listening on port ${port}`));
