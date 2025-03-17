import sys

input = sys.stdin.readline

INF = int(1e12)
MAX = 10001
N, M = map(int , input().split())
weights = [0] + list(map(int ,input().split()))
values = [0] + list(map(int, input().split()))

dp = [[0 for _ in range(MAX)] for _ in range(N+1)]

for i in range(1, N+1):
	for j in range(MAX):
		dp[i][j] = dp[i-1][j]
		if j - values[i] >= 0:
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-values[i]] + weights[i])

ans = INF 

for i in range(MAX):
	if dp[N][i] >= M:
		ans = min(ans, i)
		break

print(ans)
