import sys
sys.setrecursionlimit(100000000) 

N, M = map(int, input().split(" "))

arr = []

for _ in range(N):
	temp = list(map(int, input().split(" ")))
	arr.append(temp)

visited = [[False for _ in range(M)] for _ in range(N)]

move_x = [-1,1,0,0]
move_y = [0,0,-1,1]

def dfs(x,y):
	global arr, visited, move_x, move_y

	zero = 0
	
	for dx, dy in zip(move_x, move_y):
		cx = x + dx
		cy = y + dy

		if 0 <= cx < N and 0 <= cy < M and arr[cx][cy] and not visited[cx][cy]:
			visited[cx][cy] = True
			dfs(cx,cy)

		elif 0 <= cx < N and 0 <= cy < M and not arr[cx][cy] and not visited[cx][cy]: #0인 경우
			zero += 1

	arr[x][y] = max(0, arr[x][y] - zero)

sec = 0

while True:
	res = 0
	sec += 1
	visited = [[False for _ in range(M)] for _ in range(N)]

	for i in range(N):
		for j in range(M):
			if arr[i][j] and not visited[i][j]:
				visited[i][j] = True
				dfs(i,j)
				res += 1

	if res >= 2:
		print(sec-1)
		break

	if res == 0:
		print(0)
		break