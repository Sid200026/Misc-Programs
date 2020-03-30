/**
 * Created by manishgiri on 7/2/17.
 */

const Sequelize = require('sequelize');
const sequelize = new Sequelize(undefined, undefined, undefined, {
    'dialect': 'sqlite',
    'storage': __dirname + '/sql-db.sqlite'
});

let Todo = sequelize.define('todo', {
    description: {
        type: Sequelize.STRING,
        allowNull: false,
        validate: {
            len: [1, 20]
        }
    },
    completed: {
        type: Sequelize.BOOLEAN,
        allowNull: false,
        defaultValue: false
    }
});

sequelize.sync({force: true}).then(function () {
    console.log("Everything is synced.");

    Todo.create({
        description: "Take out trash",
        // completed: false
    }).then(function (todo) {
        //console.log("Finished");
        // console.log(todo);
        return Todo.create({
            description: "Clean Office"
        });
    }).then(function () {
        // return Todo.findById(1)
        return Todo.findAll({
            // completed: false
            where: {
                description: {
                    $like: '%office%'
                }
            }
        })
    }).then(function (todos) {
          if(todos) {
              // console.log(todo.toJSON());
              todos.forEach(todo => console.log(todo.toJSON()));
          }
          else {
              console.log("No Todo found.");
          }
    }).catch(function (error) {
        console.log(error);
    })
});

