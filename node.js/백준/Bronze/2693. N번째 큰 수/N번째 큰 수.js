let fs = require("fs");
// let input = fs.readFileSync("./example.txt").toString().split("\n");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

//T 정의
const T = +input[0];

for (let i = 0; i < T; i++) {
  let tempArr = input[i + 1].split(" "); //띄어쓰기 기준으로 배열로 저장
  tempArr.sort((a, b) => b - a); //내림차순 정렬
  console.log(tempArr[2]); //3번째로 큰 수 출력
}
