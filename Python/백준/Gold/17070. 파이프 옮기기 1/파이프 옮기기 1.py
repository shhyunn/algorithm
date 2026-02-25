import sys
input = sys.stdin.readline
N = int(input())
arr = []
for _ in range(N):
    temp = list(map(int, input().split()))
    arr.append(temp)
    #1,1괴 1,2는 항상 빈칸 (파이프 현재 위치)
    #n,n으로 이동시키는 방법의 개수

dp = [[[0 for _ in range(3)] for _ in range(N)] for _ in range(N)]
dp[0][1][0] = 1
for i in range(N):
    for j in range(N):
        if i == 0 and j <= 1:
            continue
        if arr[i][j] == 0:
            if j-1 >= 0:
                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1]

            if i-1 >= 0 and j-1 >= 0 and arr[i-1][j] == 0 and arr[i][j-1] == 0:
                dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]
            if i-1 >= 0:
                dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2]

print(sum(dp[N-1][N-1]))
