const getRecipeIDs = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve([1,5,3,4,8,9]);
    }, 1500);
});

const getRecipe = id => {
    return new Promise((resolve, reject) => {
        setTimeout(id => {
            resolve({
                id : id,
                name: "Chicken Soup",
                price : 500,
            })
        }, 1500, id)
    })
};

async function recipe() {
    try{
        const ids = await getRecipeIDs;
        const recipe = await getRecipe(ids[2]);
        console.log(recipe);
        return 5;
    } catch(error) {
        console.log(error);
    }
}

recipe().then(res => console.log(res));