const user = {
  name: 'David',
  age: 22,
  city: 'Salt Lake City',
  country: 'USA'
};

/* const name = user.name;
const country = user.country; */

const { name, country } = user;

console.log('name: ', name);
console.log('country: ', country);

const myArr = [1, 2, 3, 4];

/* const foo = myArr[0];
const bar = myArr[1];
const jazz = myArr[2]; */

const [foo, bar, jazz] = myArr;

console.log('foo: ', foo);
console.log('bar: ', bar);
console.log('jazz: ', jazz);