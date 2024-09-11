let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let cnt = 0;
let startNum;

input.forEach((value, index) => {
  if (!isNaN(value)) {
    cnt = 3 - index;
    startNum = Number(value);
  };
});

if (cnt == 0) {
  console.log(1);
} else {
  if ((startNum + cnt) % 3 == 0) {
    if ((startNum + cnt) % 5 == 0) {
      console.log("FizzBuzz");
    } else {
      console.log("Fizz");
    }
  } else {
    if ((startNum + cnt) % 5 == 0) {
      console.log("Buzz");
    } else {
      console.log(startNum+cnt);
    }
  }
}