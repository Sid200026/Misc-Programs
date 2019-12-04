var Mark = {
    name : "Mark",
    mass : 67,
    height : 1.3,
    calcBMI : function() {
        this.bmi = this.mass/(this.height^2);
        return this.bmi;
    }
}

var John = {
    name : "John",
    mass : 52,
    height : 0.9,
    calcBMI : function() {
        this.bmi = this.mass/(this.height^2);
        return this.bmi;
    }
}
John.calcBMI()
Mark.calcBMI()

if(Mark.bmi>John.bmi)
{
    console.log(Mark.name, Mark.bmi);
    
}
else if(John.bmi>Mark.bmi)
{
    console.log(John.name, John.bmi);
    
}
else
{
    console.log("Same BMI");
    
}