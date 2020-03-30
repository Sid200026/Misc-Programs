/**
 * Created by manishgiri on 10/22/16.
 */
var person = {
    name: 'Andrew',
    age: 24
}

var personJSON = JSON.stringify(person);
console.log(`personJSON = ${personJSON} `);
console.log(typeof personJSON);

console.log();

var personObject = JSON.parse(personJSON);
console.log(`personObject.name = ${personObject.name}`);
console.log(typeof personObject);

//challenge
var animal = '{"name": "Halley"}';

//convert string to JS object, add an age property, convert back 
var animalObject = JSON.parse(animal);
console.log(`animalObject.name = ${animalObject.name}`);
animalObject.age = 4;
console.log(`animalObject.age = ${animalObject.age}`);
var animalJSON = JSON.stringify(animalObject)
console.log(`animal object JSON = ${animalJSON}`);
