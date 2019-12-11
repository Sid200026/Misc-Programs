// Promise Creation
const get_id = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve([1,2,3,4,5]);
    }, 2000)
});

// Promise Consumption
get_id
.then(ID => {
    console.log(ID);
})
.catch(error => {
    console.log(error);
})