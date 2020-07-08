function Rabbit() {}

Rabbit.prototype = {
  eats: true
};

let rabbit = new Rabbit();

Rabbit.prototype.eats = false;

//The F.prototype property does not have any effect if the function is not called like a constructor (with new)
console.log( rabbit.eats ); // true