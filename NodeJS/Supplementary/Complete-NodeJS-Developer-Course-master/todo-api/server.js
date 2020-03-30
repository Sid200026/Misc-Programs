/**
 * Created by manishgiri on 4/11/17.
 */
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var port = process.env.PORT || 3000;
var todoNextID = 1;
var _ = require("underscore");
var db = require("./db.js");


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
    let filteredTodos = todos;

    if (queryParams.hasOwnProperty("completed")) {
        if (queryParams.completed === "true") {
            filteredTodos = _.where(filteredTodos, {
                completed: true
            });
        } else if (queryParams.completed === "false") {
            filteredTodos = _.where(filteredTodos, {
                completed: false
            });
        }
    }

    if (queryParams.hasOwnProperty("q") && queryParams.q.length > 0) {
        let searchItem = queryParams.q.toLowerCase();
        filteredTodos = _.filter(filteredTodos, function (todo) {
            return todo.description.toLowerCase().indexOf(searchItem) >= 0;
        })

    }
    res.json(filteredTodos);
});

/**
 * GET REQUEST -
 * GET /todos/:id
 */
app.get('/todos/:id', function (req, res) {
    var todoID = parseInt(req.params.id);
    db.todo.findById(todoID).then(todo => {
        todo ? res.json(todo) : res.status(404).send();
    }, e => {
        // problem with server
        res.status(500).send();
    })
})

app.get('/', function (req, res) {
    res.send("Todo API Root");
});


/**
 * POST todos to /todos
 */
app.post('/todos', function (req, res) {
    var body = _.pick(req.body, "description", "completed");

    // if (!_.isBoolean(body.completed) || !_.isString(body.description) || !body.description.trim().length) {
    //     // bad data was sent
    //     return res.status(400).send();
    // }

    

    db.todo.create(body).then(todo => {
        res.json(todo.toJSON());
    }, e => {
        res.status(400).json(e);
    })

    // body.description = body.description.trim();
    // body.id = todoNextID++;
    // //push body into array
    // todos.push(body);
    // res.json(body);
});

/**
 * DELETE a todo with ID
 */

app.delete('/todos/:id', function (req, res) {
    let toDeleteID = parseInt(req.params.id);
    let matchedTodo = _.findWhere(todos, {
        id: toDeleteID
    });
    if (!matchedTodo) {
        res.status(404).json({
            "error": "No TODO found with that ID"
        });
    } else {
        todos = _.without(todos, matchedTodo);
        res.json(matchedTodo);
    }

});

/**
 * UPDATE a todo with an ID
 */

app.put('/todos/:id', function (req, res) {
    let body = _.pick(req.body, "description", "completed");
    let toUpdateID = parseInt(req.params.id);
    let matchedTodo = _.findWhere(todos, {
        id: toUpdateID
    });

    // object to store validated fields
    var validatedAttributes = {};
    if (!matchedTodo) {
        return res.status(404).send();
    }
    if (body.hasOwnProperty("completed") && _.isBoolean(body.completed)) {
        validatedAttributes.completed = body.completed;
    } else if (body.hasOwnProperty("completed")) {
        // completed property exists but is not boolean
        return res.status(400).send();
    }


    // validation for passed in body.description property
    if (body.hasOwnProperty("description") && _.isString(body.description)) {
        validatedAttributes.description = body.description;
    } else if (body.hasOwnProperty("description")) {
        // completed property exists but is not boolean
        return res.status(400).send();
    }

    // use _.extend to get updated todo - this will update matchedTodo in place too
    _.extend(matchedTodo, validatedAttributes);

    res.json(matchedTodo);
});

db.sequelize.sync().then(() => {
    app.listen(port, function () {
        console.log("Express listening on port " + port);
    });
});
