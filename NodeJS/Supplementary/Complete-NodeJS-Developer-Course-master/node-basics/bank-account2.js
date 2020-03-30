//an array to hold account objects
var accounts = [];

//create a function to create a user account
function createAccount(balance, userName) {
    var account = {};
    account.balance = balance;
    account.userName = userName;
    accounts.push(account);
    console.log("Account created for user: " + userName);
    return account;
}

//a function to get a user's account given the userName
function getAccount(user) {
  //modify function to use for loop instead of forEach
    var matchedAccount = {};
    for(var i = 0; i < accounts.length; i++) {
      if(accounts[i].userName === user) {
        matchedAccount = accounts[i];
      }
    }
    return matchedAccount;
}

function deposit(account, amount) {
    // body...
    //only accept numbers
    if(typeof amount === "number") {
      account.balance += amount;
    }
    else {
        console.log("Deposit failed.");
    }

}

function withdraw(account, amount) {
    // body...
    //only accept numbers
    if(typeof amount === "number") {
      account.balance -= amount;
    }
    else {
      console.log("Deposit failed.");
    }
}

function getBalance(account) {
    return account.balance;
}

//function to create closure for balance getBalance
function createBalanceGetter(account) {
  return function() {
    return account.balance;
  };
}

/*
deposit(account, 1000);
console.log(getBalance(account));
withdraw(account,200);
console.log(getBalance(account));
*/

//create 3 accounts
createAccount(2000, "John");
createAccount(4000, "James");
createAccount(6000, "Elisa");

//get accounts - 1 success, 1 fail
//getAccount("James");
//getAccount("Jack");

console.log(accounts);

//deposit into john - fail
var johnAccount = getAccount("John");
console.log("Balance = " + getBalance(johnAccount));
deposit(johnAccount, "skdksjd");
console.log("Balance = " + getBalance(johnAccount));
deposit(johnAccount, 1000);
console.log("Balance = " + getBalance(johnAccount));

createAccount(1500, "Joe");
console.log(accounts);
var joeAccount = getAccount("Joe");
//console.log(joeAccount);
console.log(createBalanceGetter(joeAccount)());
