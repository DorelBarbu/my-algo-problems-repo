let user = {
  name: "John",
  surname: "Doe",

  get fullName() {
    return `${this.name} ${this.surname}`;
  }
}

console.log(user.fullName);

