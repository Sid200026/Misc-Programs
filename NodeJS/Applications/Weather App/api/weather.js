const axios = require("axios");
const key = require("../constants/key");

const getLatLong = async place => {
  const res = await axios.get(
    `https://api.mapbox.com/geocoding/v5/mapbox.places/${place}.json?access_token=${key.mapbox_key}&limit=1&routing=false`
  );
  return res;
};

const getWeather = async (long, lat) => {
  const res = await axios.get(
    `https://api.darksky.net/forecast/${key.darksky_key}/${lat},${long}`
  );
  return res;
};

const weatherInfo = (place, displayfunc) => {
  getLatLong(place)
    .then(res => {
      const long = res.data.features[0].center[0];
      const lat = res.data.features[0].center[1];
      getWeather(long, lat)
        .then(res => displayfunc(place, res.data.hourly.summary))
        .catch(() => {
          console.log("Weather information not available");
        });
    })
    .catch(() => {
      console.log("Place information not available");
    });
};

module.exports = {
  weatherInfo
};
