import sys

input = sys.stdin.readline

arr = []

for _ in range(9):
	temp = list(map(int, input().split()))
	arr.append(temp)

pos = []
row = [[False for _ in range(10)] for _ in range(9)]
col = [[False for _ in range(10)] for _ in range(9)]
square = [[[False for _ in range(10)] for _ in range(3)] for _ in range(3)]

def search(lev):
	global arr, pos, row, col, square
	if lev == len(pos):
		for i in range(9):
			for j in range(9):
				print(arr[i][j], end=" ")
			print()
		exit(0)

	x, y = pos[lev]
	for n in range(1,10):
		if not row[x][n] and not col[y][n] and not square[x//3][y//3][n]:
			row[x][n] = col[y][n] = square[x//3][y//3][n] = True
			arr[x][y] = n
			search(lev+1)
			arr[x][y] = 0
			row[x][n] = col[y][n] = square[x//3][y//3][n] = False

for i in range(9):
	for j in range(9):
		cur = arr[i][j]
		if cur == 0:
			pos.append((i,j))
		else:
			row[i][cur] = col[j][cur] = square[i//3][j//3][cur] = True

search(0)
