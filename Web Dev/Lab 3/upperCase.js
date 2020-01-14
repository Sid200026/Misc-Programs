const capitalize = word => {
    let res = '';
    let flag = true;
    for(let i = 0;i<word.length; i++)
    {
        if(flag) {
            res += word[i].toUpperCase();
            flag = false;
        } else {
            res += word[i];
        }
        if(word[i] === ' ') {
            flag = true;
        }
    }
    return res;
}

const word = "Hi my name is Siddharth Singha Roy";

console.log(capitalize(word))