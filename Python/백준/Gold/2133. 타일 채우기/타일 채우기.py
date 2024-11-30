import sys

input = sys.stdin.readline

N = int(input())

# dp 배열 초기화
dp = [0 for _ in range(N+1)]
dp[0] = 1

if N >= 2:
    dp[2] = 3

if N % 2 == 0:  # N이 짝수일 경우에만 계산
    for i in range(4, N+1, 2):
        dp[i] = dp[i-2] * 3
        for j in range(i-4, -1, -2):  # j가 음수가 되지 않도록 조건 확인
            dp[i] += dp[j] * 2

print(dp[N])