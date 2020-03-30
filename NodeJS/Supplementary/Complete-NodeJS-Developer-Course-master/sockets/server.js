// imports
const PORT = process.env.PORT || 3000;
const express = require('express');
const app = express();
const moment = require('moment');
// TODO: read docs on these statements
const http = require('http').Server(app);
const io = require('socket.io')(http);

app.use(express.static(__dirname + '/public'));

let clientInfo = {};

function displayCurrentUsers(socket) {
    // socket is requesting socket
    let info = clientInfo[socket.id];
    let users = [];

    if(!info) {
        return;
    }

    Object.keys(clientInfo).forEach(socketID => {

        // get array of all unique socketIDs in clientInfo object
        let userInfo = clientInfo[socketID];

        // iterate through array and for each object, if room name matches the name of the room the requesting user was in
        // then add this user name to users array
        if(info.room === userInfo.room) {
            users.push(userInfo.name);
        }
    });

    socket.emit('message', {
        name: "The Matrix",
        text: `Current Users: ${users.join(", ")}`,
        at: moment.valueOf()
    });

}


io.on('connection', (socket) => {
    console.log("User connected via Socket.io!");
    console.log("------");

    // emit a custom message on connection from a socket (browser)
    // FIRST system message

    socket.emit('message', {
        name: "The Matrix",
        text: 'Welcome to the chat application!',
        at: moment().valueOf()
    });

    // listen for join room event
    socket.on('joinRoom', req => {

        // set room info for use later (broadcast only to this room)
        clientInfo[socket.id] = req;

        // attach this socket to the specified room
        socket.join(req.room);

        // inform other users of THIS ROOM of new user joining
        socket.broadcast.to(req.room).emit('message', {
            name: "The Matrix",
            text: `${req.name} has joined the room`,
            at: moment.valueOf()
        });

    });


    // listen for custom message from one socket and broadcast to all other sockets
    socket.on('message', message => {
        console.log(`Message received: ${message.text}`);

        // FEATURE: check message text for specific commands

        // /users - display a list of all users
        if(message.text === '/users') {

            displayCurrentUsers(socket);
        }

        else {
            // attach timestamp to received message
            message.at = moment().valueOf();

            // SECOND user message
            // broadcast to everyone but sender
            // NOTE: use io.emit() for sending to sender too

            // send message only to a specific room (get ID from info set earlier while joining room)
            io.to(clientInfo[socket.id].room).emit('message', message);
        }



    });


    // listen for socket disconnection event and exit user from room, if user exists
    socket.on('disconnect', () => {
        const userData = clientInfo[socket.id];
        if(userData) {
            socket.leave(userData.room);
            io.to(userData.room).emit('message', {
                name: "The Matrix",
                text: `${userData.name} has left the room`,
                at: moment.valueOf()
            });

            // delete this user's data
            delete clientInfo[socket.id];
        }
    });

});








http.listen(PORT, () => console.log("Server started"));