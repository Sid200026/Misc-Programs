const express = require('express');
const router = express.Router();
const productController = require('../controller/productController');
const joiSchemaValidation = require('../middleware/joiSchemaValidation');
const productSchema = require('../apiSchema/productSchema');
const tokenValidation = require('../middleware/tokenValidation');

//add an entry int0 the database
router.post('/', 
tokenValidation.validateToken, 
joiSchemaValidation.validateBody(productSchema.createProductSchema), 
productController.createProduct);

//get an entry from database based on id of product
router.get('/:id',
tokenValidation.validateToken, 
productController.getProductById 
)

//update or add info to product via its id
router.put('/:id',
tokenValidation.validateToken, 
joiSchemaValidation.validateBody(productSchema.updateProductSchema),
productController.updateProduct
)

//get all entries in the database
router.get('/',
tokenValidation.validateToken, 
joiSchemaValidation.validateQueryParams(productSchema.getAllProductSchema),
productController.getAllProducts)

router.delete('/:id',
tokenValidation.validateToken, 
productController.deleteProduct
)

module.exports = router;