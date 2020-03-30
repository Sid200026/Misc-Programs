const socket = io();
const name = getQueryVariable('name') || 'Anonymous';
const room = getQueryVariable('room');
//console.log(socket);

console.log(`${name} wants to join ${room}`);
socket.on('connect', () => {

    // setup chat room name
    $(".room-title").html(room);

    console.log("Connected to socket.io server");

    console.log("--- Joining room ---");
    socket.emit('joinRoom', {name, room});
});



// listen for custom event 'message', passed the message received
socket.on('message', (message) => {
    console.log(`New message received: ${message.text}`);

    /*
    comment for testing


    // convert timestamp received from server to moment object
    let timestampMoment = moment.utc(message.timestamp);
    // create a header - name + date
    let messageInfo = `${message.name} ${timestampMoment.local().format('h:mm a')}`;

    let $message = $("<li class='list-group-item'></li>");

    // display message received from server on screen
    // attach timestamp received from server as local time
    $message.append(`<p class="text-info">${messageInfo}</p>`);
    $message.append(`<p>${message.text}</p>`);
    $(".messages").append($message);
    */

    // convert timestamp received from server to moment object
    let timestampMoment = moment.utc(message.timestamp);
    // create a header - name + date
    let user = message.name;
    let time = `<span class="label label-default pull-right">${timestampMoment.local().format('h:mm a')}</span>`;

    let $message = $("<li class='list-group-item'></li>");

    // display message received from server on screen
    // attach timestamp received from server as local time
    $message.append(`<p class="text-info lead">${user}</p>`);
    $message.append(`<p>${message.text} ${time}</p>`);
    $(".messages").append($message);



});

// handle form submission
const $form = $("#message-form");
const $formInp = $form.find('input[name=message]');

$form.on('submit', (e) => {
   e.preventDefault();


   socket.emit('message', {
       name: name,
       text: $formInp.val()
   });

   // reset input
    $formInp.val('');

});