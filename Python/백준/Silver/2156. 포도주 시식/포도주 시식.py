import sys
input = sys.stdin.readline

n = int(input())
arr = []
dp = [[0 for _ in range(n+2)] for _ in range(2)]

for _ in range(n):
    arr.append(int(input()))

for i in range(2, n+2):
    dp[0][i] = max(dp[0][i-2], dp[1][i-2]) + arr[i-2]
    dp[1][i] = max(dp[0][i-1] + arr[i-2], dp[1][i-1])

print(max(dp[0][n+1], dp[1][n+1]))