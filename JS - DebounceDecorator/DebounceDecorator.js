function printSomething(chr) {
  console.log(`Function was called with ${chr}`);
}

function debounce(f, ms) {
  let timeout;
  return function() {
    clearTimeout(timeout);
    timeout = setTimeout(() => {
      f.apply(this, arguments)
    }, ms);
  }
}

const drl = {
  firstName: 'Dorel',
  lastName: 'Barbu',
  sayHi: function(chr) {
    console.log(`Hi, my name is ${this.firstName} ${this.lastName} and ${chr}`);
  }
}

drl.sayHi = debounce(drl.sayHi, 1000);

drl.sayHi("a");
setTimeout( () => drl.sayHi("b"), 200);
setTimeout( () => drl.sayHi("c"), 500);
// debounced function waits 1000ms after the last call and then runs: alert("c")