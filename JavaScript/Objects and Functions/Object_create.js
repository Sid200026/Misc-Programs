var personProto = {
    caculateBirthYear : function() {
        consoole.log(2019 - this.age);
    }
};

var john = Object.create(personProto); // The first argument is the prototype of that object
john.name = "John";
john.age = 18;

var mark = Object.create(personProto, 
{
    name : { value : "Mark"},
    age : { value : 19 },
});

var sid = Object.create(null);