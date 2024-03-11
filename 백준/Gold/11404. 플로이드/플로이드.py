import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
inf = 1e9
floyd = [ [inf for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int, input().split())
    floyd[a][b] = min(floyd[a][b], c)

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i == j:
                continue

            floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])

#출력
for i in range(1,n+1):
    for j in range(1,n+1):
        if floyd[i][j] == inf:
            print(0, end=" ")
        else:
            print(floyd[i][j], end=" ")
    print("")