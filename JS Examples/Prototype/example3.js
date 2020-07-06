let animal = {
  eat() {
    this.full = true;
  }
};

let rabbit = {
  __proto__: animal
};

rabbit.eat();

//This is the object before the dot, so rabbit.eat() will modify rabbit
//The method rabbit.eat is first found in prototype, then executed with this=rabbit