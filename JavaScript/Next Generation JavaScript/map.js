const question = new Map();
question.set("question", "What is 1+1");
question.set(1, "2");
question.set(2, "0");
question.set(3, "I will be deleted");
question.set(true, 1);
question.set(false, "Try again");

// console.log(question.get("question"));
// console.log(question.get(1));
// if(question.has(3))
// {
//     console.log(question.get(3));
//     question.delete(3);
// }
// question.clear();
// console.log(question.size);

// question.forEach((value, key) => {
//     console.log(key, value);
// })

for( const [key, value] of question.entries()) // .entries() specifies that we want the key-value pair
{
    if(typeof(key) === 'number')
        console.log(key,parseInt(value)); // Convert to num
}