N = int(input())
lst = list(map(int, input().split()))

dp = [0 for _ in range(N)]
#증가하는 수열에서 누적된 합이 가장 큰 걸로 업데이트
dp[0] = lst[0]

for i in range(1, N):
    max_value = 0

    for j in range(i):
        if lst[i] > lst[j] and max_value < dp[j]:
            max_value = dp[j]

    dp[i] = max_value + lst[i]

print(max(dp))
