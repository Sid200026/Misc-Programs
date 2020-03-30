/**
 * Created by manishgiri on 2/28/17.
 */
//weather app done with promises instead of callback
/**
 * Created by manishgiri on 2/24/17.
 */
var request = require('request');

//var url = "http://api.openweathermap.org/data/2.5/weather?q=London,uk&appid=72c269f82f1a47216a1106cd04e0f37a";
//var url = "http://api.openweathermap.org/data/2.5/weather?q=London,uk&appid=ae0acb60e8db4952e081c2fb470a1b23";

function weather(location) {
    return new Promise(function (resolve, reject) {


        if(typeof location !== "string") {
            var lat = location.lat;
            var lon = location.lon;
            var city = location.city;
            //console.log(lat);
            var url = "http://api.openweathermap.org/data/2.5/weather?lat="+lat+"&lon="+lon+"&units=metric&appid=ae0acb60e8db4952e081c2fb470a1b23";
            request({
                url: url,
                json: true
            }, function (error, res, result1) {
                if (error) {
                    reject("Unable to fetch weather");
                }
                else {
                    resolve(result1);
                    //console.log("It's " + result1.main.temp + " degrees Celsius in " + city);
                }

            })
        }
        else {
            //a city is passed in
            var encodedLocation = encodeURI(location);
            url = "http://api.openweathermap.org/data/2.5/weather?q="+encodedLocation+"&units=metric&appid=ae0acb60e8db4952e081c2fb470a1b23";
            request({url: url, json: true}, function (error, res, result2) {
                if (error) {
                    reject("Unable to fetch IP location");
                    //console.log("Unable to fetch IP location");
                }
                else {
                    resolve(result2)
                    //console.log("It's " + result2.main.temp + " degrees Celsius in " + location);

                }

            });
        }

    });


}

module.exports = weather;
