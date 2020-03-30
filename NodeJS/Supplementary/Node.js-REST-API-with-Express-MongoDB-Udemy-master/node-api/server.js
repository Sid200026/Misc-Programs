const express = require('express');
const dotEnv = require('dotenv');
const cors = require('cors');
const swaggerUi = require('swagger-ui-express');
const YAML = require('yamljs');
const swaggerDocument = YAML.load('./swagger.yaml');
const dbConnection = require('./database/connection');

dotEnv.config();

const app = express();

//DB connectivity
dbConnection();

// cors implementation for handling cross domain error
app.use(cors());

//request payload middleware
app.use(express.json());
app.use(express.urlencoded({extended: true}));

app.use('/api/v1/product', require('./routes/productRoutes'));
app.use('/api/v1/user', require('./routes/userRoutes'));

//API Documentation
if (process.env.NODE_ENV != 'production') {
    app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));
}

app.get('/', (req,res,next) => {
    res.send('Hello from Node api Server')
})

const PORT = process.env.PORT || 3000;

app.listen(PORT,() => {
    console.log(`Server listening on port ${PORT}`);
});

//error handling middleware
app.use(function (err, req, res, next) {
    console.error(err.stack)
    res.status(500).send({
        status: 500,
        message: err.message,
        body: {}
    });
  })