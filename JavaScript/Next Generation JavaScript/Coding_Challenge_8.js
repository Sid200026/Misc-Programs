class Element{
    constructor(name, buildYear){
        this.name = name;
        this.buildYear = buildYear;
    }

    getAge() {
        this.age = new Date().getFullYear() - this.buildYear;
    }
}

class Park extends Element{
    constructor(name, buildYear, treeCount, area) {
        super(name, buildYear);
        this.treeCount = treeCount;
        this.area = area;
    }

    getDensity() {
        this.density = Math.round((this.treeCount)/(this.area));
        console.log(`Density of ${this.name} is ${this.density}`);
    }
}

const calcAvg = (...parks) => {
    let sum = 0;
    for ( const park of parks )
    {   
        sum+= park.age;
    }
    const avg = sum/parks.length;
    console.log(`The average is ${avg}`);
}

const moreThan1000 = (...parks) => {
    for (const park of parks) {
        const {name, treeCount} = park;
        if(treeCount>1000)
        {
            console.log(name);
        }
    }
}

const p1 = new Park('Alpha', 2005, 1400, 220);
p1.getDensity();
p1.getAge();
const p2 = new Park('Beta', 2000, 566, 55);
p2.getDensity();
p2.getAge();
const p3 = new Park('Charlie', 1999, 1222, 90);
p3.getDensity();
p3.getAge();

moreThan1000(p1, p2, p3);
calcAvg(p1, p2, p3);

console.log(p1);
console.log(p2);
console.log(p3);

class Town extends Element{
    constructor(name, buildYear, length, size="normal"){
        super(name, buildYear);
        this.length = length;
        this.size = size;
    }
}

const totalAndAvg = (...streets) => {
    let sum = 0;
    for(const street of streets) {
        const {length : l} = street;
        sum+=l;
    }
    console.log(`The sum is ${sum}`);
    const avg = sum/streets.length;
    console.log(`The average is ${avg}`);
}

const t1 = new Town('Delta', 1999, 20, "tiny");
const t2 = new Town('Echo', 2004, 80);
const t3 = new Town('Foxtrot',2019, 1500);
const t4 = new Town('Gamma', 1960, 10, "small");
totalAndAvg(t1, t2, t3, t4);

console.log(t1);
console.log(t2);
console.log(t3);
console.log(t4);

