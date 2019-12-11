const second = () => {
    setTimeout(() => {
        console.log("Async Second called");
    }, 2000); // Execute this call back function after 2 seconds
}

const first = () => {
    console.log("Hi there");
    second();
    setTimeout(() => {
        console.log("Async called after calling second");
    }, 1500);
    console.log("Done calling second");
}
first();