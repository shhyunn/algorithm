let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
let T = Number(input[0]);

function combination(n, k) {
  let result = 1;
  for (let i = 0; i < k; i++) {
    result *= n - i;
    result /= i + 1;
  }
  return result;
}

for (let i = 1; i <= T; i++) {
  let arr = input[i].split(" ");
  let numbers = arr.map(Number);

  let N = numbers[0];
  let M = numbers[1];

  // 서쪽 N개의 사이트를 동쪽 M개에서 선택하는 경우의 수를 구합니다.
  let res = combination(M, N);

  console.log(Math.round(res)); // 조합의 결과는 정수로 떨어지므로 Math.round()는 불필요할 수도 있음
}