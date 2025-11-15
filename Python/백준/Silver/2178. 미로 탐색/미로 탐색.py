from collections import deque

N, M = map(int , input().split(" "))
arr = [list(map(int , input().strip())) for _ in range(N)]

stack = deque([(0, 0, 1)])
move = [(0,1), (1,0), (-1,0), (0,-1)]
answer = 0
visited = [[False for _ in range(M)] for _ in range(N)]
visited[0][0] = True

while (len(stack) != 0):
    x, y, cnt = stack.popleft()
    if x == N-1 and y == M-1:
        answer = cnt
        break

    for dx, dy in move:
        tx = x + dx
        ty = y + dy

        if 0 <= tx < N and 0 <= ty < M and arr[tx][ty] == 1 and not visited[tx][ty]:
            stack.append((tx, ty, cnt + 1))
            visited[tx][ty] = True

print(answer)