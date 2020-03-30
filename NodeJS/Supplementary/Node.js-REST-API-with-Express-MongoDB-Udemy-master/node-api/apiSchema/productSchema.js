const Joi = require('@hapi/joi');

module.exports.createProductSchema = Joi.object().keys({
    name: Joi.string().required(), //make sure name is compulsorily there
    price: Joi.number().required(),
    brand: Joi.string().required()
});

module.exports.getAllProductSchema = Joi.object().keys({
    skip: Joi.string(),
    limit: Joi.string()
});

module.exports.updateProductSchema = Joi.object().keys({
    name: Joi.string(),
    price: Joi.number(),
    brand: Joi.string()
});