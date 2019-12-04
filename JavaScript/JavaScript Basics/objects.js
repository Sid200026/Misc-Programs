var user = {
    username : "Siddharth",
    password : "admin",
    email : "sid@gmail.com",
    gender : "Male",
    friends : ["Siddharth", "Singha", "Roy"],
    token  : "randtoken",
    birthYear : 1999,
}

// console.log(user);
// console.log(user.username);
// console.log(user['password']);

user.username = "sid"
user['password'] = "pwd"

// console.log(user);

user.isAdult = function() {
    this.age = (2019-this.birthYear)>=18
}

user.isAdult()
console.log(user);

// user.adult = user.isAdult();
// console.log(user);
// Now instead of separately specifying a new key-value relation we can directly do that in the method
// using this keyword





