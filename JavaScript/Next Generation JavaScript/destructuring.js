// var arr = ['John', 18];
// var name = arr[0];
// var age = arr[1];
// console.log(name, age);

// Destructuring

// const [name, age] = arr;
// console.log(name, age);

const mark = {
    name: "Sid",
    age: 19,
    fn: ()=>17,
    arr:[1,2,3],
}

const {name, fn, age, arr} = mark;
console.log(name, age, fn, arr);