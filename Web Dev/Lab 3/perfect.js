const sumDivisor = num => {
    let sum = 1;
    for(let i=2;i<=num/2;i++) {
        if(num%i === 0) {
            sum+=i;
        }
    }
    return sum;
}

const checkPerfectNumber = num => {
    const sum = sumDivisor(num);
    if(sum===num) {
        return true;
    }
    return false;
}

if(checkPerfectNumber(11)) {
    console.log("Perfect Number");
} else {
    console.log("Not a Perfect Number")
}