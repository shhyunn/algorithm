#n: 세로선, m: 가로선, h: 놓을 수 있는 가로선 개수
N, M, H = map(int, input().split())

graph = [[0 for _ in range(H)] for _ in range(N)] #세로선 별 가로선 연결 유무, 처음엔 0 초기화

for _ in range(M): #현재 설치되어 있는 가로
	a, b = map(int, input().split())
	graph[b-1][a-1] = 1 #오른쪽에 가로선 배치

def transform(x,y):
	if y == H-1: #마지막 가로선이라면
		if x == N-2:
			return -1,-1
		else:
			return x+1, 0
	else:
		return x, y+1

def can_install(x,y):
	global graph
	if x == 0:
		return not graph[x+1][y]
	if x == N-2:
		return not graph[x-1][y]

	return not graph[x-1][y] and not graph[x+1][y] 

def check():
	#그래프 탈출 되는지 확인
	global graph
	correct = True

	for i in range(N): #세로선마다 확인, 0번 세로선인 경우, 0번만 확인하고, 마지막 세로선인 경우, 이전 세로선에 연결된 가로선들만 확인
		curr_x = i #현재 세로선
		curr_y = 0
		while curr_y < H: # 가로선 개수만큼만 확인
			move = False

			if curr_x == 0: #가장 왼쪽 세로선인 경우
				for j in range(curr_y, H): #가로선마다 모두 확인
					if graph[curr_x][j] == 1: #가로선이 설치되어 있다면,
						curr_x = curr_x + 1 #세로선 이동_
						curr_y = j+1
						move = True
						break
				if not move:
					curr_y = H # 움직이지 않았다면 그대로 while 문 종료

			elif curr_x == N-1: #마지막 세로선일 경우
				for j in range(curr_y, H):
					if graph[curr_x-1][j] == 1:
						curr_x = curr_x - 1
						curr_y = j + 1
						move = True
						break

				if not move:
					curr_y = H

			else: # 그 사이의 사다리일 경우
				for j in range(curr_y, H):
					if graph[curr_x - 1][j] == 1: # 왼쪽으로 이동 가능할 경우
						curr_x = curr_x - 1
						curr_y = j + 1
						move = True
						break

					if graph[curr_x][j] == 1:
						curr_x = curr_x + 1
						curr_y = j + 1
						move= True
						break
				if not move:
					curr_y = H


		if curr_x != i:
			return False

	return correct

res = 1e9	
def dfs(x,y,cnt):
	global graph, res

	if cnt <= 3:
		checked = check() #그래프 탈출이 제대로 잘 되는지 확인 
		if checked:
			res = min(res, cnt)

	if cnt == 3:
		return #3개를 설치한 경우는 중단

	if x == -1 and y == -1:
		return

	if graph[x][y] == 1: #이미 설치가 되어 있다면, x가 세로선, y가 가로
		cx, cy = transform(x,y) #현재 상태에서 dfs 호출
		dfs(cx, cy, cnt) #가로선 설치 안함

	else: #현재 설치가 안되어 있다면
		cx, cy = transform(x, y)

		if can_install(x,y):
			graph[x][y] = 1 #가로선 설치
			
			dfs(cx, cy, cnt+1) #가로선 설치 후 dfs 실행

			graph[x][y] = 0

		dfs(cx, cy, cnt) #가로선 설치 안하고 호출

dfs(0,0,0)

if res == 1e9:
	print(-1)
else:
	print(res)