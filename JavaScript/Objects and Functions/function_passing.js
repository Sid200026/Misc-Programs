var arr1 = [1980, 1956, 1999, 2000, 2005];

function arrayCalc(arr, fn) {
    var arrRes = []
    for(var i = 0;  i < arr.length; i++)
    {
        arrRes.push(fn(arr[i]))
    }
    return arrRes;
}

function calcAge(el) {
    return 2019 - el;
}

function isFullAge(el) {
    return el>=19;
}
var arr = arrayCalc(arr1, calcAge);
console.log(arrayCalc(arr, isFullAge));
console.log(arr);
