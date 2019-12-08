// function addFour(a, b, c, d) {
//     return a+b+c+d;
// }

// console.log(addFour(1,2,3,4));

// ages = [1,2,3,4];
// // console.log(addFour.apply(this, ages));

// console.log(addFour(...ages));

const arr1 = [1,2,3,4];
const arr2 = [5,6,7,8];

const arr = [...arr1,4.5,...arr2];
console.log(arr);
