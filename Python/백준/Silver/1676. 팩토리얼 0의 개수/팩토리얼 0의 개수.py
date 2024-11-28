import sys
input = sys.stdin.readline

N = int(input())
num = 1
for i in range(N,0,-1):
    num*=i

cnt = 0
str_num = str(num)
for j in range(len(str_num)-1,0,-1):
    if str_num[j] == "0":
        cnt += 1
    else:
        break

print(cnt)