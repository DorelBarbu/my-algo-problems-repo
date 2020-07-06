let user = {
  firstName: 'John',
  sayHi() {
    console.log(`Hi, my name is ${this.firstName}`);
  }
};

let sayHi = user.sayHi.bind(user);
sayHi(); //The function does not loose "this"

setTimeout(sayHi, 1000); //The function works, it does not loose this, it is still linked to user
