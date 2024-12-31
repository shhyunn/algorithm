import sys
from collections import deque

input = sys.stdin.readline
N, M, K = map(int, input().strip().split(" "))

arr = [[0 for _ in range(M)] for _ in range(N)]

for _ in range(K):
    r, c = map(int, input().strip().split(" "))
    arr[r-1][c-1] = 1

stack = deque([(0,0)])
move = [(1,0),(-1,0),(0,1),(0,-1)]

def bfs(x,y):
    global arr
    cnt = 0
    stack = deque([(x,y)])
    while stack:
        cx, cy = stack.popleft()
        cnt += 1
        for dx, dy in move:
            rx = cx + dx
            ry = cy + dy

            if 0 <= rx < N and 0 <= ry < M and arr[rx][ry] == 1:
                arr[rx][ry] = -1
                stack.append((rx, ry))
    return cnt

res = []
for i in range(N):
    for j in range(M):
        if arr[i][j] == 0 or arr[i][j] == -1:
            arr[i][j] = -1
            continue
        if arr[i][j] == 1:
            arr[i][j] = -1
            temp = bfs(i,j)
            res.append(temp)

print(max(res))