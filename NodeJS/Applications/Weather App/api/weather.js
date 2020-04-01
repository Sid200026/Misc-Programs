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

module.exports = {
  getLatLong,
  getWeather
};
