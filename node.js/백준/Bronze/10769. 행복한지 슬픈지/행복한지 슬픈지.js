let input = require('fs').readFileSync("/dev/stdin").toString().split('\n');
const strr = input[0];
let strr2 = "!" + strr + "!";
let smileCnt = strr2.split(':-)').length - 1;
let sadCnt = strr2.split(':-(').length - 1;

if (smileCnt == 0 && sadCnt == 0) {
    console.log("none");
} else if (smileCnt == sadCnt) {
    console.log("unsure");
} else if (smileCnt > sadCnt) {
    console.log("happy");
} else {
    console.log("sad");
}
