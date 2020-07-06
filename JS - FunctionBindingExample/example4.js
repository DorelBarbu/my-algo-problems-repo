function mul(a, b) {
  return a * b;
}

let double = mul.bind(null, 2); //Fixes 2 as the first argument, the other aguments are passed as is

console.log(double(3));
console.log(double(10));