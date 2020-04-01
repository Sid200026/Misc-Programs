const express = require("express");
const router = express.Router();
const api = require("../api/weather");

router.route("/:place").get((req, res) => {
  const place = req.params.place; // Sanitize input here
  api
    .getLatLong(place)
    .then(resp => {
      const long = resp.data.features[0].center[0];
      const lat = resp.data.features[0].center[1];
      api
        .getWeather(long, lat)
        .then(resp => {
          res.json({ weather: resp.data.hourly.summary });
        })
        .catch(() => {
          res.json({ error: "Weather information not available" });
        });
    })
    .catch(() => res.json({ error: "Place cannot be found" }));
});

module.exports = router;
