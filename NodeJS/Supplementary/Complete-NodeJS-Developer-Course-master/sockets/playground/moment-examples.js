const moment = require('moment');

let now = moment();

// display timestamps
console.log(`Unformatted: ${now.format()}`);
console.log(`Formatted with hour, minute and time: ${now.format('h.mm a')}`);


// format and show timestamp
console.log(`Formatted with y,m,d and time: ${now.format('MMM Do YYYY, h:mm a')}`);

console.log(`Formatted as unix timestamp in secs: ${now.format('X')}`);
console.log(`Fomatted as unix timestamp in millisecs: ${now.format('x')}`);

console.log("----");

// converting between timestamps and moment objects
let timestamp = 1518900426836;
let timestampMoment = moment.utc(timestamp);
console.log(`Unix timestamp converted to moment: ${timestampMoment.format('h:mm a')}, at ${now.format('h.mm a')}`);

// convert from utc to local offset
console.log("--- Local timestamps --- ");
console.log(`Unix timestamp converted to moment: ${timestampMoment.local().format('h:mm a')}, at ${now.local().format('h.mm a')}`);
