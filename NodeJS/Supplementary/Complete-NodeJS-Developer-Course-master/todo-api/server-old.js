// backup of old server.js - without DB
/**
 * Created by manishgiri on 4/11/17.
 */
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var port = process.env.PORT || 3000;
var todoNextID = 1;
var _ = require("underscore");
var db = require("db.js");

//TODOS - collection of todoitems - todo is the model
// var todos = [
//     {
//         id: 1,
//         description: "Meet mom for lunch",
//         completed: false
//     },
//     {
//         id: 2,
//         description: "go to market",
//         completed: false
//     },
//     {
//         id: 3,
//         description: "Learn node",
//         completed: true
//     }
//
// ]

var todos = [];

app.use(bodyParser.json());

/**
 * GET REQUESTS -
 * all todos - GET /todos
 * individual todo  - GET /todos/:id
 */

app.get('/todos', function (req, res) {
    // a query param is all K-V pairs after the ?, like GET /todos?completed=true
    // get the query params obj
    let queryParams = req.query;
    // todos that will be filtered
    let filteredTodos = todos;

    // a search param will look like GET /todos?completed=true&q=work, search for "work"

    // check if completed was used in query params
    if(queryParams.hasOwnProperty("completed")) {
        // if value was true (note - string, not boolean)
        if(queryParams.completed === "true") {
            // return all todos with completed set to true
            filteredTodos = _.where(filteredTodos, {completed: true});
        }
        else if (queryParams.completed === "false") {
            // return all todos with completed to false
            filteredTodos = _.where(filteredTodos, {completed: false});
        }
    }

    // use filter and indexOf to return todos whose description contains the searched text
    if(queryParams.hasOwnProperty("q") && queryParams.q.length > 0) {
        let searchItem = queryParams.q.toLowerCase();

        filteredTodos = _.filter(filteredTodos, function (todo) {
            return todo.description.toLowerCase().indexOf(searchItem) >= 0;
        })

    }

    // return filtered todos
    res.json(filteredTodos);
});

app.get('/todos/:id', function (req, res) {
    var todoID = parseInt(req.params.id);

    // use Underscore's findWhere
    var todoItem = _.findWhere(todos, {id: todoID});
    if(!todoItem) {
        res.status(404).send();
    }
    else {
        res.json(todoItem);
    }
})

app.get('/', function (req, res) {
    res.send("Todo API Root");
});


/**
 * POST todos to /todos
 */
app.post('/todos', function (req, res) {
    var body = req.body;

    if(!_.isBoolean(body.completed) || !_.isString(body.description) || !body.description.trim().length) {
        // bad data was sent
        return res.status(400).send();
    }

    // use .pick() to filter out whitelist data - remove unnecessary fields
    body = _.pick(body, "description", "completed");

    // use trim to remove spaces from description
    body.description = body.description.trim();

    //add ID field
    body.id = todoNextID++;

    //push body into array
    todos.push(body);

    // console.log("description = " + body.toString());
    res.json(body);
});

/**
 * DELETE a todo with ID
 */

app.delete('/todos/:id', function (req, res) {
    let toDeleteID = parseInt(req.params.id);

    // get todo ITEM to be removed
    // let deletedTodo = todos[toDeleteID];
    let matchedTodo = _.findWhere(todos, {id: toDeleteID});

    // if ID not found
    if(!matchedTodo) {
        //send error response
        res.status(404).json({"error": "No TODO found with that ID"});
    }

    else {
        // use .without() from underscore to return filtered todo array
        todos = _.without(todos, matchedTodo);
        res.json(matchedTodo);
    }

});

/**
 * UPDATE a todo with an ID
 */

app.put('/todos/:id', function (req, res) {
    // filter unnecessary fields from request
    let body = _.pick(req.body, "description", "completed");
    let toUpdateID = parseInt(req.params.id);

    // get todo ITEM to be updated
    // NOTE : Does this return a reference to the matched item from the todos array?
    let matchedTodo = _.findWhere(todos, {id: toUpdateID});

    // object to store validated fields
    var validatedAttributes = {};

    // if no matched todo
    if(!matchedTodo) {
        // using RETURN ensures following code won't execute
        // 404 = not found, 400 = bad request
        return res.status(404).send();
    }
    // validation for passed in body.completed property
    if(body.hasOwnProperty("completed") && _.isBoolean(body.completed)) {
        validatedAttributes.completed = body.completed;
    }
    else if(body.hasOwnProperty("completed")) {
        // completed property exists but is not boolean
        return res.status(400).send();
    }


    // validation for passed in body.description property
    if(body.hasOwnProperty("description") && _.isString(body.description)) {
        validatedAttributes.description = body.description;
    }
    else if(body.hasOwnProperty("description")) {
        // completed property exists but is not boolean
        return res.status(400).send();
    }

    // use _.extend to get updated todo - this will update matchedTodo in place too
    _.extend(matchedTodo, validatedAttributes);

    res.json(matchedTodo);
});

    app.listen(port, function () {
        console.log("Express listening on port " + port);
    });



