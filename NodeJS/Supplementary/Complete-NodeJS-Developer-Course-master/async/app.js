/**
 * Created by manishgiri on 2/25/17.
 */
var weather = require('./weather.js');
var location = require('./location');

//use yargs to get user's input
var argv = require('yargs').option("location", {
    alias: "l",
    demand: false,
    describe: "Location to fetch weather for",
    type: "string"
}).help("help").argv;

if(typeof argv.l === "string" && argv.l.length > 0) {
    //user has entered specific location - call weather with this location
    weather(argv.l);
}

else {
    //call weather with user's default location
    //var lat,lon,city;
    location(function (result) {
        var coords = result.loc.split(",");
        var lat = coords[0];
        var lon = coords[1];
        var city = result.city;
        console.log(city);
        weather({lat, lon, city});
    });
}

