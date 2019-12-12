// Promise Creation
const get_id = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve([1,2,3,4,5]);
    }, 2000)
});

const getRecipe = (ID) => {
    return new Promise((resolve, reject) => {
        setTimeout(id => {
            resolve({
                Serial : id,
                name:"Chicken Soup",
                price:350,
            });
        }, 2000, ID)
    })
}

// Promise Consumption

// This is similar to callback hell

// get_id
// .then(ID => {
//     getRecipe(ID[2])
//     .then(recipe => {
//         console.log(recipe);
//     })
//     .catch(error => {
//         console.log(error);
//     })
// })
// .catch(error => {
//     console.log(error);
// })

// What we will use instead is something known as chaining of promises

get_id
.then(ID => {
    return getRecipe(ID[2])
})
.then(recipe => {
    console.log(recipe);
})
.catch(error => {
    console.log(`Reject ${error}`);
})