import sys
input = sys.stdin.readline

N = int(input())

arr = []

for _ in range(N):
    arr.append(list(map(int, input().strip().split(" "))))

dp = [[0 for _ in range(N)] for _ in range(N)]

dp[0][0] = 1

for i in range(N):
    for j in range(N):
        v = arr[i][j]
        if v == 0:
             continue

        if 0 <= i + v< N and dp[i][j] > 0:
            dp[i+v][j] += dp[i][j]
          
        if 0 <= j + v < N and dp[i][j] > 0:
            dp[i][j+v] += dp[i][j]

print(dp[N-1][N-1])