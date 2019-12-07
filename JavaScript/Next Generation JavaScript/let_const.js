// ES5

var name5 = "Siddharth Singha Roy";
var age5 = 18;
name5 = "Siddharth S Roy";
console.log(name5);

// ES6
const name6 = "Siddharth Singha Roy";
let age6 = 18;
// name6 = "Siddharth S Roy";   // Causes an error
console.log(name6);

function test() {
    if(true)
    {
        var i = 0;
    }
    console.log(i);
}

test();

function test6() {
    if(true)
    {
        let i = 0;
        const j = 0;
    }
    // console.log(i,j);
}

// An error will be raised when we run this because let and const are block scoped

test6();


// const check;
// let you;
// you = 1;
// check = 5;

let i = 23;
for(let i = 0; i<5;i++)
    console.log(i);
console.log(i);

    