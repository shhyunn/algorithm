import sys
input = sys.stdin.readline

R, C, K = map(int, input().strip().split(" "))
arr = []
for _ in range(R):
    temp = list(input().strip())
    arr.append(temp)

move = [(-1,0), (1,0), (0,1), (0,-1)]
visited = [[0 for _ in range(C)] for _ in range(R)]
visited[R-1][0] = 1
cnt = 0

def bfs(x,y,temp):
    global cnt, visited

    if x == 0 and y == C-1 and temp == K:
        cnt += 1
        return
    
    for cx, cy in move:
        dx = x + cx
        dy = y + cy

        if 0 <= dx < R and 0 <= dy < C and arr[dx][dy] != "T" and not visited[dx][dy]:
            visited[dx][dy] = 1
            bfs(dx, dy, temp +1)
            visited[dx][dy] = 0

bfs(R-1, 0, 1)

print(cnt)