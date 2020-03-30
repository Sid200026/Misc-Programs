console.log("Starting password manager");

var storage = require('node-persist');
storage.initSync();

var argv = require('yargs')
    .command('create', 'Create user account', function (yargs) {
        return yargs.options (
            {
                name: {
                    demand: true,
                    alias: 'acc',
                    description: "Enter account name (Twitter, Facebook, etc)",
                    type: 'string'
                },
                username: {
                    demand: true,
                    alias: 'un',
                    description: "Enter your user ame",
                    type: 'string'
                },
                password: {
                    demand: true,
                    alias: 'pwd',
                    description: "Enter your password",
                    type: 'string'
                }
            }
        ).help('help');
    })
    .command('get', "Get user account information", function (yargs) {
        return yargs.options(
            {
                name: {
                    demand: true,
                    alias: 'acc',
                    description: "Enter account name",
                    type: 'string'
                }
            }
        ).help('help');
    }).help('help').argv;

var command = argv._[0];



//function to create an account, arguments - account object
//account object - name(facebook), username, password
function createAccount(account) {
  //first, get accounts stored with node-persist
  var accounts = storage.getItemSync("accounts");

  //if returned item is undefined, set it to an empty array
  if(typeof accounts === "undefined") {
    accounts = [];
  }

  accounts.push(account);
  storage.setItemSync("accounts", accounts);

  return account;
}

//function to get an account - arguments - account name
function getAccount(accountName) {
  //load all saved accounts
  var accounts = storage.getItemSync("accounts");
  var matchedAccount = {};
  accounts.forEach(function(account) {
    if(account.name === accountName) {
      matchedAccount = account;
    }
  });
  return matchedAccount;
}

if(command === 'create') {
    var createdAccount = createAccount({
        name: argv.name,
        username: argv.username,
        password: argv.password
    });
    console.log("Account created successfully, account details ---");
    console.log(createdAccount);
}

else if (command === 'get') {
    var fetchedAccount = getAccount(argv.name);
    if(typeof fetchedAccount !== 'undefined') {
        console.log("Account fetched successfully, account details ---");
        console.log(fetchedAccount);
    }
    else {
        console.log("Sorry, that account does not exist");
    }
}
