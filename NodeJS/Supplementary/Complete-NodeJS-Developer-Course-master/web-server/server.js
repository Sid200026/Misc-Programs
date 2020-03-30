/**
 * Created by manishgiri on 2/28/17.
 */

var express = require('express');
var app = express();

/*
app.get('/', function (req, res) {
    res.send("Hello Express");
})
*/

var middleware = {
    requireAuthentication: function (req, res, next) {
        console.log("Private route hit");
        next();
    },
    logger: function (req, res, next) {
        var date = new Date().toDateString();
        console.log("Request: " + req.method + " " + req.originalUrl + " at " + date);
        next();
    }
};


//application level middleware
//app.use(middleware.requireAuthentication);
app.use(middleware.logger);

app.get("/about", middleware.requireAuthentication, function (req, res) {
    res.send("About Me");
});

//console.log(__dirname);
var port = process.env.PORT || 3000;

app.use(express.static(__dirname +"/public"));

app.listen(port, function () {
    console.log("Express server started on port " + port);
});
