import sys

input = sys.stdin.readline

N = int(input())
lst = list(map(int, input().split(" ")))
dp = [float('inf') for _ in range(N+1)]
dp[0] = 0

for i in range(1, N+1):
    for j in range(N):
        dp[i] = min(dp[i], lst[j]+dp[i-j-1])

print(dp[N])