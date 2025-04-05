N = int(input())
board = []

for _ in range(N):
	tmp = list(map(int, input().split()))
	board.append(tmp)


def cal_maxValue():
	tmp = 0
	for i in range(N):
		for j in range(N):
			if board[i][j] > tmp:
				tmp = board[i][j]

	return tmp

res = 0

def non_zero(dic):
	global board

	if dic == 0: #남쪽으로 이동
		for j in range(N):
			seq = N-1
			for i in reversed(range(N)): #N-1부터 역순으로
				if board[i][j] == 0:
					continue
				else:
					tmp = board[i][j]
					board[i][j] = 0
					board[seq][j] = tmp
					seq -= 1

	elif dic == 1: #북쪽으로 이동
		for j in range(N):
			seq = 0
			for i in range(N):
				if board[i][j] == 0:
					continue
				else: #0이 아닐 경우
					tmp = board[i][j]
					board[i][j] = 0
					board[seq][j] = tmp
					seq += 1

	elif dic == 2:#동쪽
		for i in range(N):
			seq = N-1
			for j in reversed(range(N)):
				if board[i][j] == 0:
					continue
				else:
					tmp = board[i][j]
					board[i][j] = 0
					board[i][seq] = tmp
					seq -= 1
 
	elif dic == 3: #서쪽
		for i in range(N):
			seq = 0
			for j in range(N):
				if board[i][j] == 0:
					continue
				else:
					tmp = board[i][j]
					board[i][j] = 0
					board[i][seq] = tmp
					seq += 1

def moving(dic):
	global board
	non_zero(dic) #0 공간 없도록 조정
	if dic == 0: #남쪽
		for j in range(N):
			for i in reversed(range(1, N)): #N-1부터 1까지
				if board[i][j] == board[i-1][j]:
					board[i][j] = board[i][j] * 2
					start = i-1
					while start > 0:
						board[start][j] = board[start-1][j]
						start -= 1
					board[start][j] = 0

	elif dic == 1: #북쪽
		for j in range(N): #열마다 진행
			for i in range(N-1): #행마다 진행
				if board[i][j] == board[i+1][j]:
					board[i][j] = board[i][j] * 2
					start = i+1
					while start < N-1:
						board[start][j] = board[start+1][j]
						start += 1
					board[start][j] = 0 

	elif dic == 2: #동쪽
		for i in range(N):
			for j in reversed(range(1,N)):
				if board[i][j] == board[i][j-1]:
					board[i][j] = board[i][j] * 2
					start = j-1
					while start > 0:
						board[i][start] = board[i][start-1]
						start -= 1
					board[i][start] = 0


	elif dic == 3: #서쪽
		for i in range(N):
			for j in range(N-1):
				if board[i][j] == board[i][j+1]:
					board[i][j] = board[i][j] *2
					start = j + 1
					while start < N-1:
						board[i][start] = board[i][start+1]
						start += 1
					board[i][start] = 0


def bfs(cnt):
	global board, res
	init_board = [row[:] for row in board]

	if cnt == 5: #5번 이동 후
		maxValue = cal_maxValue()
		res = max(maxValue, res)
		return

	for i in range(4): #방향 4가지 동안 하기
		moving(i) #moving 후 다음 단계로 이동
		bfs(cnt+1)
		board = [row[:] for row in init_board]

bfs(0)
print(res)