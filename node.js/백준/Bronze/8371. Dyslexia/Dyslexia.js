let input = require("fs").readFileSync('/dev/stdin').toString().split("\n");
const cnt = +input[0];
const str1 = input[1];
const str2 = input[2];
let res = 0;

for (let i = 0; i < cnt; i++) {
  if (str1[i] != str2[i]) {
    res += 1;
  }
}

console.log(res);