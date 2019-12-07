const arr = [1,2,3,4,5];
for ( const ele of arr) {
    if(ele%2==0)
        continue;
    console.log(ele);
}