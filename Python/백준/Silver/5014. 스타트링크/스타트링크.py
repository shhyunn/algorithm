import sys
from collections import deque
input = sys.stdin.readline

F, S, G, U, D = map(int,input().strip().split(" "))
visited = [False for _ in range(F+1)]

stack = deque([(S, 0)])
find = -1

while stack:
    v, cnt = stack.popleft()
    if v == G:
        find = cnt
        break
    
    cu = v + U
    cd = v - D

    if 0 < cu <= F and not visited[cu]:
        visited[cu] = True
        stack.append((cu, cnt+1))
    
    if 0 < cd <= F and not visited[cd]:
        visited[cd] = True
        stack.append((cd, cnt+1))

if find == -1:
    print("use the stairs")
else:
    print(find)