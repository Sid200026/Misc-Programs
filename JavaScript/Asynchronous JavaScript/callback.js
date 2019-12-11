function getRecipeID() {
    setTimeout(() => {
        const arr = [15,2,64,34];
        console.log(arr);
        setTimeout((id) => {
            console.log(id);
        }, 1500, arr[1]);
    }, 2000);
};

getRecipeID();
