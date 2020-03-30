var person = {}

person.firstName = "Manish"
person.lastName = "Giri"
person.age = 27;

console.log(person)

function greetPerson(person) {
	console.log("Hello " + person.firstName + " " + person.lastName);
}

greetPerson(person);