let input = require("fs").readFileSync('/dev/stdin').toString().split("\n");
let T = Number(input[1]);
console.log(input[0][T - 1]);
