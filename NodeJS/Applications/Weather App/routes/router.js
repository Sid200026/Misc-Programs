const express = require("express");
const chalk = require("chalk");
const router = express.Router();
const api = require("../api/weather");
const bodyParser = require("body-parser");
const axios = require("axios");

router.use(bodyParser.urlencoded({ extended: true }));

router
  .route("/")
  .get((_req, res) => {
    res.render("homepage", (err, html) => {
      if (err) {
        console.log(chalk.red("Error occured while fetching"));
        res.send("Sorry please try again");
      }
      res.send(html);
    });
  })
  .post((req, res) => {
    // api.getLatLong(req.body.place).then(resp => {
    //   const long = resp.data.features[0].center[0];
    //   const lat = resp.data.features[0].center[1];
    //   api
    //     .getWeather(long, lat)
    //     .then(resp => {
    //       res.render(
    //         "homepage",
    //         { weather: resp.data.hourly.summary },
    //         (err, html) => {
    //           if (err) {
    //             console.log(chalk.red("Error occured"));
    //             res.send("Sorry please try again");
    //           }
    //           res.send(html);
    //         }
    //       );
    //     })
    //     .catch(() => {
    //       console.log("Weather information not available");
    //     });
    // });
    axios.get(`http://127.0.0.1:3000/api/${req.body.place}`).then(response => {
      console.log(response.data)
      if (response.data.error) {
        res.send(response.data.error);
      }
      res.render(
        "homepage",
        { weather: response.data.weather},
        (err, html) => {
          if (err) {
            console.log(chalk.red("Error occured"));
            res.send("Sorry please try again");
          }
          res.send(html);
        }
      );
    }).catch(() => res.send("Error occured"));
  });

module.exports = router;
