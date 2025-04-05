from collections import deque
N, M = map(int, input().split())
arr = []
rx, ry, bx, by = -1, -1, -1, -1

for i in range(N):
	tmp = list(input())
	for j, t in enumerate(tmp):
		if t == "R":
			rx, ry = i, j
		elif t == "B":
			bx, by = i, j
	arr.append(tmp)

stack = deque([(rx, ry, bx, by, 1)])
move = [(1,0), (-1,0), (0,1), (0,-1)]
visited = set()
visited.add((rx, ry, bx, by))

def moving(x, y, direction):
	global arr, move

	cnt = 0
	dx, dy = move[direction]


	while arr[x][y] != "O" and arr[x+dx][y+dy] != "#":
		x += dx
		y += dy
		cnt += 1

	return x, y, cnt

while stack:
	rx, ry, bx, by, cnt = stack.popleft()

	if cnt > 10:
		break

	for i in range(4):
		_rx, _ry, r_cnt= moving(rx, ry, i)
		_bx, _by, b_cnt = moving(bx, by, i)

		if arr[_bx][_by] == "O":
			continue

		if arr[_rx][_ry] == "O":
			print(cnt)
			exit(0)

		if _rx == _bx and _ry == _by:
			if r_cnt > b_cnt:
				_rx -= move[i][0]
				_ry -= move[i][1]

			else:
				_bx -= move[i][0]
				_by -= move[i][1]

		if (_rx, _ry, _bx, _by) not in visited:
			visited.add((_rx, _ry, _bx, _by))
			stack.append((_rx, _ry, _bx, _by, cnt + 1))

print(-1)