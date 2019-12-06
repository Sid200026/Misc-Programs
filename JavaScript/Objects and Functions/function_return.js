function interviewQuestion(job) {
    if(job === 'designer') {
        return function(name) {
            console.log(name + " designer");
        }
    }
    else if (job === 'teacher') {
        return function(name) {
            console.log(name + " teacher");
        }
    } else {
        return function(name) {
            console.log(name + " What do you do?");
        }
    }
}

// Here the return type of the function is an function

var desq = interviewQuestion("designer");
desq("Siddharth");

interviewQuestion("teacher")("Mark");