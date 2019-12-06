var Person = function(name, age) {
    this.name = name;
    this.age = age;
    // this.calcBirthYear = function() {
    //     this.birthYear = 2019 - this.age;
    // }
}

Person.prototype.calcBirthYear = function() {
    this.birthYear = 2019 - this.age;
}

Person.prototype.nation = "Indian";

var john = new Person("John", 19);
john.calcBirthYear(); // Here the this variable will point to the john object.
console.log(john);
// console.log(john.nation);

var mark = new Person("Mark", 20);
mark.calcBirthYear();
// console.log(mark);

