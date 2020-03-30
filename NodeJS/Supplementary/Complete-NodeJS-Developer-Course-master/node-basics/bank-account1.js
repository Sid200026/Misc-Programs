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
    var matchedAccount = {};
    accounts.forEach(function(account) {
        if (account.userName === user) {
            //console.log("Account for user: " + user + " was found.");
            matchedAccount = account;
        }

    });
    return matchedAccount;
}

function deposit(account, amount) {
    // body...
    account.balance += amount;
}

function withdraw(account, amount) {
    // body...
    account.balance -= amount;
}

function getBalance(account) {
    return account.balance;
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

//deposit into john
var johnAccount = getAccount("John");
console.log("Balance = " + getBalance(johnAccount));
deposit(johnAccount, 1000);
console.log("Balance = " + getBalance(johnAccount));
