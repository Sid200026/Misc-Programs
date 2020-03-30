/**
 * Created by manishgiri on 2/28/17.
 */
var weather = require('./weather-prom.js');
var location = require('./location-prom');

//use yargs to get user's input
var argv = require('yargs').option("location", {
    alias: "l",
    demand: false,
    describe: "Location to fetch weather for",
    type: "string"
}).help("help").argv;

if(typeof argv.l === "string" && argv.l.length > 0) {
    //user has entered specific location - call weather with this location
    weather(argv.l).then(function (res) {
        var temp = res.main.temp;
        var city = res.name;
        return {temp, city};
        //console.log(res);
    }).then(function (resObj) {
        console.log(`It's ${resObj.temp} degrees Celsius in ${resObj.city}`);
    }).catch(function (err) {
        console.log(err);
    });
}

else {
    //call weather with user's default location
    //var lat,lon,city;
    location().then(function (result) {
        var coords = result.loc.split(",");
        var lat = coords[0];
        var lon = coords[1];
        var city = result.city;
        return weather({lat, lon, city});
    }).then(function (res) {
        console.log(`It's ${res.main.temp} degrees Celsius in ${res.name}`);
        //console.log(res);
    }).catch(function (err) {
        console.log(err);
    });

}
