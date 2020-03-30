const mongoose = require('mongoose');

const productSchema = new mongoose.Schema({
    name: String,
    price: Number,
    brand: String
}, {
    timestamps: true,
    // this transforms _id to id and removes __v field from database.
    //It doesn't delete it from original db, only when the client/user sees the data, _id is replaced by id
    toObject: {
        transform: function(doc, ret, options) {
            ret.id=ret._id;
            delete ret._id;
            delete ret.__v;
            return ret;
        }
    }
});

module.exports = mongoose.model('Product', productSchema);