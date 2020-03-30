/**
 * Created by manishgiri on 7/3/17.
 */
const Sequelize = require('sequelize');
const sequelize = new Sequelize(undefined, undefined, undefined, {
    'dialect': 'sqlite',
    'storage': __dirname + '/data/dev-todo-api.sqlite'
});

let db = {};
db.todo = sequelize.import(__dirname + '/models/todo.js');
db.sequelize = sequelize;
db.Sequelize = Sequelize;

// export the db object
module.exports = db;
