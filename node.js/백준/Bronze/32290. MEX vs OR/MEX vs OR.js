let input = require("fs").readFileSync("/dev/stdin").toString().split(" ");
let l = +input[0];
let r = +input[1];
let c = +input[2];

let res = [];

for (let t = l; t < r+1; t++) {
  res.push(t | c);
}

if (res[0] == 0) {
  console.log(Math.max(...res)+1);
} else {
  console.log(0);
}