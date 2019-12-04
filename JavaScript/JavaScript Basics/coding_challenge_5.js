var John = {
    bills: [124,48, 268, 180, 42],
    tip : [],
    getTip : function() {
        for(var i = 0; i<this.bills.length; i++)
        {
            var tipamt = 0;
            if(this.bills[i]<50)
                tipamt = 0.2*this.bills[i];
            else if(this.bills[i]<200)
                tipamt = 0.15*this.bills[i];
            else
                tipamt = 0.1*this.bills[i];
            this.tip.push(tipamt);
        }
    },
    getTotalTip : function() {
        var sum = 0;
        for(var i =0; i<this.bills.length; i++)
        {
            sum+=this.tip[i];
        }
        this.totalTip = sum;
        this.avg = sum/this.bills.length;
    },
    
};

var Mark = {
    bills: [77,375, 110, 45],
    tip : [],
    getTip : function() {
        for(var i = 0; i<this.bills.length; i++)
        {
            var tipamt = 0;
            if(this.bills[i]<100)
                tipamt = 0.2*this.bills[i];
            else if(this.bills[i]<300)
                tipamt = 0.1*this.bills[i];
            else
                tipamt = 0.25*this.bills[i];
            this.tip.push(tipamt);
        }
    },
    getTotalTip : function() {
        var sum = 0;
        for(var i =0; i<this.bills.length; i++)
        {
            sum+=this.tip[i];
        }
        this.totalTip = sum;
        this.avg = sum/this.bills.length;
    },
};

John.getTip();
John.getTotalTip();
Mark.getTip();
Mark.getTotalTip();
if(John.avg>Mark.avg)
{
    console.log("Mark");
}
else if(Mark.avg>John.avg)
{
    console.log("John");
}
else
{
    console.log("Same");
}
console.log(John);
console.log(Mark);

