N, M, x, y, K = map(int, input().split())

maps = []
dice_x, dice_y = x,y

for i in range(N):
	tmp = list(map(int, input().split()))
	# for j,t in enumerate(tmp):
	# 	if t == 0:
	# 		dice_x, dice_y = i,j

	maps.append(tmp)

sr = list(map(int, input().split())) #명령어 순서
dices = [[0 for _ in range(3)] for _ in range(4)]
move = [(0,1), (0,-1), (-1,0), (1,0)]

def roll(s):
	global dices
	if s == 1: #동
		tmp = dices[1][2]
		dices[1][2] = dices[1][1]
		dices[1][1] = dices[1][0]
		dices[1][0] = dices[3][1]
		dices[3][1] = tmp

	elif s == 2: #서
		tmp = dices[1][0]
		dices[1][0] = dices[1][1]
		dices[1][1] = dices[1][2]
		dices[1][2] = dices[3][1]
		dices[3][1] = tmp

	elif s == 3: #북
		tmp = dices[0][1]
		dices[0][1] = dices[1][1]
		dices[1][1] = dices[2][1]
		dices[2][1] = dices[3][1]
		dices[3][1] = tmp

	else: #남
		tmp = dices[3][1]
		dices[3][1] = dices[2][1]
		dices[2][1] = dices[1][1]
		dices[1][1] = dices[0][1]
		dices[0][1] = tmp


for s in sr: #명령어 실행
	#주사위 위치 
	cx = dice_x + move[s-1][0]
	cy = dice_y + move[s-1][1]
	#위치 이동

	if not (0<= cx < N and 0 <= cy < M):
		continue

	roll(s)#주사위 굴리기
	if maps[cx][cy] == 0: #주사위 굴려진 이동한 면이 0일 경
		maps[cx][cy] = dices[3][1] #바닥면 복사
	else: #주사위 굴려진 면이 0이 아닐 경우
		dices[3][1] = maps[cx][cy]
		maps[cx][cy] = 0

	print(dices[1][1]) #윗면 출력
	dice_x = cx
	dice_y = cy