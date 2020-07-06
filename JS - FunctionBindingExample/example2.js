let user = {
  firstName: "John"
}

function f() {
  console.log(this.firstName);
}

//The "this" of funcUser will always be user
let funcUser = f.bind(user);
funcUser();