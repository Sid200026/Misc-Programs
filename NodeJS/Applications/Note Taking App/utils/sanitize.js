const validator = require("validator");

const sanitize = input => {
  input.forEach(data => {
    validator.blacklist(data);
    validator.ltrim(data);
    validator.rtrim(data);
  });
};

module.exports = sanitize;
