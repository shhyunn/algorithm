let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

let sum = 0;
for (let i = 0; i < 5; i++) {
  sum += +input[i];
}

console.log(sum);