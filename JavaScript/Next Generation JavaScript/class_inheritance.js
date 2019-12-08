// var Person = function (name, birthYear) {
//     this.name = name;
//     this.birthYear = birthYear;
// }

// Person.prototype.calcAge = function() {
//     this.age = new Date().getFullYear() - this.birthYear;
// }

// var Athlete = function ( name, birthYear, medals) {
//     Person.call(this, name, birthYear);
//     this.medals = medals;
// }

// // First use Object.create then create a new prototype  for athlete

// Athlete.prototype = Object.create(Person.prototype);

// Athlete.prototype.addMedal = function() {
//     this.medals++;
// }

// var mark = new Athlete("Mark", 1993, 23);
// mark.calcAge();
// mark.addMedal();
// console.log(mark);


class Person {
    constructor(name, birthYear) {
        this.name = name; 
        this.birthYear = birthYear;
    }

    calcAge() {
        this.age = new Date().getFullYear() - this.birthYear;
    }

    static greet() {
        console.log("Hiiiii From Person");
    }
}

class Athlete extends Person {
    constructor(name, age, medals){
        super(name, age);
        this.medals = medals;
    }
    addMedals() {
        this.medals++;
    }
}

const john = new Athlete("John", 19, 23);
john.calcAge();
john.addMedals();
// john.greet();  Static method is not inherited
console.log(john);




