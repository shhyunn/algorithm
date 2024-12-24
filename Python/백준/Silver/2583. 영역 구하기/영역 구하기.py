import sys
from collections import deque

input = sys.stdin.readline

M, N, K = map(int, input().strip().split(" "))
arr = [[0 for _ in range(N)] for _ in range(M)]

for _ in range(K):
    lx, ly, rx, ry = map(int, input().strip().split(" "))
    for i in range(ly, ry):
        for j in range(lx, rx):
            arr[i][j] = 1

move = [(-1,0),(1,0),(0,1),(0,-1)]

def bfs(x,y):
    global arr
    stack = deque([(x,y)])
    arr[x][y] = 1
    cnt = 0
    while stack:
        x,y =stack.popleft()
        cnt += 1
        for cx, cy in move:
            dx = x + cx
            dy = y + cy

            if 0 <= dx < M and 0 <= dy < N and arr[dx][dy] == 0:
                stack.append((dx, dy))
                arr[dx][dy] = 1
    return cnt

res = []

for i in range(M):
    for j in range(N):
        if arr[i][j] == 1:
            continue
        temp = bfs(i,j)
        res.append(temp)

res.sort()
print(len(res))
print(*res)

