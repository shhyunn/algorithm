from collections import deque

N = int(input())
K = int(input())

directions = deque([])
maps = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(K):
	x, y = map(int, input().split())
	maps[x-1][y-1] = 1 #사과 있음

L = int(input())
for _ in range(L):
	x, c = input().split()
	directions.append((int(x), c))


snake = deque([(0,0)])
#오른쪽으로 이동

x,y = 0,0
cnt = 0
move = [(0,1), (1,0), (0,-1), (-1,0)]
move_index = 0

while True:
	#일단 오른쪽으로 이동
	dx, dy = move[move_index]
	cnt += 1

	cx = x + dx
	cy = y + dy

	if not (0 <= cx < N and 0 <= cy < N):
		#벽 초과할 경우
		break

	if (cx, cy) in snake: #뱀이 자기 자신 몸과 부딪혔을 경우
		break

	if maps[cx][cy] == 1: #사과일 경우
		snake.append((cx, cy))
		maps[cx][cy] = 0
		x = cx
		y = cy

	else: #사과가 아닐 경우
		snake.popleft() #꼬리 이동
		snake.append((cx,cy))
		x = cx
		y = cy

	if directions and cnt == directions[0][0]: #n초가 끝난 후의 상황일 경우
		_, c = directions.popleft()

		if c == "L": #왼쪽으로 회전일 경우
			move_index = ( move_index - 1 + 4) % 4

		else: #오른쪽으로 회전할 경우
			move_index = ( move_index + 1 + 4) % 4

print(cnt)