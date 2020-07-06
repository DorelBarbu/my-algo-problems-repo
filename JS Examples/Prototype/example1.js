//__proto__ is a historycal getter and setter for [[Prototype]]

let animal = {
  eats: true
};

let rabbit = {
  jumps: true
};

rabbit.__proto__ = animal;

console.log(rabbit.jumps);
console.log(rabbit.eats); //It will be taken of the prototype