const constants = require('../constants');
const mongoose = require('mongoose');

mongoose.set('useNewUrlParser', true);
mongoose.set('useFindAndModify', false);
mongoose.set('useCreateIndex', true);
mongoose.set('useUnifiedTopology', true);

module.exports.formatMongoData = (data) => {
    if (Array.isArray(data)) {
        let newDataList = [];
        for (value of data) {
            newDataList.push(value.toObject());
        }
        return newDataList;
    }
    return data.toObject();
}

module.exports.checkObjectId = (id) => {
    if (!mongoose.Types.ObjectId.isValid(id)) {
        throw new Error(constants.databaseMessage.INVALID_ID);
    }
}