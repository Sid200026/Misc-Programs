/**
 * Created by manishgiri on 2/25/17.
 */
var request = require('request');
function location(callback) {

    request({url: 'http://ipinfo.io', json: true}, function (error, res, body) {
        if (error) {
            console.log("Unable to fetch IP location");
        }
        else {
            callback(body);
        }
    })


}

module.exports = location;
