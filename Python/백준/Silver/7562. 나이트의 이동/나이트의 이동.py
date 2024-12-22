import sys
from collections import deque

input = sys.stdin.readline

T = int(input())
move = [(2,1), (1,2), (-2,1), (-1,2), (-2,-1), (-1,-2), (2,-1), (1,-2)]

for _ in range(T):
    l = int(input())
    cx, cy = map(int, input().strip().split(" "))
    nx, ny = map(int, input().strip().split(" "))
    visited = [[False for _ in range(l)] for _ in range(l)]
    visited[cx][cy] = True

    stack = deque([(cx, cy, 0)])
    res = 0
    while stack:
        x,y,cnt= stack.popleft()

        if x == nx and y == ny:
            res = cnt
            break

        for m in move:
            dx = x + m[0]
            dy = y + m[1]

            if 0 <= dx < l and 0 <= dy < l and not visited[dx][dy]:
                visited[dx][dy] = True
                stack.append((dx, dy, cnt + 1))
    print(res)