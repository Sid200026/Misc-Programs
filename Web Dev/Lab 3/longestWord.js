const word = "Hi my name is Siddharth Singha Roy";
const arr = word.split(' ');
let max = 0;
let maxindex = -1;
const lenarr = arr.forEach((str, index) => {
    if(str.length>max) {
        max = str.length;
        maxindex = index;
    }
});
console.log(arr[maxindex]);