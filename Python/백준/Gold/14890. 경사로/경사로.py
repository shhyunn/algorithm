N, L = map(int, input().split())
maps = []

for _ in range(N):
	tmp = list(map(int, input().split()))
	maps.append(tmp)

visited = [[[False, False] for _ in range(N)] for _ in range(N)]

res = 0

for i in range(N):
	correct = True
	for j in range(1,N):
		if maps[i][j-1] == maps[i][j]: #이전 높이와 동일한 경우
			continue #통과

		#동일하지 않을 경우
		if maps[i][j-1] < maps[i][j]: #이전 값이 작을 경우
			if j < L: #경사로를 둘 수 없음
				correct = False
				break

			if maps[i][j] - maps[i][j-1] != 1:
				correct = False
				break

			for k in range(j-L, j): #경사로를 둘 위치
				if visited[i][k][0] or maps[i][k] != maps[i][j-1]: #이미 경사로를 둔 길이거나 경사로를 둘 길이 평평하지 않다면
					correct = False
					break

				visited[i][k][0] = True #경사로 배치

		elif maps[i][j-1] > maps[i][j]: #이전 값이 클 경우
			if j+L-1 >= N: #경사로를 둘 수 없음
				correct = False
				break

			if maps[i][j-1] - maps[i][j] != 1: #1차이가 아닌 경우
				correct = False
				break

			for k in range(j, j+L): #경사로를 둘 위치
				if visited[i][k][0] or maps[i][k] != maps[i][j]:
					correct = False
					break
				visited[i][k][0] = True

	if correct:
		res += 1

for j in range(N):
	correct = True
	for i in range(1,N):
		if maps[i-1][j] == maps[i][j]:
			continue

		if maps[i-1][j] < maps[i][j]: #이전 값이 작을 경우
			if i < L:
				correct = False
				break

			if maps[i][j] - maps[i-1][j] != 1:
				correct = False
				break

			for k in range(i-L, i):
				if visited[k][j][1] or maps[k][j] != maps[i-1][j]:
					correct = False
					break

				visited[k][j][1] = True
		elif maps[i-1][j] > maps[i][j]:
			if i+L-1 >= N:
				correct = False
				break

			if maps[i-1][j] - maps[i][j] != 1:
				correct = False
				break

			for k in range(i, i+L):
				if visited[k][j][1] or maps[k][j] != maps[i][j]:
					correct = False
					break
				visited[k][j][1] = True

	if correct:
		res += 1

print(res)