import sys
input = sys.stdin.readline

#이진수는 0으로 시작하지 않음. 1이 두번 연속으로 나타나지 않
#이친수 개수 출력

N = int(input())

dp = [[0,0] for _ in range(N)]

dp[0][0] = 0
dp[0][1] = 1

for i in range(1,N):
    dp[i][0] = dp[i-1][0] + dp[i-1][1]
    dp[i][1] = dp[i-1][0]

print(sum(dp[N-1]))
