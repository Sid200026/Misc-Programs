var john = {
    name : "John",
    age: 26,
    job: 'teacher',
    presentation : function(style,time) {
        if(style === "formal") {
            console.log("Good "+time+" gentleman. I'm "+this.name);
        }
        else if(style === "friendly") {
            console.log("Howdyyyyyyy. It's "+time+" my friend. I'm "+this.name);
        }
    }
};



john.presentation("formal","morning");
john.presentation("friendly","night");


var emily = {
    name:"Emily",
    age: 35,
};

// We want to have the presentation method of john in emily.

john.presentation.call(emily, 'friendly','morning'); // The callmethod is used for method borrowing

// john.presentation.apply(emily, ['friendly','night']);


var johnFriendly = john.presentation.bind(john, 'friendly');
johnFriendly('night');
johnFriendly('morning');

var emilyFormal = john.presentation.bind(emily, 'formal');
emilyFormal('afternoon');

function isFullAge(limit, age) {
    return age>=limit;
}

console.log(isFullAge.bind(this,20)(21));