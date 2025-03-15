import sys
input = sys.stdin.readline

N = int(input())
arr = map(int , input().split())

res = 0
prev = 0
res = -1e9

for a in arr:
	if prev + a >= 0:
		prev = max(a, prev+a)
	else:
		prev = a
	res = max(res, prev)

print(res)





