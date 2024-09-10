let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
let N = Number(input[0]);
let sizeArr = input[1].split(" "); //사이즈별 숫자 배열
let temp = input[2].split(" ");
let T = Number(temp[0]);
let P = Number(temp[1]);

let T_max = 0;
for (let s of sizeArr) {
  T_max += Math.ceil(s / T);
}
let P_max = Math.floor(N / P);
let P_r = N % P;

console.log(T_max);
console.log(P_max, P_r);