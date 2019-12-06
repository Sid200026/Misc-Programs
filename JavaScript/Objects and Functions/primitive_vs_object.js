var a = 5;
var b = 5;
console.log(a===b);


var c = 43;
var d = c;
c = 5;
console.log(c,d); // The value  of c remains 43

var obj1 = {
    name : 'John',
    age : 26,
};

var obj2 = obj1;

obj1.age = 18;

console.log(obj1, obj2);

console.log(obj1 === obj2);


var obj3 = {
    name : 'John',
    age : 18,
};

console.log(obj1 === obj3);


changeVal(c, obj1);

function changeVal(a,b) {
    a = 6;
    b.age = 17;
}

console.log(c, obj1);


