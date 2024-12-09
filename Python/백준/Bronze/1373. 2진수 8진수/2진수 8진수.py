import sys
input = sys.stdin.readline

strr = input().strip()

octal = oct(int(strr, 2))  # 2진수를 10진수로 변환한 후 8진수로 변환
print(octal[2:])