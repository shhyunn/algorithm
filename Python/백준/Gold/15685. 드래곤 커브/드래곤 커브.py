N = int(input())
move = [(1,0), (0,-1), (-1,0), (0,1)]
visited = [[False for _ in range(101)] for _ in range(101)]

for _ in range(N):
    x,y,d,g = map(int, input().split()) #d는 시작 방향, g는 세대

    k = ""
    k += str(d)
    len_k = 1
    cg = 0 #몇세대인지

    cx, cy = x + move[d][0], y + move[d][1]
    visited[x][y] = True
    visited[cx][cy] = True
    while cg != g: #g세대가 되기 전까지
        tmp = ""
        for i in reversed(range(len_k)):
            dg = (int(k[i]) + 1) % 4 #반시계 방향 회전
            
            cx += move[dg][0]
            cy += move[dg][1]

            visited[cx][cy] = True
            k += str(dg)
        cg += 1
        len_k += 2 ** (cg-1)

res = 0

for i in range(100):
    for j in range(100):
        if visited[i][j] and visited[i][j+1] and visited[i+1][j] and visited[i+1][j+1]:
            res += 1

print(res)