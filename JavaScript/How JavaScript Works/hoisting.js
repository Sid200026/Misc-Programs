/*calcAge(2018); // This works because of code hoisting
// JS already knows the functions that are there in the code
// even before executing the function

function calcAge(year) {
    console.log(2019-year);
}

//calcAge(2018);


// Code Hoisting
console.log(test);

test = 6;
console.log(test);

var test = 5;

// This raises an error
// retire(2000);

// // This a function expression
// var retire = function() {
//     console.log(2018-2000);
// }
*/

// Here since hoisting is done inside the foo context, the JS engine knows
// that we have the age variable declared later in the foo context.
// CASE 1
// var age = 18;
// function foo() {
//     console.log(age); // undefined
//     var age = 8;
//     console.log(age);
// }
// foo();
// console.log(age);

// This will use the scope chain to get the parent context objects from
// which it will get the age variable
// // CASE 2
// var age = 18;
// function foo() {
//     age = 8;
//     console.log(age);
// }
// foo();
// console.log(age);

// CASE 3
var age = 18;
function foo() {
    console.log(age);
}
foo();
console.log(age);
