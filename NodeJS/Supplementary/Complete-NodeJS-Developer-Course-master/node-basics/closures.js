function greetMaker(name) {
  function greet() {
    console.log("Hi " + name +"!");
  };

  return greet;
}

var greeting = greetMaker("Tom");
greeting();
