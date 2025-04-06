from collections import deque

N, M = map(int, input().split())
maps = []
cctv = []

for i in range(N):
	tmp = list(map(int, input().split()))
	for j,t in enumerate(tmp):
		if 1 <= t <= 5:
			cctv.append((i,j))

	maps.append(tmp)

len_cctv = len(cctv)
direction = [-1] * len_cctv

res = 1e9
move = [(-1,0), (1,0),(0,1), (0,-1)] #북쪽, 남쪽, 동쪽, 서쪽

def proceed(x,y,dic): #중심 좌표와 방향
	global maps 

	dx, dy = move[dic]

	cx = x + dx
	cy = y + dy

	while 0 <= cx < N and 0 <= cy < M and maps[cx][cy] != 6:
		if 1 <= maps[cx][cy] <= 5: #cctv는 통과
			cx += dx
			cy += dy

		elif maps[cx][cy] == 0: #빈칸일경우
			maps[cx][cy] = 1 #그냥 아무값 설정, 빈칸만 아니면 됨 
			cx += dx
			cy += dy


def update_cctv():
	global direction, maps 
	#cctv 상태에 따라 업데이트
	for c in range(len_cctv): #cctv 개수만큼 반복
		cctv_x, cctv_y = cctv[c] #cctv 좌표

		if maps[cctv_x][cctv_y] == 1:
			#방향에 따라 한 방향으로만 이동 하면 됨
			proceed(cctv_x, cctv_y, direction[c]) #현재 cctv의 방향으로만 처리하면 됨

		elif maps[cctv_x][cctv_y] == 2:
			if direction[c] == 0: #북쪽 남쪽,
				proceed(cctv_x, cctv_y, 0)
				proceed(cctv_x, cctv_y, 1)

			else: #direction이 1일 경우, 서쪽, 동쪽
				proceed(cctv_x, cctv_y, 2)
				proceed(cctv_x, cctv_y, 3)

		elif maps[cctv_x][cctv_y] == 3:
			if direction[c] == 0:
				proceed(cctv_x, cctv_y, 0)
				proceed(cctv_x, cctv_y, 2)

			elif direction[c] == 1:
				proceed(cctv_x, cctv_y, 1)
				proceed(cctv_x, cctv_y, 2)

			elif direction[c] == 2:
				proceed(cctv_x, cctv_y, 1)
				proceed(cctv_x, cctv_y, 3)

			else:
				proceed(cctv_x, cctv_y, 0)
				proceed(cctv_x, cctv_y, 3)

		elif maps[cctv_x][cctv_y] == 4:
			if direction[c] == 0:
				proceed(cctv_x, cctv_y, 0)
				proceed(cctv_x, cctv_y, 1)
				proceed(cctv_x, cctv_y, 2)

			elif direction[c] == 1:
				proceed(cctv_x, cctv_y, 0)
				proceed(cctv_x, cctv_y, 1)
				proceed(cctv_x, cctv_y, 3)

			elif direction[c] == 2:
				proceed(cctv_x, cctv_y, 0)
				proceed(cctv_x, cctv_y, 2)
				proceed(cctv_x, cctv_y, 3)

			else:
				proceed(cctv_x, cctv_y, 1)
				proceed(cctv_x, cctv_y, 2)
				proceed(cctv_x, cctv_y, 3)

		else: #전체 방향
			proceed(cctv_x, cctv_y, 0)
			proceed(cctv_x, cctv_y, 1)
			proceed(cctv_x, cctv_y, 2)
			proceed(cctv_x, cctv_y, 3)


def count_green(): #cctv 처리하고, 사각지대 개수 세고, 복구 
	global maps
	init_maps = [row[:] for row in maps] #초기 상태 저장
	cnt = 0

	update_cctv()
	for i in range(N):
		for j in range(M):
			if maps[i][j] == 0:
				cnt += 1

	maps = [row[:] for row in init_maps] #다시 초기화

	return cnt



def dfs(cnt):
	global res, direction
	if cnt == len_cctv: #cctv 개수 모두 고려하여 처리했다면
		tm = count_green()
		res = min(tm, res) #사각지대 최솟값으로 설정
		return

	cctv_x, cctv_y = cctv[cnt]

	if maps[cctv_x][cctv_y] == 1: #1번 cctv라면
		for i in range(4):
			direction[cnt] = i #방향 저장
			dfs(cnt+1)
			direction[cnt] = -1 # 방향 초기황

	elif maps[cctv_x][cctv_y] == 2:
		for i in range(2):
			direction[cnt] = i
			dfs(cnt+1)
			direction[cnt] = -1

	elif maps[cctv_x][cctv_y] == 3:
		for i in range(4):
			direction[cnt] = i 
			dfs(cnt+1)
			direction[cnt] = -1

	elif maps[cctv_x][cctv_y] == 4:
		for i in range(4):
			direction[cnt] = i 
			dfs(cnt+1)
			direction[cnt] = -1

	else:
		direction[cnt] = 0
		dfs(cnt+1)
		direction[cnt] = -1

dfs(0) #cctv 개수
print(res)