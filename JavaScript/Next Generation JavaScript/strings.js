let name = "Siddharth";
const birthYear = 1990;

function calcAge(year) {
    return 2019 - year;
}

// ES5

console.log(name+" having birth year "+birthYear+ " is "+calcAge(birthYear) + " years old.");

// ES6
// Template Literals

console.log(`${name} having birth year ${birthYear} is ${calcAge(birthYear)} years old`);

name = "Siddharth Singha Roy";
console.log(name.startsWith("Sid"));
console.log(name.endsWith("oy"));
console.log(name.includes("ing"));
console.log(name.repeat(5));
console.log(`${name} `.repeat(5));

