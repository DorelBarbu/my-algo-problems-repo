function delayDecorator(f:Function, ms:number) {
  return function(this: any) {
    console.log('Who is this ?');
    console.log(this);
    setTimeout(() => f.apply(this, arguments), ms);
  }
}

function addNumbers(x:number, y:number):void {
  console.log(`addNumbers called with ${x} and ${y} and returns ${x + y}`);
}

const drl = {
  firstName: 'Dorel',
  lastName: 'Barbu',
  sayHello() {
    console.log(`Hi, my name is ${this.firstName} ${this.lastName}`);
  }
}

//Test 1
const f150 = delayDecorator(addNumbers, 150);

//Test 2
console.log('About to call the function on drl');
drl.sayHello = delayDecorator(drl.sayHello, 2000);
drl.sayHello();
