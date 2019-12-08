// function sum() {
//     console.log(arguments);  // arguments is a keyword
// }

function sum(...arr) {
    let sums = 0;
    for(const ele of arr)
    {
        sums+=ele;
    }
    console.log(sums);
}
sum(1,2,3,4,5);

const arr = [0,1,2,3,4,5,6,7,8];
console.log(arr.slice(2,5));
console.log(arr.slice(4));

const checkAge = (limit, ...years) => {
    years.forEach((ele) => {
        console.log(ele>=limit);
    })
}

checkAge(19,16,12,18,14,20,23,26,85);