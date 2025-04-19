import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
M = int(input())

dp = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    dp[i][i] = 1

for i in range(N-1):
    if arr[i] == arr[i+1]:
        dp[i][i+1] = 1
    else:
        dp[i][i+1] = 0

for cnt in range(N-2):
    for i in range(N-cnt-2):
        j = i + 2 + cnt
        if arr[i] == arr[j] and dp[i+1][j-1] == 1:
            dp[i][j] = 1

for _ in range(M):
    s, e = map(int, input().split())
    print(dp[s-1][e-1])