// ES5

// var Person = function(name, job, birthYear = 2000) {
//     this.name = name;
//     this.job = job;
//     this.birthYear = birthYear;
// }

// Person.prototype.calcAge = function() {
//     this.age = new Date().getFullYear() - this.birthYear;
// }

// var john = new Person("John", "Web-Dev", 2001);
// john.calcAge();
// console.log(john);

// ES6

class Person {
    constructor(name, job, birthYear = 2000)
    {
        this.name = name;
        this.job = job;
        this.birthYear = birthYear;
    }

    calcAge() { // This becomes a prototype property
        this.age = new Date().getFullYear() - this.birthYear;
    }

    static greet () {
        console.log("Hi there...");
    }
}

const john = new Person("John", "Web-dev", 2001);
john.calcAge();
// console.log(john);
Person.greet();