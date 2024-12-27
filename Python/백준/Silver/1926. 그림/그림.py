import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().strip().split(" "))
arr = []

for _ in range(n):
    arr.append(list(map(int, input().strip().split(" "))))


stack = deque([])
res = [0]
cnt = 0
move_x = [-1,1,0,0]
move_y = [0,0,-1,1]

def bfs(i,j):
    global arr
    stack = deque([(i,j)])
    square = 0

    while stack:
        x,y = stack.popleft()
        square += 1

        for i in range(4):
            cx = x + move_x[i]
            cy = y + move_y[i]
            if 0 <= cx < n and 0 <= cy < m and arr[cx][cy] == 1:
                arr[cx][cy] = -1
                stack.append((cx, cy))

    return square


for i in range(n):
    for j in range(m):
        if arr[i][j] == -1:
            continue

        if arr[i][j] == 0:
            arr[i][j] = -1
            continue
        
        arr[i][j] = -1
        temp = bfs(i,j)
        cnt += 1
        res.append(temp)

print(cnt)
print(max(res))
