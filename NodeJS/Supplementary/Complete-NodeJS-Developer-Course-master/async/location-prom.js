/**
 * Created by manishgiri on 2/28/17.
 */
var request = require('request');
function location() {
    return new Promise(function (resolve, reject) {
        request({url: 'http://ipinfo.io', json: true}, function (error, res, body) {
            if (error) {
                reject("Unable to fetch IP location");
            }
            else {
                resolve(body);
            }
        })
    });



}

module.exports = location;
