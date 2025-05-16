import sys
from collections import deque

input = sys.stdin.readline

N, L, R = map(int, input().split())
maps = []

for _ in range(N):
    tmp = list(map(int, input().split()))
    maps.append(tmp)

find = True 
cnt = 0
move = [(-1,0), (1,0), (0,1), (0,-1)]

def bfs(i,j):
    global visited, maps

    visited[i][j] = True
    sums = maps[i][j]
    lst = [(i,j)]
    stack = deque([(i,j)])

    while stack:
        x,y = stack.popleft()

        for dx, dy in move:
            cx = x + dx 
            cy = y + dy

            if 0 <= cx < N and 0 <= cy < N and not visited[cx][cy] and (L <= abs(maps[x][y] - maps[cx][cy]) <=R):
                sums += maps[cx][cy]
                lst.append((cx, cy))
                visited[cx][cy] = True 
                stack.append((cx, cy))

    if len(lst) == 1:
        return False 


    avg = int(sums / len(lst))
    for x,y in lst:
        maps[x][y] = avg 

    return True


while find:
    visited = [[False for _ in range(N)] for _ in range(N)]
    find = False
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                res = bfs(i,j)

                if res:
                    find = True

    if find:
        cnt += 1
    else:
        break

print(cnt)