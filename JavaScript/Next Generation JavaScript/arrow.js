const years = [1990, 2016, 2000, 1986];
// const arr = years.map(function(value) {
//     return 2018 - value;
// })

// const arr = years.map(calcAge);

// function calcAge(value) {
//     return 2018-value;
// }

const arr = years.map(ele => 2019-ele);

// console.log(arr);

var obj = {
    color:'green',
    calc:function() {
        var self = this;   // Hack to use the this keyword inside the nested function
        return function(){
            console.log("Hi    " + self.color);
        }
    }
}

// obj.calc()();

// var obj6 = {
//     color:'green',
//     calc:(function() {
//         return() => {
//             console.log("Hi    " + this.color); // this will refer to the function inside which we have the nested function
//         }
//     })
// };

// obj6.calc()();

// var obj6 = {
//         color:'green',
//         calc: () => {
//             return() => {
//                 console.log("Hi    " + this.color); // this will refer to the function inside which we have the nested function
//             }
//         }
//     };
// obj6.calc()();



var obj = {
    color:'green',
    calc:function() {
        //var self = this;   // Hack to use the this keyword inside the nested function
        return function(){
            console.log("Hi    " + this.color);
        }.bind(this);
    }
}
obj.calc()();