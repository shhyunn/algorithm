import sys
sys.setrecursionlimit(10 ** 4)
input = sys.stdin.readline

N = int(input())

arr = []

# minVal = 1e9
# maxVal = -1e9  
for _ in range(N):
    temp = list(map(int, input().strip().split(" ")))
    arr.append(temp)
    # minVal = min(minVal, min(temp))
    # maxVal = max(maxVal, max(temp))

visited = [[False for _ in range(N)] for _ in range(N)]

res = 1
move = [(-1,0), (1,0), (0,1), (0,-1)]

def dfs(x,y,n):
    global visited
    for cx, cy in move:
        dx = x + cx
        dy = y + cy
        if 0 <= dx < N and 0 <= dy < N and not visited[dx][dy] and arr[dx][dy] > n:
            visited[dx][dy] = True
            dfs(dx, dy, n)

for num in range(1, 101):
    temp_res = 0
    for i in range(N):
        for j in range(N):
            if not visited[i][j] and arr[i][j] > num:
                visited[i][j] = True
                temp_res += 1
                dfs(i,j,num)

    visited = [[False for _ in range(N)] for _ in range(N)]
    res = max(res, temp_res)

print(res)