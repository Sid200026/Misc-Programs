/**
 * Created by manishgiri on 2/26/17.
 */

function doPromiseWork(data) {
    //console.log(data);
    return new Promise(function(resolve, reject) {
        //call resolve after 2 seconds
        setTimeout(function() {
            resolve(data);
        }, 2000);
//        setTimeout(function() {
//        reject("Promises failed");
//      }, 2000);
    });
}

/*doPromiseWork("Hello World").then(function(result) {
        console.log(result);
    } //function(error) {
    //console.log(error);
//}
);*/

// doPromiseWork(2).then(function(result){
//
//     console.log(result);
//     return result += 1;
// }).then(function(result){
//     console.log(result);
//     return result += 2;
// }).then(function(result){
//     console.log(result);
//     //result += 1;
// })

function booleanWork(shouldFail) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if(shouldFail) {
                reject("Promise Rejected.");
            }
            else {
                resolve("Promise Resolved.");
            }
        }, 2000)
    });
}

booleanWork().then(function (message) {
    console.log(message);
    // return another promise
    return booleanWork(true)
}).then(function (message) {
    console.log(message);
}).catch(function (error) {
    // this will execute because promise was rejected 2nd time
    console.log(error);
})
