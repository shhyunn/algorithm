from collections import deque

N, M = map(int, input().split())
maps = []
emptys = []
virus = deque([])

for i in range(N):
	tmp = list(map(int, input().split()))
	for j, t in enumerate(tmp):
		if t == 0:
			emptys.append((i,j))

		if t == 2:
			virus.append((i,j))

	maps.append(tmp)

#3개 벽 세우기
move = [(1,0), (-1,0), (0,1), (0,-1)]

def open_virus():
	global maps, virus
	dual = [row[:] for row in maps]
	visited = [[False for _ in range(M)] for _ in range(N)]

	for v in virus:
		visited[v[0]][v[1]] = True

	stack = deque([v for v in virus])

	while stack:
		x,y = stack.popleft()

		for dx, dy in move:
			cx = x + dx
			cy = y + dy

			if 0 <= cx < N and 0 <= cy < M and not visited[cx][cy] and dual[cx][cy] == 0:
				dual[cx][cy] = 2 #바이러스 퍼짐
				visited[cx][cy] = True #방문 함
				stack.append((cx,cy))

	result = 0
	for i in range(N):
		for j in range(M):
			if dual[i][j] == 0:
				result += 1

	return result

res = 0

def dfs(i,cnt):
	global maps, res

	if cnt == 3: #벽을 3개 세웠을 경우
		counting = open_virus() #바이러스가 퍼진 상태
		res = max(res, counting)
		return

	if i == len(emptys):
		return

	#3개를 세우지 않았을 경우
	ei, ej = emptys[i]

	maps[ei][ej] = 1 #벽 세우기
	dfs(i+1, cnt+1)
	maps[ei][ej] = 0 #벽 해제

	dfs(i+1, cnt)

dfs(0,0) #현재 벽 하나도 안세움
print(res)