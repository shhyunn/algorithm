import sys
input = sys.stdin.readline

numArr = list(map(str, input().strip().split(" ")))
num1 = numArr[0] + numArr[1]
num2 = numArr[2] + numArr[3]

print(int(num1) + int(num2))
