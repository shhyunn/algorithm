import sys
from collections import defaultdict, deque

input = sys.stdin.readline

R, C = map(int, input().split())
arr = []
collec = set()


for _ in range(R):
	temp = list(input().strip())
	arr.append(temp)

dx = [-1,1,0,0]
dy = [0,0,-1,1]

res = 0
#dic 대신 set을 사용해보자
def dfs(x,y,cnt):
	global res

	res = max(res, cnt)

	for mx, my in zip(dx, dy):
		cx = x + mx
		cy = y + my

		if 0 <= cx < R and 0 <= cy < C and arr[cx][cy] not in collec:
			collec.add(arr[cx][cy])

			dfs(cx, cy, cnt+1)

			collec.remove(arr[cx][cy])

collec.add(arr[0][0])
dfs(0,0,1)
print(res)
