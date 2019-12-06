function retirement(retirementAge) {
    var a = " years left till retirement";
    return function(yearOfBirth){
        var age = 2016-yearOfBirth;
        console.log((retirementAge-age)+a);
    }
}

// var retirementUS = retirement(65);
// retirementUS(1992);

// retirement(66)(1992);

// The inner function can use the values of a and retirementAge even after exiting from the
// execution stack of retirement ( since we have returned something ).

function interviewQuestion(job) {
    var design = " Hi designer";
    var teacher = " Hi teacher";
    if (job==="designer") {
        return function(name) {
            console.log(name,design);
        }
    }
    else if (job==="teacher") {
        return function(name) {
            console.log(name,teacher);
        }
    }
}

// This function could be written by returning just one function if we did the if else inside return

var teacher = interviewQuestion("teacher");
teacher("Mark");
teacher("Sally");
interviewQuestion("designer")("John");