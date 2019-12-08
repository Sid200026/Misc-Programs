// function details(name, age, birthYear, nation) {
//     if(birthYear === undefined)
//     {
//         birthYear = new Date().getFullYear();
//     }
//     if(nation === undefined)
//     {
//         nation = "India";
//     }
//     console.log(name, age, birthYear, nation);
// }

const details = (name, age, birthYear = new Date().getFullYear(), nation = "India") => console.log(name ,age, birthYear, nation);

details("Siddharth", 19);