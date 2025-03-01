import sys
input = sys.stdin.readline

N, K = map(int, input().strip().split())

arr = []
for i in range(N):
    w,v = map(int, input().strip().split())
    arr.append((w,v))
    
arr.sort()
dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(1,N+1):
    cw = arr[i-1][0]
    cv = arr[i-1][1]
    
    for j in range(K+1):
        if cw > j:
            dp[i][j] = dp[i-1][j]
            continue

        dp[i][j] = max(dp[i-1][j], dp[i-1][j-cw] + cv)

print(dp[N][K])
