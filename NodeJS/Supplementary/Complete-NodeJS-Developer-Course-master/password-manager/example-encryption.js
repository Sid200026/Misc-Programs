/**
 * Created by hi on 10/22/2016.
 */
var crypto = require('crypto-js');

//message
//var secretMessage = "I hid the chips under the couch.";
var secretMessage = {
    name: "Andrew",
    code: 007
};

//key
var secretKey = '123abc';

//encrypt the message
//encrypt() takes a string, so use JSON.stringify to create JSON string
var secretMessageJSON = JSON.stringify(secretMessage);
console.log(`Secret Message in JSON: ${secretMessageJSON}`);

//var encryptedMessage = crypto.AES.encrypt(secretMessage, secretKey);
var encryptedMessage = crypto.AES.encrypt(secretMessageJSON, secretKey);
console.log(`Encrypted Message: ${encryptedMessage}`);

//decrypt the message
var bytes = crypto.AES.decrypt(encryptedMessage, secretKey);
//convert array of bytes to string
var decryptedMessage = bytes.toString(crypto.enc.Utf8);
console.log(`Decrypted Message: ${decryptedMessage}`);

//convert decrypted string message back to JS object
var decryptedMessageObject = JSON.parse(decryptedMessage);
console.log(`Type of decrypted message object: ${typeof decryptedMessageObject}`);
console.log(`object.name = ${decryptedMessageObject.name}`);

//challenge - encrypt an object, instead of a string