let user = {
  firstName: "John",
  sayHi() {
    console.log(`Hi my name is ${this.firstName}`);
  }
}

//We will try to pass an object method as a callback

user.sayHi(); // It will work all right
setTimeout(user.sayHi, 1000); // It will result in undefined, since "this" is not bounded
setTimeout(function() {
  user.sayHi();
}, 1000); //Wll work perfectly fine


//Allthough the method worksm, what happens if user changes before the function gets called?